/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:22:53 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 18:13:32 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

t_player init_player(t_location location, t_list *collectibles)
{
	t_player player;

	player.location = location;
	player.collectibles = collectibles;
	return (player);
}


int	on_player_move(int keycode, t_world *world)
{
	//w = 119
	//s = 115
	//a = 97
	//d = 100
	printf("\nPRINT: %d", keycode);

	if(!can_move(keycode, world))
		return -1;

	if(keycode == 119)
		world->player->location.x += 1;
	else if(keycode == 115)
		world->player->location.x -= 1;
	else if(keycode == 97)
		world->player->location.y -= 1;
	else if(keycode == 100)
		world->player->location.y += 1;

	printf("\nPRINT2: %d", keycode);
	return 0;
}



t_boolean can_move(int code, t_world *world)
{
	char **map;
	char c;
	int y;
	int x;

	c = ' ';
	map = world->map;
	y = world->player->location.y;
	x = world->player->location.x;
	if(code == 119 && map[y + 1])
		c = map[y + 1][x];
	else if(code == 115 && map[y - 1])
		c = map[y - 1][x];
	else if(code == 97 && map[y][x - 1])
		c = map[y][x - 1];
	else if(code == 100 && map[y][x + 1])
		c = map[y][x + 1];

	return (is_solid(c, world->player));
}

t_boolean is_solid(char c, t_player	*player)
{
	t_player copy;
	copy = *player;
	t_collectible collectible;
	if(!c)
		return _false;
	while (copy.collectibles && copy.collectibles->next)
	{

		collectible = *((t_collectible *) &copy.collectibles->content);
		if(c == 'E' && !collectible.collected)
			return (_false);
		copy.collectibles = copy.collectibles->next;
	}

	if(c != '1')
		return (_false);
	return _true;
}
