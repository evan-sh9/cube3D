#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WIDTH 2560
# define HEIGHT 1440
// # define PI 3.14159265358 deja dispo dans la lib math

#include "../minilibx-linux/mlx.h"

typedef struct s_graphics
{
	double	pos_x; // position x du joueur
	double	pos_y; // position y du joueur
	
	double	dir_x; // direction y du joueur (vecteur de direction)
	double	dir_y; // direction y du joueur (vecteur de direction)
	
	double	plane_x; // le plan x
	double	plane_y; // le plan y
	
	double	time_now; // les time c'est pour le temps de chque frame et les fps
	double	old_time;

	double	ray_x;
	double	ray_y;

	double	camera_x;

	double	map_x;
	double	map_y;

	double	delta_x;
	double	delta_y;

	void	*mlx;
	void	*window;

	t_pars	*pars;
} t_graphics;

#endif