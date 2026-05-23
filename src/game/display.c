#include "../../header/cub3D.h"

void	display_floor(t_graphics *graph, int x, int y, int side)
{
	while (y < HEIGHT)
	{
		my_pixel_put(graph, x, y, 0x666666);
		y++;
	}
}

int	px_color(t_graphics *graph, t_img *curr_tex, int x, int y)
{
	int	color;

	color = *(int *)(curr_tex->img_addr + (graph->tex_map.texY
				* curr_tex->size_line) + (graph->tex_map.texX
				* (curr_tex->bits_pp / 8)));
	my_pixel_put(graph, x, y, color);
}

void	display_wall(t_graphics *graph, int x, int y, int side)
{
	int		color;
	t_img	*curr_tex;

	while (y <= graph->lower_px)
	{
		graph->tex_map.texY = (int)(graph->tex_map.text_pos) & (TEX_HEIGHT - 1);
		graph->tex_map.text_pos += graph->tex_map.step;
		if (side == 1)
		{
			if (graph->step_y == -1)
				curr_tex = &graph->pars->tex.north_wall;
			else
				curr_tex = &graph->pars->tex.south_wall;
		}
		else
		{
			if (graph->step_x == 1)
				curr_tex = &graph->pars->tex.east_wall;
			else
				curr_tex = &graph->pars->tex.west_wall;
		}
		color = px_color(graph, curr_tex, x, y);
		y++;
	}
	display_floor(graph, x, y, side);
}

void	display(t_graphics *graph, int x, int side)
{
	int	y;

	y = 0;
	while (y < graph->higher_px)
	{
		my_pixel_put(graph, x, y, 0x333333);
		y++;
	}
	if (side == 1)
		graph->tex_map.wall_x = graph->pos_x + graph->perpWallDist
			* graph->ray_x;
	else
		graph->tex_map.wall_x = graph->pos_y + graph->perpWallDist
			* graph->ray_y;
	graph->tex_map.wall_x = claim_decimal(graph->tex_map.wall_x);
	graph->tex_map.texX = (int)(graph->tex_map.wall_x * (double)TEX_WIDTH);
	if (graph->ray_x > 0)
		graph->tex_map.wall_x = TEX_WIDTH - graph->tex_map.texX - 1;
	if (graph->ray_y > 0)
		graph->tex_map.wall_x = TEX_WIDTH - graph->tex_map.wall_x - 1;
	graph->tex_map.step = 1.0 * TEX_HEIGHT / graph->wall_height;
	graph->tex_map.text_pos = (graph->higher_px - (HEIGHT / 2)
			+ (graph->wall_height / 2)) * graph->tex_map.step;
	display_wall(graph, x, y, side);
}
