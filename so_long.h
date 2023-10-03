/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:59:52 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/03 11:29:39 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "stdlib.h"

typedef struct s_data {

	char	**map;
	size_t	lenght_y;

}	t_data;

typedef struct s_location {

	size_t	x;
	size_t	y;

}	t_location;

typedef struct s_collectible {

	t_location location;
	t_boolean collected;

}	t_collectible;


t_data load_map(char *path);
t_boolean is_horizontal_rectangle(t_data data);
t_boolean is_vertical_rectangle(t_data data);
t_boolean is_rectangle(t_data data);
t_boolean is_closed(t_data data);

t_list *load_collectibles(t_data data);
t_collectible *create_collectible(t_location location);
int count_collectibles(t_list *collectibles, t_boolean only_uncollected);
void update_collectible(t_list **collectibles, t_location location, t_boolean collected);
void free_collectibles(t_list **collectibles);

void is_solvable(t_data data, size_t x, size_t y);
t_data *clone(t_data data);
int count_element(t_data data, char type);
void *load_texture(char *path, void *mlx);
void draw_type(void *mlx, void *mlx_window, void *texture, t_data data, char c);
int	on_player_move(int keycode, t_data *data);
void free_map(t_data data);
t_location find_element(t_data data, char type);

#endif
