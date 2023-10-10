/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:22:53 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/10 19:59:55 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"
#include "minilibx-linux/mlx.h"

t_player *init_player(t_location *location, t_collectible *collectibles)
{
	t_player *player;

	player = malloc(sizeof (t_player));
	if(!player)
		return (NULL);

	location->x--;
	location->y--;
	player->location = location;
	player->collectibles = collectibles;
	return (player);
}


t_boolean is_inside_world(int y, int x, t_world *world)
{
	if(y < 0  || y > world->length_y)
		return (_false);
	if(x < 0  || x > (int) ft_strlen(world->map[0]))
		return (_false);
	return (_true);
}


int	on_player_move(int keycode, t_game *game)
{
	//w = 119
	//s = 115
	//a = 97
	//d = 100

	if(!can_move(keycode, game->world))
		return -1;

	mlx_put_image_to_window(game->mlx,
							game->window,
							game->textures->grass->texture,
							game->world->player->location->x * 128,
							game->world->player->location->y * 128);

	if(keycode == 119)
		game->world->player->location->y -= 1;
	else if(keycode == 115)
		game->world->player->location->y += 1;
	else if(keycode == 97)
		game->world->player->location->x -= 1;
	else if(keycode == 100)
		game->world->player->location->x += 1;
	else {
		mlx_put_image_to_window(game->mlx,
								game->window,
								game->textures->player->texture,
								game->world->player->location->x * 128,
								game->world->player->location->y * 128);
		return (-1);

	}

	printf("\n-> KEYCODE: %d", keycode);
	printf("\nPLAYER: \n -> POS Y: %d", game->world->player->location->y);
	printf("\nPLAYER: \n -> POS X: %d\n ",game->world->player->location->x);

	mlx_put_image_to_window(game->mlx,
							game->window,
							game->textures->player->texture,
							game->world->player->location->x * 128,
							game->world->player->location->y * 128);

	return 0;
}




t_boolean can_move(int code, t_world *world)
{
	char **map;
	int y;
	int x;

	map = world->map;
	y = world->player->location->y;
	x = world->player->location->x;
	if(code == 119)
		y--;
	else if(code == 115)
		y++;
	else if(code == 97)
		x--;
	else if(code == 100)
		x++;
	if(!is_inside_world(y, x, world))
		return (_false);

	return (is_solid(map[y][x], world->player));
}

t_boolean is_solid(char c, t_player	*player)
{
	t_player *copy;
	copy = player;
	if(!c)
		return (_true);
	while (copy->collectibles)
	{
		if(c == 'E' && !copy->collectibles->collected)
			return (_true);
		copy->collectibles = copy->collectibles->next;
	}

	if(c != '1')
		return (_true);
	return _false;
}
