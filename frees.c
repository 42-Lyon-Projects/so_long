/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:21:10 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/13 17:09:19 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_world *world)
{
	int	index;

	index = 0;
	while (world->map && world->map[index])
	{
		free(world->map[index]);
		index++;
	}
	free((world->map));
}

void	free_textures(t_game *game)
{
	t_textures	*textures;

	textures = &game->textures;
	if (textures->wall.is_set && textures->wall.texture != NULL)
		mlx_destroy_image(game->mlx, game->textures.wall.texture);
	if (textures->player.is_set && textures->player.texture != NULL)
		mlx_destroy_image(game->mlx, game->textures.player.texture);
	if (textures->collectible.is_set && textures->collectible.texture != NULL)
		mlx_destroy_image(game->mlx, game->textures.collectible.texture);
	if (textures->grass.is_set && textures->grass.texture != NULL)
		mlx_destroy_image(game->mlx, game->textures.grass.texture);
	if (textures->exit.is_set && textures->exit.texture != NULL)
		mlx_destroy_image(game->mlx, game->textures.exit.texture);
}

void	free_collectibles(t_collectible *collectible)
{
	t_collectible	*copy;

	while (collectible != NULL)
	{
		copy = collectible;
		collectible = collectible->next;
		free(copy);
	}
}

int	free_unavailable_texture(t_game game)
{
	if (has_unavailable_texture(game.textures))
	{
		ft_printf("Error\n -> Textures can't be loaded.\n");
		free_map(&game.world);
		free_textures(&game);
		free_collectibles(game.world.player.collectibles);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1);
	}
	return (0);
}

void	destroy(t_game *game)
{
	free_map(&game->world);
	free_textures(game);
	free_collectibles(game->world.player.collectibles);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}
