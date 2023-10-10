/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:30:50 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/10 17:06:20 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_location *create_location(int x, int y)
{
	t_location *location;

	location = malloc(sizeof (t_location));
	if(!location)
		return (NULL);

	location->x = x;
	location->y = y;
	return (location);
}

t_boolean loc_equals(t_location *loc_1, t_location *loc_2)
{
	return loc_1->x == loc_2->x && loc_1->y == loc_2->y;
}