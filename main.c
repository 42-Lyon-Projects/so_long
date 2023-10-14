/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/12 20:02:26 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	int				fd;
	t_game			game;
	int				value;
	int				graphics;

	fd = handle_file_error(argv);
	if (argc < 1 || fd < 0)
		return (0);
	load_map(fd, argv[1], &game.world);
	value = handle_map_error(game);
	if (value < 0)
		return (0);
	game.world.player = init_player(find_element(game.world, 'P'), \
	load_collectibles(&game.world));
	value = handle_elements_error(argv[1], game);
	if (value < 0)
		return (0);
	graphics = init_graphics_part(&game);
	if (graphics < 0)
		return (0);
	return (destroy(&game), 0);
}
