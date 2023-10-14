/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:27:59 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/13 17:31:58 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_boolean	is_valid_shape(t_world world)
{
	return (has_good_shape(world) && is_closed(world));
}

t_boolean	has_illegal_character(t_world world)
{
	int		index_y;
	int		index_x;
	char	c;

	index_y = 0;
	index_x = 0;
	while (index_y < world.length_y)
	{
		while (index_x < (int) ft_strlen(world.map[index_y]))
		{
			c = world.map[index_y][index_x];
			if (c != '1' && c != '0' && c != 'E' && c != 'C' && c != 'P')
				return (_true);
			index_x++;
		}
		index_x = 0;
		index_y++;
	}
	return (_false);
}

t_boolean	has_good_shape(t_world world)
{
	int	x_length;
	int	y_index;

	if (world.map == NULL || world.map[0] == NULL)
		return (_false);
	x_length = (int) ft_strlen(world.map[0]);
	y_index = 0;
	while (y_index < world.length_y && world.map[y_index])
	{
		if ((int) ft_strlen(world.map[y_index]) != x_length)
			return (_false);
		y_index++;
	}
	if (x_length <= y_index)
		return (_false);
	return (_true);
}

t_boolean	is_closed(t_world world)
{
	int	x_length;
	int	x_index;
	int	y_index;

	x_length = (int)ft_strlen(world.map[0]);
	x_index = 0;
	y_index = 0;
	while (x_index < x_length)
	{
		if (world.map[0][x_index] != '1' || \
		world.map[world.length_y - 1][x_index] != '1')
			return (_false);
		x_index++;
	}
	while (y_index < world.length_y)
	{
		if (world.map[y_index][0] != '1' || \
		world.map[y_index][x_length - 1] != '1')
			return (_false);
		y_index++;
	}
	return (_true);
}
