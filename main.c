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

	fd = handle_file_error(argv);
	if (argc < 1 || fd < 0)
		return (0);
	load_map(fd, argv[1], &game.world);
	game.world.player = init_player(find_element(game.world, 'P'), \
	load_collectibles(&game.world));
	value = handle_map_error(argv[1], game);
	if (value < 0)
		return (0);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	game.textures = load_textures(game.mlx);
	if (free_unavailable_texture(game))
		return (0);
	game.window = mlx_new_window(game.mlx, 128 * ft_strlen(game.world.map[0]), \
	128 * game.world.length_y, "Xe'Burger");
	draws(game);
	mlx_hook(game.window, 2, (1L << 0), on_player_move, &game);
	mlx_loop(game.mlx);
	return (destroy(&game), 0);
}
