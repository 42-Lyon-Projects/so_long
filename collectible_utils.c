/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:24:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/12 08:57:08 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collectible *load_collectibles(t_world *world) {
	int pos_x;
	int pos_y;
	t_collectible *collectible;

	pos_x = 0;
	pos_y = 0;
	collectible = NULL;

	while (world->map[pos_y]) {
		while (world->map[pos_y] && pos_x < (int) ft_strlen(world->map[0])) {
			if (world->map[pos_y][pos_x] == 'C') {
				t_location location;
				location.x = pos_x;
				location.y = pos_y;
				if(!collectible)
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

	collectible->location = location;
	collectible->collected = 0;
	collectible->is_set = _true;
	collectible->next = NULL;
	return (collectible);
}

int count_collectibles(t_collectible collectibles, t_boolean o_uncollected, t_boolean o_collected)
{
	int count;

	count = 0;

	while (collectibles.is_set)
	{
		if(o_uncollected && !collectibles.collected)
			count++;
		if(o_collected && collectibles.collected)
			count++;
		if(collectibles.next != NULL)
			collectibles = *collectibles.next;
		else
			break;
	}
	return (count);
}


t_collectible *get_collectible_at(t_world world, t_location location)
{
	while (world.player.collectibles)
	{
		if(loc_equals(location, world.player.collectibles->location))
			return (world.player.collectibles);
		world.player.collectibles = world.player.collectibles->next;
	}
	return (NULL);
}

#include "stdio.h"
void update_collectible(t_collectible *collectibles, t_location location, t_boolean collected)
{
	while (collectibles)
	{
		if(loc_equals(collectibles->location, location)) {
			collectibles->collected = collected;
			break;
		}
		collectibles = collectibles->next;
	}
}