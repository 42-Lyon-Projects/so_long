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

t_boolean	loc_equals(t_location loc_1, t_location loc_2)
{
	if (loc_1.x == loc_2.x && loc_1.y == loc_2.y)
		return (_true);
	else
		return (_false);
}
