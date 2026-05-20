#include "../../header/graphics.h"

void	game(t_graphics **graph)
{
	(*graph)->old_time_struct = (*graph)->time_now_struct;
	gettimeofday(&(*graph)->time_now_struct, NULL);
	(*graph)->old_time = (*graph)->old_time_struct.tv_sec + ((double)(*graph)->old_time_struct.tv_usec / 1000000.0);
	(*graph)->time_now = (*graph)->time_now_struct.tv_sec + ((double)(*graph)->time_now_struct.tv_usec / 1000000.0);
	(*graph)->delta_time = (*graph)->time_now - (*graph)->old_time;
	if ((*graph)->rotate_gauche)
		to_left(graph);
	if ((*graph)->rotate_droite)
		to_right(graph);
	if ((*graph)->avancer)
		up(graph);
	if ((*graph)->reculer)
		down(graph);
	if ((*graph)->a_droite)
		right(graph);
	if ((*graph)->a_gauche)
		left(graph);
	algo(graph);
}

void	to_left(t_graphics **graph)
{
	double	old_x;
	double	old_plane;

	old_plane = (*graph)->plane_x;
	old_x = (*graph)->dir_x;
	(*graph)->dir_x = old_x * cos(-ROT_SPEED * (*graph)->delta_time) - (*graph)->dir_y * sin(-ROT_SPEED * (*graph)->delta_time);
	(*graph)->dir_y = old_x * sin(-ROT_SPEED * (*graph)->delta_time) + (*graph)->dir_y * cos(-ROT_SPEED * (*graph)->delta_time);

	(*graph)->plane_x = old_plane * cos(-ROT_SPEED * (*graph)->delta_time) - (*graph)->plane_y * sin(-ROT_SPEED * (*graph)->delta_time);
	(*graph)->plane_y = old_plane * sin(-ROT_SPEED * (*graph)->delta_time) + (*graph)->plane_y * cos(-ROT_SPEED * (*graph)->delta_time);
	//algo(graph);
}

void	to_right(t_graphics **graph)
{
	double	old_x;
	double	old_plane;

	old_plane = (*graph)->plane_x;
	old_x = (*graph)->dir_x;
	(*graph)->dir_x = old_x * cos(ROT_SPEED * (*graph)->delta_time) - (*graph)->dir_y * sin(ROT_SPEED * (*graph)->delta_time);
	(*graph)->dir_y = old_x * sin(ROT_SPEED * (*graph)->delta_time) + (*graph)->dir_y * cos(ROT_SPEED * (*graph)->delta_time);

	(*graph)->plane_x = old_plane * cos(ROT_SPEED * (*graph)->delta_time) - (*graph)->plane_y * sin(ROT_SPEED * (*graph)->delta_time);
	(*graph)->plane_y = old_plane * sin(ROT_SPEED * (*graph)->delta_time) + (*graph)->plane_y * cos(ROT_SPEED * (*graph)->delta_time);
	//algo(graph);
}

void	up(t_graphics **graph)
{
	double	new_y;
	double	new_x;

	new_y = (*graph)->pos_y + ((*graph)->dir_y * SPEED * (*graph)->delta_time);
	new_x = (*graph)->pos_x + ((*graph)->dir_x * SPEED * (*graph)->delta_time);
	if (new_x < 0 || new_y < 0)
		return ;
	if ((*graph)->map[(int)new_y][(int)new_x] && (*graph)->map[(int)new_y][(int)new_x] != '1')
	{
		(*graph)->pos_x = new_x;
		(*graph)->pos_y = new_y;
		//algo(graph);
	}
	return ;
}

void	down(t_graphics **graph)
{
	double	new_y;
	double	new_x;

	new_y = (*graph)->pos_y - ((*graph)->dir_y * SPEED * (*graph)->delta_time);
	new_x = (*graph)->pos_x - ((*graph)->dir_x * SPEED * (*graph)->delta_time);
	if (new_x < 0 || new_y < 0)
		return ;
	if ((*graph)->map[(int)new_y][(int)new_x] && (*graph)->map[(int)new_y][(int)new_x] != '1')
	{
		(*graph)->pos_x = new_x;
		(*graph)->pos_y = new_y;
		//algo(graph);
	}
	return ;
}

void	right(t_graphics **graph)
{
	double	new_y;
	double	new_x;

	new_y = (*graph)->pos_y + ((*graph)->plane_y * SPEED * (*graph)->delta_time);
	new_x = (*graph)->pos_x + ((*graph)->plane_x * SPEED * (*graph)->delta_time);
	if (new_x < 0 || new_y < 0)
		return ;
	if ((*graph)->map[(int)new_y][(int)new_x] && (*graph)->map[(int)new_y][(int)new_x] != '1')
	{
		(*graph)->pos_x = new_x;
		(*graph)->pos_y = new_y;
		//algo(graph);
	}
	return ;
}

void	left(t_graphics **graph)
{
	double	new_y;
	double	new_x;

	new_y = (*graph)->pos_y - ((*graph)->plane_y * SPEED * (*graph)->delta_time);
	new_x = (*graph)->pos_x - ((*graph)->plane_x * SPEED * (*graph)->delta_time);
	if (new_x < 0 || new_y < 0)
		return ;
	if ((*graph)->map[(int)new_y][(int)new_x] && (*graph)->map[(int)new_y][(int)new_x] != '1')
	{
		(*graph)->pos_x = new_x;
		(*graph)->pos_y = new_y;
		//algo(graph);
	}
	return ;
}
