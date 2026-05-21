#include "../header/graphics.h"

void load_texture(t_graphics *graph)
{
	int	w;
	int	h;

	graph->pars->tex.north_wall = mlx_xpm_file_to_image(graph->window,
			graph->pars->config.north_texture, &w, &h);
	graph->pars->tex.south_wall = mlx_xpm_file_to_image(graph->window,
			graph->pars->config.south_texture, &w, &h);
    graph->pars->tex.east_wall = mlx_xpm_file_to_image(graph->window,
			graph->pars->config.est_texture, &w, &h);
    graph->pars->tex.west_wall = mlx_xpm_file_to_image(graph->window,
			graph->pars->config.west_texture, &w, &h);
}
