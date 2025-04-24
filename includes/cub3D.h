/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdorig <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:37:05 by cdorig            #+#    #+#             */
/*   Updated: 2025/04/15 09:29:35 by cdorig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*------------------------------Includes------------------------------*/

# include <stdio.h>
# include "../lib/libft/includes/libft.h"
# include "../lib/mlx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "debug.h"

/*------------------------------Macros------------------------------*/

// Math values
# define PI 3.1415
# define TILE 2048

// MLX info
# define W_WIDTH 1920
# define W_HEIGHT 1080
# define W_NAME "Cub3D"
# define MMAP_WALL 10

// File contents
# define PLAYER "NSWE"
# define MAP_CHARS " 01NSWE"

/*------------------------------Structures------------------------------*/

typedef enum e_keys
{
	W = 0,
	A = 1,
	S = 2,
	D = 3,
	LEFT = 4,
	RIGHT = 5
}	t_keys;

typedef enum e_texindex
{
	NORTH = 0,
	SOUTH = 1,
	WEST = 2,
	EAST = 3
}	t_texindex;

typedef struct s_img
{
	void	*ptr;
	int		*addr;
	int		b;
	int		ll;
	int		e;
	int		width;
	int		height;
}	t_img;

typedef struct s_texpath
{
	char	*path;
	int		color;
}	t_texpath;

typedef struct s_map
{
	t_texpath	no;
	t_texpath	so;
	t_texpath	we;
	t_texpath	ea;
	t_texpath	f;
	t_texpath	c;
	char		**map;
	int			map_width;
	int			map_height;
}	t_map;

typedef struct s_ray
{
	double	cam_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	rot;
	int		moved;
	int		keys[20];
}	t_player;

typedef struct s_tex
{
	int		x;
	int		y;
	int		size;
	double	step;
	double	pos;
	t_img	texs[4];
}	t_tex;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_map		map;
	t_player	player;
	t_tex		tex;
	int			minimap_mode;
}	t_data;

/*------------------------------Prototypes------------------------------*/

// exit
	// exit.c
void	err_msg(char *msg);
void	clean_exit(t_data *data, int status);
int		exit_program(t_data *data);
void	exit_msg(t_data *data, char *msg, int status, int exit);
	// free.c
void	free_textures(t_data *data);
void	free_tab(char **tab);

// init
	// check_args.c
void	check_args(int ac, char **av);
	// init_data.c
void	init_textures(t_data *data);
void	init_data(t_data *data);

// mlx
	// hooks.c
void	init_hooks(t_data *data);
	// minimap_utils.c
void	draw_cell(t_data *data, int screen_x, int screen_y, int color);
	// show_minimap.c
void	show_minimap(t_data *data);
void	hide_minimap(t_data *data);
	// window.c
void	assign_textures(t_data *data, void *m, t_tex *t, t_map *map);
void	create_window(t_data *data);
int		destroy_window(t_data *data);

// parsing
	// check_contents.c
void	check_map_contents(t_data *data);
void	check_floor_ceiling(t_data *data);
void	check_textures(t_data *data);
	// color_utils.c
int		check_colors(t_data *data, char **colors, char *ident);
	// handle_identifier.c
int		handle_identifier(t_data *data, char *line);
	// handle_map.c
int		handle_map(t_data *data, char **arr, int i);
	// handle_player.c
void	handle_player(t_data *data, char c, int x, int y);
	// line_utils.c
int		is_empty_line(char *content);
int		is_map(char *line);
int		check_line(t_data *data, char **arr);
	// parse_and_check.c
void	parse_and_check(t_data *data, char *path);

// update
	// move_player.c
int		rotate_player(t_player *player, int rot_dir);
void	move_player(t_data *data);
	// raycasting.c
void	raycasting(t_data *data);
	// textures.c
void	pix_to_img(t_img *i, int x, int y, int color);
void	get_pix_color(t_data *data, t_tex *tex, t_ray *ray, int x);

#endif
