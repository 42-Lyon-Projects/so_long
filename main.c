/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/10 19:06:42 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"
#include "minilibx-linux/mlx.h"
#include <fcntl.h>


int main(int argc, char *argv[]) {
	int value;
	t_world *world;

	world = malloc(sizeof(t_world));
	if(!world)
		return (0);

	value = handle_launch_error(argc, argv, world);
	if(value == -1)
		return (0);

	t_location p_pos = find_element(world, 'P');
	t_location *start_location = create_location(p_pos.x, p_pos.y);
	t_collectible *collectibles_list = load_collectibles(world);

	t_player *player = init_player(start_location, collectibles_list);
	world->player = player;

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


	t_textures *textures;
	textures = load_textures(mlx);

	if(textures == NULL)
		return (0);

	t_game *game;

	game = malloc(sizeof (t_game));
	if(!game)
		return (0);

	game->mlx = mlx;
	game->world = world;
	game->textures = textures;
	printf("\nPOS Y %d\n", game->world->player->location->y);
	printf("\nPOS X %d\n", game->world->player->location->x);

	void *window = mlx_new_window(mlx, 128 * ft_strlen(world->map[0]), 128 * world->length_y, "Xe'Burger");
	game->window = window;

	draw_type(mlx, window, world, *textures->wall);
	draw_type(mlx, window, world, *textures->grass);
	draw_type(mlx, window, world, *textures->player);
	draw_type(mlx, window, world, *textures->collectible);
	draw_type(mlx, window, world, *textures->exit);


	mlx_hook(window, 2, (1L<<0), on_player_move, game);
	mlx_loop(mlx);

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
