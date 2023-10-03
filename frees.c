/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:21:10 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/03 10:54:19 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_data data) {
	size_t lenght_y;

	lenght_y = 0;
	while (data.lenght_y < lenght_y) {
		free(data.map[lenght_y]);
		lenght_y++;
	}
	free(data.map);
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