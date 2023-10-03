/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:09:47 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/03 10:41:46 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <fcntl.h>

t_data load_map(char *path) {
	size_t index;
	size_t y;
	int fd;
	t_data data;

	index = 0;
	y = 0;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd) != NULL)
		index++;
	data.map = malloc((index) * sizeof(char *));
	if (!data.map)
		return (data);
	close(fd);
	fd = open(path, O_RDONLY);
	while (y != index) {
		data.map[y] = ft_strtrim(get_next_line(fd), "\n");
		y++;
	}
	return (data.lenght_y = y, data);
}

void is_solvable(t_data data, size_t x, size_t y)
{

	char character;
	if(data.map[y] == NULL || y > data.lenght_y)
		return;
	character = data.map[y][x];
	if (character == 'O')
		return ;
	if (character == '0' || character == 'C' || character == 'P' || character == 'E')
	{
		data.map[y][x] = 'O';
		is_solvable(data, x - 1, y);
		is_solvable(data, x + 1, y);
		is_solvable(data, x, y + 1);
		is_solvable(data,x, y - 1);
	}
	return ;

}