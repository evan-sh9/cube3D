#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WIDTH 2560
# define HEIGHT 1440
// # define PI 3.14159265358 deja dispo dans la lib math

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "parsing.h"
#include <math.h>
#include <stdlib.h>

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

	double	ray_x; // le rayon qu'on calcule pour chaque camera_x (pour chaque colonne de l'ecran)
	double	ray_y; // pareil mais en y

	double	camera_x; 

	double	map_x; // la case sur laquelle se trouve le joueur
	double	map_y; // pareil mais en y

	double	delta_x; // la distance que doit parcourir un vecteur pour traverser une case
	double	delta_y; // pareil mais en y

	int		step_x;
	int		step_y;

	double	side_x; // la distcance que doit parcourir le rayon pour atteindre la prochaine case a partir de la 
	double	side_y; // pareil mais en y

	double	perpWallDist; // la distcance qu'on va utiliser pour eviter le fisheye effect
	
	double	wall_height; // la taille du mur apres avoir calcule la distance avec perpwall

	double	higher_px; // les coordonnes du pixel du haut
	double	lower_px; // les coordonnes des pixels du bas

	void	*mlx;
	void	*window;
	char	**map;

	t_pars	*pars;
} t_graphics;

void	algo(t_graphics **graph);
t_graphics	*dda(double ray_x, double ray_y, t_graphics *graph, int x);
double	ft_abs(double num);

#endif