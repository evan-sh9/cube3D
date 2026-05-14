#include "header/cub3D.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
    //t_pars pars;
	t_graphics *graph;

	
	graph = ft_malloc(1, sizeof(t_graphics));

	graph->pos_x = 22.5;
	graph->pos_y = 12.8;

	graph->dir_x = -1.0; // ca pointe vers la gauche de la map 
	graph->dir_y = 0.0;

	graph->plane_x = 0.0;
	graph->plane_y = 0.66;


	graph->mlx = mlx_init();
	graph->window = mlx_new_window(graph->mlx, 2560, 1440, "game");
	mlx_loop(graph->mlx);
    //     return (1);
    // pars.map_file = av[1];
    // map_load(&pars);
    return 0;
}