#include "../../header/graphics.h"

void	put_pos(t_graphics *graph)
{
	int	center_x;
	int	center_y;
	int	p_y;
	int	p_x;

	center_x = graph->mini_map->x_start + (2 * graph->mini_map->size_square)
		+ (graph->mini_map->size_square / 2) - 3;
	center_y = graph->mini_map->y_start + (2 * graph->mini_map->size_square)
		+ (graph->mini_map->size_square / 2) - 3;
	p_y = center_y;
	while (p_y < center_y + 9)
	{
		p_x = center_x;
		while (p_x < center_x + 9)
		{
			my_pixel_put(graph, p_x, p_y, 0xFF0000);
			p_x++;
		}
		p_y++;
	}
}

void	draw_outside_map(t_graphics *graph, int x, int y, int size)
{
	int	old_x;
	int	old_y;

	old_x = x;
	old_y = y;
	while (y < old_y + size)
	{
		x = old_x;
		while (x < old_x + size)
		{
			my_pixel_put(graph, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_graphics *graph, int x, int y, int size)
{
	int	old_x;
	int	old_y;

	old_x = x;
	old_y = y;
	while (y < old_y + size)
	{
		x = old_x;
		while (x < old_x + size)
		{
			my_pixel_put(graph, x, y, 0xD3D3D3);
			x++;
		}
		y++;
	}
}

void	draw_walls_minimap(t_graphics *graph, int x, int y, int size)
{
	int	old_x;
	int	old_y;

	old_x = x;
	old_y = y;
	while (y < old_y + size)
	{
		x = old_x;
		while (x < old_x + size)
		{
			my_pixel_put(graph, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_graphics *graph)
{
	if (graph->mini_map->realmap_idx_x < 0 || graph->mini_map->realmap_idx_y
		< 0 || graph->mini_map->realmap_idx_x
		> ft_strlen(graph->pars->map[graph->mini_map->realmap_idx_y]))
		draw_outside_map(graph, graph->mini_map->x_minimap,
			graph->mini_map->y_minimap, graph->mini_map->size_square);
	else if (graph->pars->map[graph->mini_map->realmap_idx_y]
		[graph->mini_map->realmap_idx_x]
		&& (graph->pars->map[graph->mini_map->realmap_idx_y]
			[graph->mini_map->realmap_idx_x]
			== '0' || graph->pars->map[graph->mini_map->realmap_idx_y]
			[graph->mini_map->realmap_idx_x] == 'N'
			|| graph->pars->map[graph->mini_map->realmap_idx_y]
			[graph->mini_map->realmap_idx_x] == 'E'
			|| graph->pars->map[graph->mini_map->realmap_idx_y]
			[graph->mini_map->realmap_idx_x] == 'S'
			|| graph->pars->map[graph->mini_map->realmap_idx_y]
			[graph->mini_map->realmap_idx_x] == 'W'))
		draw_floor(graph, graph->mini_map->x_minimap,
			graph->mini_map->y_minimap, graph->mini_map->size_square);
	else
		draw_walls_minimap(graph, graph->mini_map->x_minimap,
			graph->mini_map->y_minimap, graph->mini_map->size_square);
}
