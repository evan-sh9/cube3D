#include "../../header/graphics.h"

void	algo(t_graphics **graph)
{
	double	x; // pour la boucle pour faire toutes les colonnes de pixel de l'ecran

	x = 0;
	while (x < WIDTH)
	{
		(*graph)->camera_x = 2 * x / (double)WIDTH - 1;
		(*graph)->ray_x = (*graph)->dir_x + (*graph)->plane_x * (*graph)->camera_x;
		(*graph)->ray_y = (*graph)->dir_y + (*graph)->plane_y * (*graph)->camera_x;
		*graph = dda((*graph)->ray_x, (*graph)->ray_y, *graph, x);
		x++;
	}
	mlx_put_image_to_window((*graph)->mlx, (*graph)->window, (*graph)->img, 0, 0);
}

double	ft_abs(double num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_graphics	*dda(double ray_x, double ray_y, t_graphics *graph, int x)
{
	int hit;

	hit = 0;
	int side;
	graph->map_x = (int)graph->pos_x;
	graph->map_y = (int)graph->pos_y;
	
	
	if (ray_x != 0)
		graph->delta_x = ft_abs(1 / ray_x);
	else
		graph->delta_x = 1e30;
	if (ray_y != 0)
		graph->delta_y = ft_abs(1 / ray_y);
	else
		graph->delta_y = 1e30;
	
	if (ray_x < 0)
	{
		graph->step_x = -1;
		graph->side_x = (graph->pos_x - graph->map_x) * graph->delta_x;
	}
	else
	{
		graph->step_x = 1;
		graph->side_x = (graph->map_x + 1.0 - graph->pos_x) * graph->delta_x;
	}
	if (ray_y < 0)
	{
		graph->step_y = -1;
		graph->side_y = (graph->pos_y - graph->map_y) * graph->delta_y;
	}
	else
	{
		graph->step_y = 1;
		graph->side_y = (graph->map_y + 1.0 - graph->pos_y) * graph->delta_y;
	}


	while (hit == 0)
	{
		if (graph->side_x < graph->side_y)
		{
			graph->side_x += graph->delta_x;
			graph->map_x += graph->step_x;
			side = 0;
		}
		else
		{
			graph->side_y += graph->delta_y;
			graph->map_y += graph->step_y;
			side = 1;
		}
		if (graph->map[(int)graph->map_y][(int)graph->map_x] == '1')
			hit = 1;
	}

	if (side == 0)
		graph->perpWallDist = (graph->side_x - graph->delta_x);
	else
		graph->perpWallDist = (graph->side_y - graph->delta_y);
		
	graph->wall_height = (int)(HEIGHT / graph->perpWallDist);
	graph->higher_px = - graph->wall_height / 2 + HEIGHT / 2;
	if (graph->higher_px < 0)
		graph->higher_px = 0;
	graph->lower_px = graph->wall_height / 2 + HEIGHT / 2;
	if (graph->lower_px >= HEIGHT)
		graph->lower_px = HEIGHT - 1;
	
	int y;
	y = 0;
	while (y < graph->higher_px)
	{
		my_pixel_put(graph, x, y, 0x333333);
		y++;
	}
	while (y <= graph->lower_px)
	{
		int color = 0xFF0000;
		if (side == 1)
			color = color / 2;
		my_pixel_put(graph, x, y, color);
		y++;
	}
	while (y < HEIGHT)
	{
		my_pixel_put(graph, x, y, 0x666666);
		y++;
	}
	return (graph);
}

void	my_pixel_put(t_graphics *graph, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = graph->addr + (y * graph->line_size + x * (graph->bits_per_px / 8));
	*(unsigned int*)dst = color;
}
