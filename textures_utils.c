/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:28:23 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/13 16:28:23 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	load_textures(void *mlx)
{
	t_textures	textures;

	textures.wall = load_texture(mlx, '1', "./textures/wall.xpm");
	textures.grass = load_texture(mlx, '0', "./textures/grass.xpm");
	textures.player = load_texture(mlx, 'P', "./textures/player.xpm");
	textures.collectible = load_texture(mlx, 'C', "./textures/collectible.xpm");
	textures.exit = load_texture(mlx, 'E', "./textures/exit.xpm");
	return (textures);
}

t_texture	load_texture(void *mlx, char character, char *path)
{
	int			img_width;
	int			img_height;
	t_texture	texture;

	texture.character = character;
	texture.texture = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	texture.is_set = _true;
	return (texture);
}

t_boolean	has_unavailable_texture(t_textures textures)
{
	if (textures.exit.texture == NULL)
		return (_true);
	if (textures.player.texture == NULL)
		return (_true);
	if (textures.wall.texture == NULL)
		return (_true);
	if (textures.collectible.texture == NULL)
		return (_true);
	if (textures.grass.texture == NULL)
		return (_true);
	return (_false);
}
