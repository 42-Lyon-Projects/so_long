/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:19:55 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/03 15:45:24 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"
#include "minilibx-linux/mlx.h"


int main() {

	t_data data = load_map("/home/jimmy/CLionProjects/so_long/maps/1.ber");
	t_data *copy_map = clone(data);

	int collectibles;
	int exit;

	collectibles = 0;
	exit = 0;

	printf("Is Rectangle: %b", is_rectangle(data));
	t_location start_location = find_element(data, 'P');
	printf("\nStart location %zu %zu", start_location.x, start_location.y);
	t_location exit_location = find_element(data, 'E');
	printf("\nExit location %zu %zu", exit_location.x, exit_location.y);
	t_list *list = load_collectibles(data);
	t_list *copy = list;
	while (copy->next != NULL) {
		t_collectible *col = ((t_collectible *) copy->content);
		printf("\nCollectible: X %zu : Y %zu collected %b", col->location.x, col->location.y, col->collected);
		copy = copy->next;
	}

	printf("\nCollectibles Count: %d", count_collectibles(list, _false));
	printf("\nIs closed: %b", is_closed(data));

	is_solvable(*copy_map, start_location.x, start_location.y);
	printf("\nSolvable ");
	size_t index = 0;
	while (index < data.lenght_y) {
		printf("\nCopyMAP: %s", copy_map->map[index]);
		index++;
	}

	collectibles = count_element(*copy_map, 'C');
	exit = count_element(*copy_map, 'E');
	printf("\nStruct error : %b", collectibles != 0 || exit != 0);

	void	*mlx;

	mlx = mlx_init();
	if(!mlx) {
		return (0);
	}

	void *window = mlx_new_window(mlx, 1500, 800, "Hello world!");

	void *wall = load_texture("./textures/wall.xpm", mlx);
	void *grass = load_texture("./textures/grass.xpm", mlx);
	void *collectible = load_texture("./textures/collectible.xpm", mlx);
	void *ext = load_texture("./textures/exit.xpm", mlx);
	void *player = load_texture("./textures/player.xpm", mlx);

	draw_type(mlx, window, wall, data, '1');
	draw_type(mlx, window, grass, data, '0');
	draw_type(mlx, window, collectible, data, 'C');
	draw_type(mlx, window, ext, data, 'E');
	draw_type(mlx, window, player, data, 'P');


	//mlx_hook(window, 2,  1L << 0, on_player_move, &data);

	mlx_loop(mlx);

	return 0;
}
