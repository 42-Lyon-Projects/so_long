/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:21:10 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/12 19:51:21 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(t_world *world) {
	int index;

	index = 0;
	while (world->map && world->map[index]) {
		free(world->map[index]);
		index++;
	}
	free((world->map));
}


void free_textures(t_game *game)
{
	t_textures *textures = &game->textures;
	if(textures->wall.is_set)
		mlx_destroy_image(game->mlx, game->textures.wall.texture);
	if(textures->player.is_set)
		mlx_destroy_image(game->mlx, game->textures.player.texture);
	if(textures->collectible.is_set)
		mlx_destroy_image(game->mlx, game->textures.collectible.texture);
	if(textures->grass.is_set)
		mlx_destroy_image(game->mlx, game->textures.grass.texture);
	if(textures->exit.is_set)
		mlx_destroy_image(game->mlx, game->textures.exit.texture);
}

void free_collectibles(t_collectible *collectible)
{
	t_collectible *copy;

	while (collectible != NULL)
	{
		copy = collectible;
		collectible = collectible->next;
		free(copy);
	}
}