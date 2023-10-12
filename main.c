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
#include <fcntl.h>

int main(int argc, char *argv[]) {
	void			*mlx;
	void			*window;
	int				value;
	t_textures		textures;
	t_game			game;

	value = handle_launch_error(argc, argv, &game.world);
	if(value == -1)
		return (0);

	game.world.exit = find_element(game.world, 'E');
	game.world.player = init_player(find_element(game.world, 'P'), load_collectibles(&game.world));

	if(!is_valid_map(game.world))
	{
		ft_putstr_fd("Veuillez verifier votre map (rectangle, collectibles, sortie, ect..)", 1);
		free_map(&game.world);
		return (-1);
	}

	mlx = mlx_init();
	if(!mlx) {
		return (0);
	}


	textures = load_textures(mlx);

	game.mlx = mlx;
	game.textures = textures;

	window = mlx_new_window(mlx, 128 * ft_strlen(game.world.map[0]), 128 * game.world.length_y, "Xe'Burger");
	game.window = window;

	draw_type(mlx, window, &game.world, textures.wall);
	draw_type(mlx, window, &game.world, textures.grass);
	draw_type(mlx, window, &game.world, textures.player);
	draw_type(mlx, window, &game.world, textures.exit);
	draw_collectibles(game);

	mlx_hook(window, 2, (1L<<0), on_player_move, &game);
	mlx_loop(mlx);

	free_map(&game.world);
	free_textures(&game);
	free_collectibles(game.world.player.collectibles);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);

	return 0;
}


int handle_launch_error(int argc, char *argv[], t_world *world)
{
	int	fd;
	if(argc < 2)
	{
		ft_putstr_fd( "You must include the abstract path to your map.\n", 1);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("You must include the abstract path to your map.\n", 1);
		return (-1);
	}
	load_map(fd, argv[1], world);
	return (fd);
}
