#include "header/cub3D.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
    //t_pars pars;
	t_graphics *graph;
	
	graph = ft_malloc(1, sizeof(t_graphics));

	graph->map = ft_malloc(1, sizeof(char *) * 25); // 24 lignes + NULL
    graph->map[0]  = ft_strdup("111111111111111111111111");
    graph->map[1]  = ft_strdup("100000000000000000000001");
    graph->map[2]  = ft_strdup("100000000000000000000001");
    graph->map[3]  = ft_strdup("100000000000000000000001");
    graph->map[4]  = ft_strdup("100011111000000000000001");
    graph->map[5]  = ft_strdup("100010001000000000000001");
    graph->map[6]  = ft_strdup("100010001000000000000001");
    graph->map[7]  = ft_strdup("100011011000000000000001");
    graph->map[8]  = ft_strdup("100000000000000000000001");
    graph->map[9]  = ft_strdup("100000000000000000000001");
    graph->map[10] = ft_strdup("100000000000000000000001");
    graph->map[11] = ft_strdup("100000000000000000000001");
    graph->map[12] = ft_strdup("100000000000000000000001"); // Joueur à y=12.8
    graph->map[13] = ft_strdup("100000000000000000000001");
    graph->map[14] = ft_strdup("100000000000000000000001");
    graph->map[15] = ft_strdup("100000000000000000000001");
    graph->map[16] = ft_strdup("111111111000000000000001");
    graph->map[17] = ft_strdup("100000001000000000000001");
    graph->map[18] = ft_strdup("100000001000000000000001");
    graph->map[19] = ft_strdup("100000001000000000000001");
    graph->map[20] = ft_strdup("100000001000000000000001");
    graph->map[21] = ft_strdup("100000001000000000000001");
    graph->map[22] = ft_strdup("100000000000000000000001"); // Joueur à x=22.5
    graph->map[23] = ft_strdup("111111111111111111111111");
    graph->map[24] = NULL;
	graph->pos_x = 11.1;
	graph->pos_y = 12.0;

	graph->dir_x = -1.0; // ca pointe vers la gauche de la map 
	graph->dir_y = 0.0;

	graph->plane_x = 0.0;
	graph->plane_y = 0.66;
	graph->camera_x = 0;
	graph->step_x = 0;
	graph->step_y = 0;
	graph->mlx = mlx_init();
	graph->window = mlx_new_window(graph->mlx, WIDTH, HEIGHT, "game");
	graph->img = mlx_new_image(graph->mlx, WIDTH, HEIGHT);
	graph->addr = mlx_get_data_addr(graph->img, &graph->bits_per_px, &graph->line_size, &graph->endian);
	gettimeofday(&graph->time_now_struct, NULL);
	algo(&graph);
	mlx_hook(graph->window, 2, 1L<<0, (void *)mouv, &graph);
	mlx_hook(graph->window, 3, 1L<<1, (void *)stop_mouv, &graph);
	mlx_hook(graph->window, 17, 0, (void *)ft_exit, graph);
	mlx_loop_hook(graph->mlx, (void *)game, &graph);
	mlx_loop(graph->mlx);
    //     return (1);
    // pars.map_file = av[1];
    // map_load(&pars);
    return 0;
}

	// double	new_y;

	// new_y = (*graph)->pos_y - 0.07;
	// if (new_y < 0)
	// 	return ;
	// if ((*graph)->map[(int)new_y][(int)(*graph)->pos_x] && (*graph)->map[(int)new_y][(int)(*graph)->pos_x] != '1')
	// {
	// 	(*graph)->pos_y = new_y;
	// 	algo(graph);
	// }
	// return ;