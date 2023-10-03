/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:24:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/03 10:37:46 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_location find_element(t_data data, char type) {
	size_t pos_x;
	size_t pos_y;
	t_location location;

	pos_x = 0;
	pos_y = 0;
	location.x = -1;
	location.y = -1;
	while (pos_y < data.lenght_y) {
		while (pos_x < ft_strlen(data.map[0])) {
			if (data.map[pos_y][pos_x] == type) {
				location.x = ++pos_x;
				location.y = ++pos_y;
				return (location);
			}
			pos_x++;
		}
		pos_x = 0;
		pos_y++;
	}
	return (location);
}

int count_element(t_data data, char type)
{
	size_t pos_x;
	size_t pos_y;
	int count;

	pos_x = 0;
	pos_y = 0;
	count = 0;
	while (pos_y < data.lenght_y) {
		while (pos_x < ft_strlen(data.map[0])) {
			if (data.map[pos_y][pos_x] == type)
				count++;

			pos_x++;
		}
		pos_x = 0;
		pos_y++;
	}
	return (count);
}

t_data *clone(t_data data) {
	t_data *clone;
	size_t index;
	char **content;

	clone = malloc(sizeof(t_data));
	if(!clone)
		return (NULL);
	clone->lenght_y = data.lenght_y;
	index = 0;
	content = malloc(sizeof(char *) * clone->lenght_y);
	if(!content)
		return (NULL);

	while (index < clone->lenght_y) {
		content[index] = ft_strdup(data.map[index]);
		index++;
	}
	clone->map = content;
	return (clone);
}