#include "header/cub3D.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_pars pars = {0};
	t_graphics *graph;

	if (ac != 2)
		return (1);
	pars.map_file = av[1];
	map_load(&pars);
	graph = init_data(&pars);
	mlx_hook(graph->window, 2, 1L << 0, (void *)mouv, &graph);
	mlx_hook(graph->window, 3, 1L << 1, (void *)stop_mouv, &graph);
	mlx_hook(graph->window, 17, 0, (void *)ft_exit, graph);
	mlx_loop_hook(graph->mlx, (void *)game, &graph);
	mlx_loop(graph->mlx);
	ft_free_all_malloc();
	return (0);
}
