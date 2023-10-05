/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:21:10 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 15:06:29 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_world world) {
	int length_y;

	length_y = 0;
	while (world.length_y < length_y) {
		free(world.map[length_y]);
		length_y++;
	}
	free(world.map);
}

void free_collectibles(t_list **collectibles) {

	t_list *list;
	t_list *copy;

	list = *collectibles;
	copy = list;
	while (copy->next)
	{
		if(copy->next == NULL) {
			free(list->content);
			copy = list;
		}
		copy = copy->next;

	}
	free(list->content);
	free(list);
}