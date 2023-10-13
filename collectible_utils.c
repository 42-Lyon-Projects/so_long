/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:24:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/12 08:57:08 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_collectible	*load_collectibles(t_world *world)
{
	int				pos_x;
	int				pos_y;
	t_collectible	*collectible;
	t_location		location;

	pos_x = 0;
	pos_y = 0;
	collectible = NULL;
	while (world->map[pos_y])
	{
		while (world->map[pos_y] && pos_x < (int) ft_strlen(world->map[0]))
		{
			if (world->map[pos_y][pos_x] == 'C')
			{
				location.x = pos_x;
				location.y = pos_y;
				last(&collectible, create_collectible(location));
			}
			pos_x++;
		}
		pos_x = 0;
		pos_y++;
	}
	return (collectible);
}

t_collectible	*create_collectible(t_location location)
{
	t_collectible	*collectible;

	collectible = malloc(sizeof (t_collectible));
	if (!collectible)
		return (NULL);
	collectible->location = location;
	collectible->collected = 0;
	collectible->next = NULL;
	return (collectible);
}

t_collectible	*get_collectible_at(t_world world, t_location location)
{
	while (world.player.collectibles)
	{
		if (loc_equals(location, world.player.collectibles->location))
			return (world.player.collectibles);
		world.player.collectibles = world.player.collectibles->next;
	}
	return (NULL);
}

void	update_col(t_collectible *col, t_location loc, t_boolean bool)
{
	while (col)
	{
		if (loc_equals(col->location, loc))
		{
			col->collected = bool;
			break ;
		}
		col = col->next;
	}
}

void	last(t_collectible **lst, t_collectible *new)
{
	t_collectible	*tmp;

	tmp = *lst;
	if (tmp == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
