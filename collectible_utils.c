/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:24:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 16:31:17 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list *load_collectibles(t_world world) {
	int pos_x;
	int pos_y;
	t_list **list;
	t_collectible collectible;

	pos_x = 0;
	pos_y = 0;
	list = malloc(sizeof (t_list *));
	if(!list)
		return (NULL);

	while (world.map[pos_y]) {
		while (world.map[pos_y] && pos_x < (int) ft_strlen(world.map[0])) {
			if (world.map[pos_y][pos_x] == 'C') {
				t_location location;
				location.x = ++pos_x;
				location.y = ++pos_y;
				collectible = create_collectible(location);
				ft_lstadd_front(list, ft_lstnew(&collectible));
			}
			pos_x++;
		}
		pos_x = 0;
		pos_y++;
	}
	return (*list);

}


t_collectible create_collectible(t_location location)
{
	t_collectible collectible;

	collectible.location = location;
	collectible.collected = 0;
	return (collectible);
}

int count_collectibles(t_list *collectibles, t_boolean o_uncollected, t_boolean o_collected)
{
	t_collectible *col;
	int count;

	count = 0;
	col = NULL;

	if (!collectibles)
		return (0);

	while (collectibles)
	{
		col = ((t_collectible*) collectibles->content);
		if	(col == NULL)
			continue;
		if(o_uncollected && !col->collected)
			count++;
		if(o_collected && col->collected)
			count++;
		collectibles = collectibles->next;
	}
	return (count);
}


t_collectible *get_collectible_at(t_world world, t_location location)
{
	t_list *collectibles = world.player->collectibles;
	t_collectible *collectible;

	while (collectibles)
	{
		collectible = ((t_collectible*) collectibles->content);
		if(loc_equals(location, collectible->location))
			return collectible;
		collectibles = collectibles->next;
	}
	return (NULL);
}

void update_collectible(t_list **collectibles, t_location location, t_boolean collected)
{
	t_list *collectibles_copy;
	t_collectible *collectible;

	collectibles_copy = *collectibles;
	while (collectibles_copy->next)
	{
		collectible = ((t_collectible*) collectibles_copy->content);
		if(collectible->location.x == location.x && collectible->location.y == location.y) {
			collectible->collected = collected;
			break;
		}
		collectibles_copy = collectibles_copy->next;
	}
}