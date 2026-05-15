#include "header/cub3D.h"

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
    //t_pars pars;
	t_graphics *graph;

	// char **test_map;

    // test_map = ft_malloc(1, sizeof(char *) * 6);
    // if (!test_map)
    //     return 1;
    // test_map[0] = ft_strdup("111111");
    // test_map[1] = ft_strdup("100001");
    // test_map[2] = ft_strdup("101001");
    // test_map[3] = ft_strdup("100001");
    // test_map[4] = ft_strdup("111111");
    // test_map[5] = NULL;
	
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
	graph->window = mlx_new_window(graph->mlx, 2560, 1440, "game");
	algo(&graph);
	mlx_loop(graph->mlx);
    //     return (1);
    // pars.map_file = av[1];
    // map_load(&pars);
    return 0;
}