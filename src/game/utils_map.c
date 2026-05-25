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
	printf("la largeur de la map est %d\n et la hauteur de la map est %d\n", graph->map_width, graph->map_height);
	return ;
}
