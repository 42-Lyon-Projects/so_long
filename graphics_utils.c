/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:56:12 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 19:26:44 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

t_texture *load_textures(void *mlx)
{
	t_texture *list;

	list = malloc(sizeof (t_texture *) * 5);
	if(!list)
		return (NULL);

	ft_lstadd_texture(&list, ft_lstnew(load_texture("./textures/wall.xpm", mlx)));
	ft_lstadd_texture(&list, ft_lstnew(load_texture("./textures/grass.xpm", mlx)));
	ft_lstadd_texture(&list, ft_lstnew(load_texture("./textures/player.xpm", mlx)));
	ft_lstadd_texture(&list, ft_lstnew(load_texture("./textures/collectible.xpm", mlx)));
	ft_lstadd_texture(&list, ft_lstnew(load_texture("./textures/exit.xpm", mlx)));

	return (list);
}


void *load_texture(char *path, void *mlx) {

	void *img;
	char *relative_path = path;
	int img_width;
	int img_height;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	return (img);
}

void draw_type(void *mlx, void *mlx_window, void *texture, t_world world, char c)
{
	int index_y;
	int index_x;

	index_y = 0;
	index_x = 0;

	while (world.map[index_y]) {
		while (index_x < (int) ft_strlen(world.map[index_y])) {
			if (world.map[index_y][index_x] == c) {
				mlx_put_image_to_window(mlx, mlx_window, texture, index_x * 128, index_y * 128);
			}
			index_x++;
		}
		index_x = 0;
		index_y++;
	}
}

void destroy_texture() {

}


void	ft_lstadd_texture(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

t_texture_list 	*ft_newtexture(char	*name, void *content)
{
	t_texture_list	*list;

	list = malloc(sizeof (t_list));
	if (!list)
		return (0);
	list->name = name;
	list->texture = content;
	list->next = NULL;
	return (list);
}
