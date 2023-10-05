/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:59:52 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/05 19:29:00 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "stdlib.h"

typedef struct s_location {

	int	x;
	int	y;
}	t_location;

typedef struct s_collectible
{
	t_location	location;
	int			collected;
}	t_collectible;

typedef struct s_player
{
	t_location		location;
	t_list			*collectibles;
}	t_player;

typedef struct s_world
{
	char		**map;
	int			length_y;
	t_player	*player;
}	t_world;

typedef struct s_texture_list
{
	void				*name;
	void				*texture;
	struct s_texture_list	*next;
}	t_texture_list;

t_world load_map(int fd, char *path);
t_boolean is_horizontal_rectangle(t_world world);
t_boolean is_vertical_rectangle(t_world world);
t_boolean is_rectangle(t_world world);
t_boolean is_closed(t_world world);
t_boolean is_valid_map(t_world world);

t_player init_player(t_location location, t_list *collectibles);

t_list *load_collectibles(t_world world);
t_collectible create_collectible(t_location location);
int count_collectibles(t_list *collectibles, t_boolean o_uncollected, t_boolean o_collected);
void update_collectible(t_list **collectibles, t_location location, t_boolean collected);
void free_collectibles(t_list **collectibles);
t_boolean is_solid(char c, t_player	*player);
t_boolean can_move(int code, t_world *world);

void is_solvable(t_world world, int x, int y);
t_world *clone(t_world world);
int count_element(t_world world, char type);
void *load_texture(char *path, void *mlx);
void draw_type(void *mlx, void *mlx_window, void *texture, t_world world, char c);
int	on_player_move(int keycode, t_world *world);
void free_map(t_world world);
t_location find_element(t_world world, char type);

t_boolean loc_equals(t_location loc_1, t_location loc_2);
t_location edit_location(t_location location, int x, int y);
t_location clone_location(t_location location);
t_location create_location(int x, int y);

t_collectible *get_collectible_at(t_world world, t_location location);
void	ft_lstadd_texture(t_list **lst, t_list *new);

#endif
