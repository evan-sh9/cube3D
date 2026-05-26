#include "../../header/graphics.h"

void	map_dimensions(t_graphics *graph)
{
	int	y;

	y = 0;
	graph->map_width = ft_strlen(graph->pars->map[y]);
	while (y < graph->pars->map_height)
	{
		if (ft_strlen(graph->pars->map[y]) > graph->map_width)
			graph->map_width = ft_strlen(graph->pars->map[y]);
		y++;
	}
	graph->map_height = graph->pars->map_height;
	return ;
}

void	up(t_graphics **graph)
{
	double	new_y;
	double	new_x;

	new_y = (*graph)->pos_y + ((*graph)->dir_y
			* SPEED * (*graph)->delta_time);
	new_x = (*graph)->pos_x + ((*graph)->dir_x
			* SPEED * (*graph)->delta_time);
	if (new_x < 0 || new_y < 0)
		return ;
	if ((*graph)->pars->map[(int)new_y][(int)new_x]
		&& ((*graph)->pars->map[(int)new_y][(int)new_x] == '0'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'N'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'E'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'S'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'W'))
	{
		(*graph)->pos_x = new_x;
		(*graph)->pos_y = new_y;
	}
	return ;
}

void	down(t_graphics **graph)
{
	double	new_y;
	double	new_x;

	new_y = (*graph)->pos_y
		- ((*graph)->dir_y * SPEED * (*graph)->delta_time);
	new_x = (*graph)->pos_x
		- ((*graph)->dir_x * SPEED * (*graph)->delta_time);
	if (new_x < 0 || new_y < 0)
		return ;
	if ((*graph)->pars->map[(int)new_y][(int)new_x]
		&& ((*graph)->pars->map[(int)new_y][(int)new_x] == '0'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'N'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'E'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'S'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'W'))
	{
		(*graph)->pos_x = new_x;
		(*graph)->pos_y = new_y;
	}
	return ;
}

void	right(t_graphics **graph)
{
	double	new_y;
	double	new_x;

	new_y = (*graph)->pos_y
		+ ((*graph)->plane_y * SPEED * (*graph)->delta_time);
	new_x = (*graph)->pos_x
		+ ((*graph)->plane_x * SPEED * (*graph)->delta_time);
	if (new_x < 0 || new_y < 0)
		return ;
	if ((*graph)->pars->map[(int)new_y][(int)new_x]
		&& ((*graph)->pars->map[(int)new_y][(int)new_x] == '0'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'N'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'E'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'S'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'W'))
	{
		(*graph)->pos_x = new_x;
		(*graph)->pos_y = new_y;
	}
	return ;
}

void	left(t_graphics **graph)
{
	double	new_y;
	double	new_x;

	new_y = (*graph)->pos_y - ((*graph)->plane_y
			* SPEED * (*graph)->delta_time);
	new_x = (*graph)->pos_x - ((*graph)->plane_x
			* SPEED * (*graph)->delta_time);
	if (new_x < 0 || new_y < 0)
		return ;
	if ((*graph)->pars->map[(int)new_y][(int)new_x]
		&& ((*graph)->pars->map[(int)new_y][(int)new_x] == '0'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'N'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'E'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'S'
			|| (*graph)->pars->map[(int)new_y][(int)new_x] == 'W'))
	{
		(*graph)->pos_x = new_x;
		(*graph)->pos_y = new_y;
	}
	return ;
}
