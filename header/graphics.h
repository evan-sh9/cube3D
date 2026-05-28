/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 10:50:43 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/28 14:44:15 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WIDTH 1160
# define HEIGHT 820
# define TEX_WIDTH 16
# define TEX_HEIGHT 16
# define FLECHE_G 65361
# define FLECHE_D 65363
# define W_AVANT 119
# define A_GAUCHE 97
# define S_ARRIERE 115
# define D_DROITE 100
# define SPEED 5.0
# define ROT_SPEED 4.0

# include "../minilibx-linux/mlx.h"
# include "../src/garbage_collector/gc.h"
# include "parsing.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_mini_map	t_mini_map;
typedef struct s_sword		t_sword;

typedef struct s_texture_mapping
{
	double					wall_x;
	double					wall_y;
	double					text_pos;
	double					step;
	int						texx;
	int						texy;
}							t_texture_mapping;

typedef struct s_graphics
{
	int						rotate_droite;
	int						rotate_gauche;
	int						avancer;
	int						reculer;
	int						a_droite;
	int						a_gauche;
	double					pos_x;
	double					pos_y;
	double					dir_x;
	double					dir_y;
	double					plane_x;
	double					plane_y;
	double					delta_time;
	double					old_time;
	double					time_now;
	double					ray_x;
	double					ray_y;
	double					camera_x;
	double					map_x;
	double					map_y;
	double					delta_x;
	double					delta_y;
	int						step_x;
	int						step_y;
	double					side_x;
	double					side_y;
	double					perpwalldist;
	double					wall_height;
	double					higher_px;
	double					lower_px;
	void					*mlx;
	void					*window;
	void					*img;
	char					*addr;
	char					**map;
	int						bits_per_px;
	int						line_size;
	int						endian;
	t_pars					*pars;
	t_texture_mapping		tex_map;
	double					angle;
	void					*sword_img;
	void					*sword_addr;
	int						sword_pixel;
	int						sword_line_size;
	int						sword_endian;
	double					height_sword;
	double					width_sword;
	int						map_width;
	int						map_height;
	t_mini_map				*mini_map;
	t_sword					*sword;
}							t_graphics;

typedef struct s_mini_map
{
	int						width_minimap;
	int						size_square;
	int						x_start;
	int						y_start;
	int						offset_x;
	int						offset_y;
	int						realmap_idx_x;
	int						realmap_idx_y;
	int						grid_x;
	int						grid_y;
	int						x_minimap;
	int						y_minimap;
}							t_mini_map;

typedef struct s_sword
{
	int						x;
	int						y;
	int						start_x;
	int						start_y;
	int						tex_x;
	int						tex_y;
	int						relative_y;
	int						relative_x;
	char					*ptr;
	unsigned int			color;
}							t_sword;

void						algo(t_graphics **graph);
t_graphics					*dda(double ray_x, double ray_y, t_graphics *graph,
								int x);
double						ft_abs(double num);
void						my_pixel_put(t_graphics *graph, int x, int y,
								int color);
void						ft_exit(t_graphics *graph);
void						mouv(int keycode, t_graphics **graph);
void						stop_mouv(int keycode, t_graphics **graph);
t_graphics					*init_data(t_pars *parse);
void						load_texture(t_graphics *graph);
void						game(t_graphics **graph);
void						to_left(t_graphics **graph);
void						to_right(t_graphics **graph);
void						up(t_graphics **graph);
void						down(t_graphics **graph);
void						right(t_graphics **graph);
void						left(t_graphics **graph);
double						get_time_of_day_ms(void);
void						display(t_graphics *graph, int x, int side);
int							hit_wall(t_graphics *graph);
void						set_delta(t_graphics *graph, double ray_x,
								double ray_y);
void						set_side_step(t_graphics *graph, double ray_x,
								double ray_y);
void						*get_addr_img(void *mlx_ptr, char *filename);
void						*get_addr_sword(t_graphics *graph);
void						put_sword(t_graphics **graph);
void						display(t_graphics *graph, int x, int side);
void						minimap(t_graphics *graph);
int							ft_strlen(char *s);
void						map_dimensions(t_graphics *graph);
void						put_pos(t_graphics *graph);
void						draw_outside_map(t_graphics *graph, int x, int y,
								int size);
void						draw_floor(t_graphics *graph, int x, int y,
								int size);
void						draw_walls_minimap(t_graphics *graph, int x, int y,
								int size);
void						draw_minimap(t_graphics *graph);
void						minimap_two(t_graphics *graph);
void						dir_spawn(t_graphics *graph);
int							hit_wall_next(t_graphics *graph, int map_x,
								int map_y);

#endif