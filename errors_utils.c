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
		return (ft_putstr_fd("Error\n -> Invalid file path.\n", 1), -2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\n -> Invalid file path.\n", 1), -2);
	return (fd);
}

int	handle_map_error(char *path, t_game game)
{
	int				elements_code;
	t_world			cloned;

	if (has_illegal_character(game.world)){
		free_map(&game.world);
		free_collectibles(game.world.player.collectibles);
		return (ft_putstr_fd("Error\n -> Invalid Map / illegal character", 1), -1);

	}
	if (!is_valid_shape(game.world))
	{
		free_map(&game.world);
		free_collectibles(game.world.player.collectibles);
		return (ft_putstr_fd("Error\n -> Invalid shape / not closed", 1), -1);
	}
	elements_code = valid_elements(game.world);
	if (elements_code < 0)
	{
		ft_putstr_fd("Error\n -> Please, check your map !", 1);
		ft_putstr_fd("\nThe map must contains 1 E, 1 P, minimum 1 C", 1);
		return (-1);
	}
	load_map(open(path, O_RDONLY), path, &cloned);
	is_solvable(cloned.map, game.world.player.location.x, game.world.player.location.y, game.world.length_y);
	if (count_element(cloned, 'C') > 0 || count_element(cloned, 'E') > 0)
	{
		ft_putstr_fd("Error\n -> Sorry, your map is not resolvable", 1);
		free_map(&game.world);
		free_collectibles(game.world.player.collectibles);
		return (free_map(&cloned), -2);
	}
	free_map(&cloned);
	return (0);
}