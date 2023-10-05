/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:24:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 15:02:04 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_location find_element(t_world world, char type) {
	int pos_x;
	int pos_y;
	t_location location;

	pos_x = 0;
	pos_y = 0;
	location.x = -1;
	location.y = -1;
	while (world.map[pos_y]) {
		while (pos_x < (int) ft_strlen(world.map[0])) {
			if (world.map[pos_y][pos_x] == type) {
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

int count_element(t_world world, char type)
{
	int pos_x;
	int pos_y;
	int count;

	pos_x = 0;
	pos_y = 0;
	count = 0;
	while (pos_y < world.length_y) {
		while (pos_x < (int) ft_strlen(world.map[0])) {
			if (world.map[pos_y][pos_x] == type)
				count++;

			pos_x++;
		}
		pos_x = 0;
		pos_y++;
	}
	return (count);
}

t_world *clone(t_world world) {
	t_world *clone;
	int index;
	char **content;

	clone = malloc(sizeof(t_world));
	if(!clone)
		return (NULL);
	clone->length_y = world.length_y;
	index = 0;
	content = malloc(sizeof(char *) * clone->length_y);
	if(!content)
		return (NULL);

	while (index < clone->length_y) {
		content[index] = ft_strdup(world.map[index]);
		index++;
	}
	clone->map = content;
	return (clone);
}