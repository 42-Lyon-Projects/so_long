/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:30:50 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 15:36:04 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_location create_location(int x, int y)
{
	t_location location;

	location.x = x;
	location.y = y;
	return (location);
}

t_location clone_location(t_location location)
{
	t_location  clone;

	clone.x = location.x;
	clone.y = location.y;
	return (clone);
}

t_location edit_location(t_location location, int x, int y)
{
	location.x += x;
	location.y += y;
	return (location);
}

t_boolean loc_equals(t_location loc_1, t_location loc_2)
{
	return loc_1.x == loc_2.x && loc_1.y == loc_2.y;
}