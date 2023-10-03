/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:56:12 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/03 15:33:57 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

void *load_texture(char *path, void *mlx) {

	void *img;
	char *relative_path = path;
	int img_width;
	int img_height;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	return (img);
}

void draw_type(void *mlx, void *mlx_window, void *texture, t_data data, char c)
{
	size_t index_y;
	size_t index_x;

	index_y = 0;
	index_x = 0;
	while (index_y < data.lenght_y) {
		while (index_x < ft_strlen(data.map[index_y])) {
			if (data.map[index_y][index_x] == c)
				mlx_put_image_to_window(mlx, mlx_window, texture, index_x * 128, index_y * 128);
			index_x++;
		}
		index_x=0;
		index_y++;
	}
}

void destroy_texture() {

}

