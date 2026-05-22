#include "header/cub3D.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_pars 		pars;
	t_graphics *graph;

	if (ac != 2)
		return (1);
	pars.map_file = av[1];
	map_load(&pars);
	graph = ft_malloc(1, sizeof(t_graphics));
	graph->pars = &pars;
	graph->pos_x = pars.pl_pos[0];
	graph->pos_y = pars.pl_pos[1];
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
	graph->addr = mlx_get_data_addr(graph->img, &graph->bits_per_px,
			&graph->line_size, &graph->endian);
	graph->sword_img = get_addr_img(graph->mlx, "/home/adjelili/Desktop/M4/cube3D/textures/diamond_sword.xpm");
	graph->sword_addr = get_addr_sword(graph);
	printf("%p %p\n", graph->sword_addr, graph->sword_img);
	graph->height_sword = HEIGHT * 0.30;
	graph->width_sword = graph->height_sword * (64.0 / 64.0);
	graph->time_now = get_time_of_day_ms();
	mlx_hook(graph->window, 2, 1L << 0, (void *)mouv, &graph);
	mlx_hook(graph->window, 3, 1L << 1, (void *)stop_mouv, &graph);
	mlx_hook(graph->window, 17, 0, (void *)ft_exit, graph);
	mlx_loop_hook(graph->mlx, (void *)game, &graph);
	mlx_loop(graph->mlx);
	return (0);
}
