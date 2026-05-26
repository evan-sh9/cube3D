#include "../../header/graphics.h"

t_graphics	*init_data(t_pars *parse)
{
	t_graphics	*graph;

	graph = ft_malloc(1, sizeof(t_graphics));
	graph->pos_x = 11.1;
	graph->pos_y = 12.0;
	graph->dir_x = -1.0;
	graph->dir_y = 0.0;
	graph->plane_x = 0.0;
	graph->plane_y = 0.66;
	graph->camera_x = 0;
	graph->step_x = 0;
	graph->step_y = 0;
	graph->mlx = mlx_init();
	graph->window = mlx_new_window(graph->mlx, WIDTH, HEIGHT, "game");
	graph->img = mlx_new_image(graph->mlx, WIDTH, HEIGHT);
	graph->addr = mlx_get_data_addr(graph->img,
			&graph->bits_per_px, &graph->line_size, &graph->endian);
	graph->pars = parse;
	graph->sword_img = get_addr_img(graph->mlx, "textures/diamond_sword.xpm");
	graph->height_sword = HEIGHT * 0.30;
	graph->width_sword = graph->height_sword * (64.0 / 64.0);
	return (graph);
}

void	dir_spawn(t_graphics *graph)
{
	if (graph->pars->map[(int)graph->pars->pl_pos[0]]
		[(int)graph->pars->pl_pos[1]] == 'N')
	{
		graph->dir_x = 0.0;
		graph->dir_y = -1.0;
		graph->plane_x = 0.66;
		graph->plane_y = 0;
	}
	else if (graph->pars->map[(int)graph->pars->pl_pos[0]]
		[(int)graph->pars->pl_pos[1]] == 'E')
	{
		graph->dir_x = 1.0;
		graph->dir_y = 0.0;
		graph->plane_x = 0;
		graph->plane_y = 0.66;
	}
	else if (graph->pars->map[(int)graph->pars->pl_pos[0]]
		[(int)graph->pars->pl_pos[1]] == 'S')
	{
		graph->dir_x = 0.0;
		graph->dir_y = 1.0;
		graph->plane_x = 0.66;
		graph->plane_y = 0;
	}
	else if (graph->pars->map[(int)graph->pars->pl_pos[0]]
		[(int)graph->pars->pl_pos[1]] == 'W')
	{
		graph->dir_x = -1.0;
		graph->dir_y = 0.0;
		graph->plane_x = 0;
		graph->plane_y = 0.66;
	}
}
