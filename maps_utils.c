/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:09:47 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/14 16:01:26 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <fcntl.h>

int	map_size(int fd)
{
	char	*tmp;
	int		index;

	index = 0;
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		index++;
	}
	close(fd);
	return (index);
}

t_world	*load_map(int fd, char *path, t_world *world)
{
	int		y;
	int		y_index;
	char	*s;

	y = 0;
	y_index = map_size(fd);
	world->map = malloc((y_index + 1) * sizeof(char *));
	if (!world->map)
		return (world);
	world->map[y_index] = NULL;
	fd = open(path, O_RDONLY);
	while (y <= y_index)
	{
		s = get_next_line(fd);
		if (s != NULL)
		{
			world->map[y] = ft_strtrim(s, "\n");
			free(s);
		}
		y++;
	}
	return (world->length_y = y_index, world);
}

int	valid_elements(t_world world)
{
	int	players;
	int	exits;
	int	collectibles;

	players = count_element(world, 'P');
	if (players > 1)
		return (-1);
	if (players < 1)
		return (-2);
	exits = count_element(world, 'E');
	if (exits > 1)
		return (-3);
	if (exits < 1)
		return (-4);
	collectibles = count_element(world, 'C');
	if (collectibles < 1)
		return (-5);
	return (1);
}

void	is_solvable(char **map, int x, int y, int length_y)
{
	char	character;

	if (map[y] == NULL || y > length_y)
		return ;
	character = map[y][x];
	if (character == 'O')
		return ;
	if (character == '0' || character == 'C' || character == 'P')
	{
		map[y][x] = 'O';
		is_solvable(map, x - 1, y, length_y);
		is_solvable(map, x + 1, y, length_y);
		is_solvable(map, x, y + 1, length_y);
		is_solvable(map, x, y - 1, length_y);
	}
	if (character == 'E')
	{
		map[y][x] = 'L';
		is_solvable(map, x - 1, y, length_y);
		is_solvable(map, x + 1, y, length_y);
		is_solvable(map, x, y + 1, length_y);
		is_solvable(map, x, y - 1, length_y);
	}
}

t_boolean	is_inside_world(int y, int x, t_world world)
{
	if (y < 0 || y > world.length_y)
		return (_false);
	if (x < 0 || x > (int) ft_strlen(world.map[0]))
		return (_false);
	return (_true);
}
