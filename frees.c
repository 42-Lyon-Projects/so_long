/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:21:10 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/10 14:58:36 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_world *world) {
	int length_y;

	length_y = 0;
	while (world->length_y < length_y) {
		free(world->map[length_y]);
		length_y++;
	}
	free(world->map);
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

void free_textures(t_textures *textures)
{
	if(textures == NULL) return;
	if(textures->wall != NULL)
	{
		free(textures->wall->texture);
		free(textures->wall);
	}
	if(textures->player != NULL)
	{
		free(textures->player->texture);
		free(textures->player);
	}
	if(textures->collectible != NULL)
	{
		free(textures->collectible->texture);
		free(textures->collectible);
	}
	if(textures->grass != NULL)
	{
		free(textures->grass->texture);
		free(textures->grass);
	}
	free(textures);
}