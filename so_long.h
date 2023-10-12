/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:59:52 by jbadaire          #+#    #+#             */
/*   Updated: 2023/10/12 17:14:35 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# include <stdlib.h>

typedef struct s_location {
	int	x;
	int	y;
}	t_location;

typedef struct s_collectible
{
	t_location				location;
	int						collected;
	t_boolean				is_set;
	struct s_collectible	*next;
}	t_collectible;


typedef struct s_player
{
	t_location		location;
	t_collectible 	*collectibles;
	int				movements;
}	t_player;

typedef struct s_world
{
	char		**map;
	int			length_y;
	t_location	exit;
	t_player	player;
}	t_world;

typedef struct s_texture
{
	char				character;
	void				*texture;
	t_boolean			is_set;
}	t_texture;


typedef struct s_textures
{
	struct s_texture	wall;
	struct s_texture	grass;
	struct s_texture	collectible;
	struct s_texture	player;
	struct s_texture	exit;
}	t_textures;


typedef struct s_game
{
	struct s_textures	textures;
	struct s_world		world;
	void		*mlx;
	void		*window;

}	t_game;


// ** UTILS ** //
t_boolean loc_equals(t_location loc_1, t_location loc_2);


// ** MAP ** //
t_world *load_map(int fd, char *path, t_world *world);
t_location find_element(t_world world, char type);
void is_solvable(t_world *world, int x, int y);
t_boolean is_valid_map(t_world world);
int count_element(t_world world, char type);


// ** MATHS ** //
t_boolean is_horizontal_rectangle(t_world world);
t_boolean is_vertical_rectangle(t_world world);
t_boolean is_rectangle(t_world world);
t_boolean is_closed(t_world world);
t_boolean is_inside_world(int y, int x, t_world world);


// ** COLLECTIBLES ** //
t_collectible *get_collectible_at(t_world world, t_location location);
void update_collectible(t_collectible *collectibles, t_location location, t_boolean collected);
void draw_collectibles(t_game game);
t_collectible *load_collectibles(t_world *world);
t_collectible *create_collectible(t_location location);
int count_collectibles(t_collectible collectibles, t_boolean o_uncollected, t_boolean o_collected);

// ** TEXTURES ** //
t_textures load_textures(void *mlx);
t_texture load_texture(void *mlx, char character, char *path);
void draw_type(void *mlx, void *mlx_window, t_world *world, t_texture texture);


// ** PLAYER ** //
int	on_player_move(int keycode, t_game *world);
t_boolean is_solid(char c, t_game player);
t_boolean can_move(int code, t_game world);
t_player init_player(t_location location, t_collectible *collectibles);


// ** FREES ** //
void free_map(t_world *world);
void free_textures(t_game *game);
void free_collectibles(t_collectible *collectible);


int handle_launch_error(int argc, char *argv[], t_world *world);

#endif
