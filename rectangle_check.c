/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:27:59 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 15:26:35 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_boolean is_rectangle(t_world world) {
	return (is_horizontal_rectangle(world) ||
	is_vertical_rectangle(world)) && is_closed(world);
}

t_boolean is_horizontal_rectangle(t_world world) {
	int x_length;
	int y_index;

	x_length = (int) ft_strlen(world.map[0]);
	y_index = 0;

	while (y_index < world.length_y && world.map[y_index]) {
		if ((int) ft_strlen(world.map[y_index]) != x_length)
			return (_false);
		y_index++;
	}

	if (x_length <= y_index)
		return (_false);

	return (_true);
}

t_boolean is_vertical_rectangle(t_world world) {
	int x_index;
	int y_index;

	int x_length;
	int y_length;

	x_index = 0;
	y_index = 0;

	x_length = (int) ft_strlen(world.map[0]);
	y_length = world.length_y;

	while (x_index < x_length) {
		while (x_index < x_length && y_index < y_length && world.map[y_index][x_index])
			y_index++;
		if (y_index != y_length)
			return (_false);
		y_index = 0;
		x_index++;
	}
	y_index = 0;
	while (y_index < y_length)
		if (world.map[y_index] && (int)ft_strlen(world.map[y_index++]) != x_length)
			return (_false);
	if (x_index >= y_length)
		return (_false);
	return (_true);
}


t_boolean is_closed(t_world world) {

	int x_length;
	int x_index;
	int y_index;

	x_length = (int)ft_strlen(world.map[0]);
	x_index = 0;
	y_index = 0;

	while (x_index < x_length) {
		if (world.map[0][x_index] != '1' || world.map[world.length_y - 1][x_index] != '1')
			return (_false);
		x_index++;
	}

	while (y_index < world.length_y) {
		if (world.map[y_index][0] != '1' || world.map[y_index][x_length - 1] != '1')
			return (_false);
		y_index++;
	}

	return (_true);
}
