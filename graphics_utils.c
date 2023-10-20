/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:56:12 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/13 16:28:17 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mlx_loop_cancel(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (1);
}

int	init_graphics_part(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->textures = load_textures(game->mlx);
	if (free_unavailable_texture(*game))
		return (-1);
	game->window = mlx_new_window(game->mlx, \
	128 * ft_strlen(game->world.map[0]), \
	128 * game->world.length_y, "Xe'Burger");
	draws(*game);
	mlx_hook(game->window, 2, (1L << 0), on_player_move, game);
	mlx_hook(game->window, 17, 0L, mlx_loop_cancel, game);
	mlx_loop(game->mlx);
	return (0);
}

void	draw_type(t_game game, t_texture texture)
{
	int	index_y;
	int	index_x;

	index_y = 0;
	index_x = 0;
	while (game.world.map[index_y])
	{
		while (index_x < (int) ft_strlen(game.world.map[index_y]))
		{
			if (game.world.map[index_y][index_x] == texture.character)
				mlx_put_image_to_window(game.mlx, game.window, \
				texture.texture, index_x * 128, index_y * 128);
			index_x++;
		}
		index_x = 0;
		index_y++;
	}
}

void	draw_collectibles(t_game game)
{
	t_location		loc;
	void			*texture;

	texture = game.textures.collectible.texture;
	while (game.world.player.collectibles)
	{
		loc = game.world.player.collectibles->location;
		mlx_put_image_to_window \
		(game.mlx, game.window, texture, loc.x * 128, loc.y * 128);
		game.world.player.collectibles = game.world.player.collectibles->next;
	}
}

void	draws(t_game game)
{
	draw_type(game, game.textures.wall);
	draw_type(game, game.textures.grass);
	draw_type(game, game.textures.player);
	draw_type(game, game.textures.exit);
	draw_collectibles(game);
}
