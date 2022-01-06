/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:50:12 by jhermon-          #+#    #+#             */
/*   Updated: 2022/01/06 18:26:59 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"

// size of every sprite
# define IMG_SIZE 64

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif
// ------- tiles
typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	PLAYER = 'P',
}	t_tiletype;

// vector x, y

typedef	struct	s_vector
{
	int x;
	int	y;
}	t_vector;

// boolean
typedef enum	e_bool
{
	TRUE = 1,
	FALSE = 0,
}	t_bool;

// pointer to window

typedef struct	s_window
{
	void	*pointer;
	t_vector	size;
}	t_window;

// struct for each tile

typedef struct	s_tile
{
	t_tiletype	type;
	t_tiletype	og_type;
	t_vector	position;
	struct	s_tile	*up;
	struct	s_tile	*down;
	struct	s_tile	*left;
	struct	s_tile	*right;
}	t_tile;

// struct for each image

typedef struct	s_image
{
	void		*pointer;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;;
	int			endian;
}	t_image;

// struct of values that define a color

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

// all those struct together in a program struct

typedef struct	s_program
{
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_image		tile;
	t_vector	tile_position;
	t_vector	sprite_position;
}	t_program;

// info about the player
typedef struct s_player
{
	t_tile		*tile;
	void		*current_img;
	int			framecount;
	int			idle_frames;
	void		*idle_img_0;
	void		*idle_img_1;
	int			action_frames;
	void		*action_img;
}	t_player;

typedef struct	s_game
{
	void		*mlx;
	void		*window;
	t_vector	wndw_size;
	t_tile		**tilemap;
	t_player	player;
	int			og_collects;
	int			collects;
	int			moves;
	t_vector	img_size;
}	t_game;

// functions

int			error(char *message);
void		*null_error(char *message);
t_image		ft_new_sprite(void *mlx_ptr, char *path);
t_window	ft_new_window(void *mlx_ptr, int width, int height, char *name);
int			ft_input(int key, void *param);
int			ft_update(void *param);

#endif
