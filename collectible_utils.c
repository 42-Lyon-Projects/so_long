/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:24:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/03 03:47:04 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list *load_collectibles(t_data data) {
	size_t pos_x;
	size_t pos_y;
	t_list *list;
	t_collectible *collectible;

	pos_x = 0;
	pos_y = 0;
	list = malloc(sizeof (t_list));
	if(!list)
		return (NULL);

	while (pos_y < data.lenght_y) {
		while (pos_x < ft_strlen(data.map[0])) {
			if (data.map[pos_y][pos_x] == 'C') {
				t_location location;
				location.x = ++pos_x;
				location.y = ++pos_y;
				collectible = create_collectible(location);
				if(!collectible)
					return (NULL);
				ft_lstadd_front(&list, ft_lstnew(collectible));
			}
			pos_x++;
		}
		pos_x = 0;
		pos_y++;
	}
	return (list);

}


t_collectible *create_collectible(t_location location)
{
	t_collectible *collectible;

	collectible = malloc(sizeof(t_collectible *));
	if(!collectible)
		return (NULL);
	collectible->location.x = location.x;
	collectible->location.y = location.y;
	collectible->collected = _false;
	return (collectible);
}

int count_collectibles(t_list *collectibles, t_boolean only_uncollected)
{
	t_list *collectibles_copy;
	t_collectible *col;
	int count;

	collectibles_copy = collectibles;
	count = 0;
	col = NULL;
	while (collectibles_copy->next != NULL) {
		collectibles_copy = collectibles_copy->next;

		if(only_uncollected) {
			col = ((t_collectible*) collectibles_copy->content);
			if(!col->collected)
			{
				count++;
				continue;
			}
		}
		count++;
	}
	return (count);
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