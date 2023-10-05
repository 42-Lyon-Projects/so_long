/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 16:31:39 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"
#include "minilibx-linux/mlx.h"
#include <fcntl.h>


int main(int argc, char *argv[]) {
	(void) argc;
	int fd;
	if(argc < 2)
	{
		ft_putstr_fd( "Veuillez inclure le chemin vers une map dans votre commande.\n", 1);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Veuillez inclure le chemin vers une map dans votre commande.\n", 1);
		return (-1);
	}
	t_world world = load_map(fd, argv[1]);

	t_location start_location = find_element(world, 'P');
	t_list *collectibles_list = load_collectibles(world);

	t_player player = init_player(start_location, collectibles_list);
	world.player = &player;

	if(!is_valid_map(world))
	{
		ft_putstr_fd("Veuillez verifier votre map (rectangle, collectibles, sortie, ect..)", 1);
		free_map(world);
		return (-1);
	}

	void	*mlx;

	mlx = mlx_init();
	if(!mlx) {
		return (0);
	}


	void *window = mlx_new_window(mlx, 2500, 2000, "Hello world!");

	void *wall_texture = load_texture("./textures/wall.xpm", mlx);
	void *grass_texture = load_texture("./textures/grass.xpm", mlx);
	void *exit_texture = load_texture("./textures/exit.xpm", mlx);
	void *player_texture = load_texture("./textures/player.xpm", mlx);
	void *collectible_texture = load_texture("./textures/collectible.xpm", mlx);

	draw_type(mlx, window, wall_texture, world, '1');
	draw_type(mlx, window, grass_texture, world, '0');
	draw_type(mlx, window, exit_texture, world, 'E');
	draw_type(mlx, window, player_texture, world, 'P');
	draw_type(mlx, window, collectible_texture, world, 'C');

	mlx_hook(window, 2, (1L<<0), &on_player_move, &world);
	mlx_loop(mlx);
	mlx_destroy_display(mlx);
	mlx_clear_window(mlx, window);
	mlx_destroy_window(mlx, window);
	free(mlx);

	free_map(world);


	return 0;
}
