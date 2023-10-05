/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:09:47 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 15:22:01 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <fcntl.h>

t_world load_map(int fd, char *path)
{
	int index;
	int y;
	char *s;
	t_world world;

	index = 0;
	y = 0;
	while (get_next_line(fd) != NULL)
		index++;
	world.map = malloc((index + 1) * sizeof(char *));
	if (!world.map)
		return (world);
	world.map[index] = NULL;
	close(fd);
	fd = open(path, O_RDONLY);
	while (y <= index) {
		s = get_next_line(fd);
		if(s != NULL)
			world.map[y] = ft_strtrim(s, "\n");
		y++;

	}
	return (world.length_y = index, world);
}

t_boolean is_valid_map(t_world world)
{
	t_location start_loc;
	t_location exit_loc;
	//int collectibles;

	start_loc = find_element(world, 'P');
	exit_loc = find_element(world, 'E');
	//collectibles = ft_lstsize(world.player->collectibles);
	return (start_loc.x != -1 && exit_loc.x != -1);
}

void is_solvable(t_world world, int x, int y)
{

	char character;
	if(world.map[y] == NULL || y > world.length_y)
		return;
	character = world.map[y][x];
	if (character == 'O')
		return ;
	if (character == '0' || character == 'C' || character == 'P' || character == 'E')
	{
		world.map[y][x] = 'O';
		is_solvable(world, x - 1, y);
		is_solvable(world, x + 1, y);
		is_solvable(world, x, y + 1);
		is_solvable(world,x, y - 1);
	}
	return ;

}