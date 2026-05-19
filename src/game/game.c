#include "../../header/graphics.h"

void	game(t_graphics **graph)
{
	if ((*graph)->rotate_gauche)
		to_left(graph);
	if ((*graph)->rotate_droite)
		to_right(graph);
	// if ((*graph)->avancer)
	// 	up(graph);
	// if ((*graph)->reculer)
	// 	down(graph);
	// if ((*graph)->a_droite)
	// 	right(graph);
	// if ((*graph)->a_gauche)
	// 	left(graph);
	//algo(graph);
	// mlx_hook((*graph)->window, 2, (1L<<0), (void *)mouv, &graph);
	// mlx_hook((*graph)->window, 3, 1L<<1, (void *)stop_mouv, &graph);	mlx_hook((*graph)->window, 17, 0, (void *)ft_exit, graph);
	// mlx_hook((*graph)->window, 17, 0, (void *)ft_exit, graph);
	//mlx_loop((*graph)->mlx);
}

void	to_left(t_graphics **graph)
{
	double	old_x;
	double	old_plane;

	old_plane = (*graph)->plane_x;
	old_x = (*graph)->dir_x;
	(*graph)->dir_x = old_x * cos(-0.04) - (*graph)->dir_y * sin(-0.04);
	(*graph)->dir_y = old_x * sin(-0.04) + (*graph)->dir_y * cos(-0.04);

	(*graph)->plane_x = old_plane * cos(-0.04) - (*graph)->plane_y * sin(-0.04);
	(*graph)->plane_y = old_plane * sin(-0.04) + (*graph)->plane_y * cos(-0.04);
	algo(graph);
}

void	to_right(t_graphics **graph)
{
	double	old_x;
	double	old_plane;

	old_plane = (*graph)->plane_x;
	old_x = (*graph)->dir_x;
	(*graph)->dir_x = old_x * cos(0.04) - (*graph)->dir_y * sin(0.04);
	(*graph)->dir_y = old_x * sin(0.04) + (*graph)->dir_y * cos(0.04);

	(*graph)->plane_x = old_plane * cos(0.04) - (*graph)->plane_y * sin(0.04);
	(*graph)->plane_y = old_plane * sin(0.04) + (*graph)->plane_y * cos(0.04);
	algo(graph);
}

