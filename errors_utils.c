/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:50:08 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/13 17:50:08 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	handle_file_error(char *argv[])
{
	int	fd;

	if (!argv[1])
		return (ft_printf("Error\n -> Invalid file path.\n"), -2);
	if (!ft_endwith(argv[1], ".ber"))
		return (ft_printf("Error\n -> Invalid file format.\n"), -2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n -> Can't open file.\n");
		ft_printf("please check permissions or path: %s", argv[1]);
		return (-2);
	}
	return (fd);
}

t_boolean	handle_map_solve(char *path, t_game game)
{
	t_world	cloned;

	load_map(open(path, O_RDONLY), path, &cloned);
	is_solvable(cloned.map, game.world.player.location.x, \
	game.world.player.location.y, game.world.length_y);
	if (count_element(cloned, 'C') > 0 || count_element(cloned, 'E') > 0)
	{
		ft_printf("Error\n -> Sorry, your map is not resolvable");
		free_collectibles(game.world.player.collectibles);
		return (free_map(&game.world), free_map(&cloned), -2);
	}
	free_map(&cloned);
	return (0);
}

int	handle_elements_error(char *path, t_game game)
{
	int				elements_code;

	elements_code = valid_elements(game.world);
	if (elements_code < 0)
	{
		ft_printf("Error\n -> Map must contains 1 E, 1 P, minimum 1 C");
		free_collectibles(game.world.player.collectibles);
		free_map(&game.world);
		return (-1);
	}
	return (handle_map_solve(path, game));
}

int	handle_map_error(t_game game)
{
	if (has_illegal_character(game.world))
	{
		free_map(&game.world);
		return (ft_printf("Error\n -> Invalid Map / illegal character"), -1);
	}
	if (!is_valid_shape(game.world))
	{
		free_map(&game.world);
		return (ft_printf("Error\n -> Invalid shape / not closed"), -1);
	}
	return (0);
}
