/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:24:01 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/14 16:21:39 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_location	find_element(t_world world, char type)
{
	int			pos_x;
	int			pos_y;
	t_location	location;

	pos_x = 0;
	pos_y = 0;
	location.x = -1;
	location.y = -1;
	while (world.map[pos_y])
	{
		while (pos_x < (int) ft_strlen(world.map[0]))
		{
			if (world.map[pos_y][pos_x] == type)
			{
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

int	count_element(t_world world, char type)
{
	int	pos_x;
	int	pos_y;
	int	count;

	pos_x = 0;
	pos_y = 0;
	count = 0;
	while (pos_y < world.length_y)
	{
		while (pos_x < (int) ft_strlen(world.map[0]))
		{
			if (world.map[pos_y][pos_x] == type)
				count++;
			pos_x++;
		}
		pos_x = 0;
		pos_y++;
	}
	return (count);
}

t_boolean	ft_endwith(char *src, char *pattern)
{
	int	pattern_size;
	int	src_size;

	if (!pattern || !src)
		return (_false);
	pattern_size = (int) ft_strlen(pattern);
	src_size = (int) ft_strlen(src);
	if (pattern_size > src_size)
		return (_false);
	--pattern_size;
	--src_size;
	while (src_size > 0 && pattern_size > 0)
	{
		if (src[src_size] != pattern[pattern_size])
			return (_false);
		pattern_size--;
		src_size--;
	}
	return (_true);
}
