/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:56:12 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/10 15:20:11 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

t_textures *load_textures(void *mlx)
{
	t_textures *textures;

	textures = malloc(sizeof (t_textures));
	if(!textures)
		return (NULL);

	textures->wall = load_texture(mlx, '1', "./textures/wall.xpm");
	textures->grass = load_texture(mlx, '0', "./textures/grass.xpm");
	textures->player = load_texture(mlx, 'P', "./textures/player.xpm");
	textures->collectible = load_texture(mlx, 'C', "./textures/collectible.xpm");
	textures->exit = load_texture(mlx, 'E', "./textures/exit.xpm");

	if (textures->wall == NULL || textures->grass == NULL || textures->exit == NULL)
		return (NULL);
	if (textures->collectible == NULL || textures->player == NULL)
		return (NULL);

	return (textures);
}


t_texture *load_texture(void *mlx, char character, char *path)
{
	int			img_width;
	int			img_height;
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if(!texture)
		return (NULL);

	texture->character = character;
	texture->texture = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	return (texture);
}

void draw_type(void *mlx, void *mlx_window, t_world *world, t_texture texture)
{
	int index_y;
	int index_x;

	index_y = 0;
	index_x = 0;

	while (world->map[index_y]) {
		while (index_x < (int) ft_strlen(world->map[index_y])) {
			if (world->map[index_y][index_x] == texture.character) {
				mlx_put_image_to_window(mlx, mlx_window, texture.texture, index_x * 128, index_y * 128);
			}
			index_x++;
		}
		index_x = 0;
		index_y++;
	}
}

