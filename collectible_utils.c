/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:24:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/10 19:35:28 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collectible *load_collectibles(t_world *world) {
	int pos_x;
	int pos_y;
	t_collectible *collectible;

	pos_x = 0;
	pos_y = 0;
	collectible = malloc(sizeof (t_collectible));
	if(!collectible)
		return (NULL);

	while (world->map[pos_y]) {
		while (world->map[pos_y] && pos_x < (int) ft_strlen(world->map[0])) {
			if (world->map[pos_y][pos_x] == 'C') {
				t_location location;
				location.x = ++pos_x;
				location.y = ++pos_y;
				if(!collectible->location)
					collectible = create_collectible(location);
				else
				collectible->next = create_collectible(location);
			}
			pos_x++;
		}
		pos_x = 0;
		pos_y++;
	}
	return (collectible);

}


t_collectible *create_collectible(t_location location)
{
	t_collectible *collectible;

	collectible = malloc(sizeof (t_collectible));
	if(!collectible)
		return (NULL);

	collectible->location = create_location(location.x, location.y);
	collectible->collected = 0;
	collectible->next = NULL;
	return (collectible);
}

int count_collectibles(t_collectible *collectibles, t_boolean o_uncollected, t_boolean o_collected)
{
	t_collectible *copy;
	int count;

	count = 0;
	copy = collectibles;

	if (!copy)
		return (0);

	while (copy)
	{
		if(o_uncollected && !copy->collected)
			count++;
		if(o_collected && copy->collected)
			count++;
		copy = copy->next;
	}
	return (count);
}


t_collectible *get_collectible_at(t_world *world, t_location *location)
{
	t_collectible *copy;
	copy = world->player->collectibles;
	while (copy)
	{
		if(loc_equals(location, copy->location))
			return copy;
		copy =	copy->next;
	}
	return (NULL);
}


void update_collectible(t_collectible *collectibles, t_location location, t_boolean collected)
{
	t_collectible *copy;

	copy = collectibles;
	while (copy->next)
	{
		if(copy->location->x == location.x && copy->location->y == location.y) {
			copy->collected = collected;
			break;
		}
		copy = copy->next;
	}
}