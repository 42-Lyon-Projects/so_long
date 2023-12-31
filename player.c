/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:22:53 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/13 17:30:36 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	init_player(t_location location, t_collectible *collectibles)
{
	t_player	player;

	location.x--;
	location.y--;
	player.location.x = location.x;
	player.location.y = location.y;
	player.collectibles = collectibles;
	player.movements = 0;
	return (player);
}

void	update_graphics(t_game *game)
{
	t_location	location;
	void		*texture;

	location = game->world.player.location;
	texture = game->textures.player.texture;
	game->world.player.movements = game->world.player.movements + 1;
	mlx_put_image_to_window(game->mlx, game->window, texture, \
	location.x * 128, location.y * 128);
}

int	on_player_move(int keycode, t_game *game)
{
	t_collectible	*collectible;

	if (keycode == 65307)
		mlx_loop_end(game->mlx);
	if (!can_move(keycode, *game))
		return (-1);
	if (keycode != 119 && keycode != 115 && keycode != 97 && keycode != 100)
		return (-1);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.grass.texture, game->world.player.location.x * 128, \
							game->world.player.location.y * 128);
	if (keycode == 119)
		game->world.player.location.y -= 1;
	else if (keycode == 115)
		game->world.player.location.y += 1;
	else if (keycode == 97)
		game->world.player.location.x -= 1;
	else
		game->world.player.location.x += 1;
	update_graphics(game);
	collectible = get_collectible_at(game->world, game->world.player.location);
	if (collectible != NULL && !collectible->collected)
		update_col(collectible, game->world.player.location, _true);
	ft_printf("-> INFOS: \n| Movements: %d\n", game->world.player.movements);
	return (0);
}

t_boolean	can_move(int code, t_game game)
{
	char	**map;
	int		y;
	int		x;

	map = game.world.map;
	y = game.world.player.location.y;
	x = game.world.player.location.x;
	if (code == 119)
		y--;
	else if (code == 115)
		y++;
	else if (code == 97)
		x--;
	else if (code == 100)
		x++;
	if (!is_inside_world(y, x, game.world))
		return (_false);
	return (!is_solid(map[y][x], game));
}

t_boolean	is_solid(char c, t_game game)
{
	t_boolean	exit;

	exit = _true;
	if (!c)
		return (_true);
	while (game.world.player.collectibles)
	{
		if (!game.world.player.collectibles->collected)
		{
			exit = _false;
			break ;
		}
		game.world.player.collectibles = game.world.player.collectibles->next;
	}
	if (exit && c == 'E')
		mlx_loop_end(game.mlx);
	if (c == '1' || c == 'E')
		return (_true);
	return (_false);
}
