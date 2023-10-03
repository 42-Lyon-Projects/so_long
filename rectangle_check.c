/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 01:27:59 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/03 05:34:04 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_boolean is_rectangle(t_data data) {
	return (is_horizontal_rectangle(data) || is_vertical_rectangle(data));
}

t_boolean is_horizontal_rectangle(t_data data) {
	size_t x_lenght;
	size_t y_index;

	x_lenght = ft_strlen(data.map[0]);
	y_index = 0;

	while (y_index < data.lenght_y && data.map[y_index]) {
		if (ft_strlen(data.map[y_index]) != x_lenght)
			return (_false);
		y_index++;
	}

	if (x_lenght <= y_index)
		return (_false);

	return (_true);
}

t_boolean is_vertical_rectangle(t_data data) {
	size_t x_index;
	size_t y_index;

	size_t x_lenght;
	size_t y_lenght;

	x_index = 0;
	y_index = 0;

	x_lenght = ft_strlen(data.map[0]);
	y_lenght = data.lenght_y;

	while (x_index < x_lenght) {
		while (x_index < x_lenght && y_index < y_lenght && data.map[y_index][x_index])
			y_index++;
		if (y_index != y_lenght)
			return (_false);
		y_index = 0;
		x_index++;
	}
	y_index = 0;
	while (y_index < y_lenght)
		if (data.map[y_index] && ft_strlen(data.map[y_index++]) != x_lenght)
			return (_false);
	if (x_index >= y_lenght)
		return (_false);
	return (_true);
}


t_boolean is_closed(t_data data) {

	size_t x_lenght;
	size_t x_index;
	size_t y_index;

	x_lenght = ft_strlen(data.map[0]);
	x_index = 0;
	y_index = 0;

	while (x_index < x_lenght) {
		if (data.map[0][x_index] != '1' || data.map[data.lenght_y - 1][x_index] != '1')
			return (_false);
		x_index++;
	}

	while (y_index < data.lenght_y) {
		if (data.map[y_index][0] != '1' || data.map[y_index][x_lenght - 1] != '1')
			return (_false);
		y_index++;
	}

	return (_true);
}
