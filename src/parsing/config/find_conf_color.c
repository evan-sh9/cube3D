#include "../../../header/cub3D.h"

void n_setting_color_check(t_pars *pars)
{
	if (pars->find_t_var.F > 1)
		invalid_map();
	if (pars->find_t_var.C > 1)
		invalid_map();
}

void n_setting_color_is_find(t_pars *pars)
{
	if (pars->find_t_var.F < 1)
		invalid_map();
	if (pars->find_t_var.C < 1)
		invalid_map();
}

int	search_color(t_pars *pars, char *line)
{
	// printf("[DEBUG] line %s\n", line);
    if (line[0] == '\0')
		return (-1);
	if (line[0] == 'F' && line[1] == ' ')
	{
		pars->find_t_var.F++;
		return (F);
	}
	if (line[0] == 'C' && line[1] == ' ')
	{
		pars->find_t_var.C++;
		return (C);
	}
	return (-2);
}

void	find_color(t_pars *pars)
{
	int	i;
	int status;

	i = 0;
	status = 0;
	pars->find_t_var.F = 0;
	pars->find_t_var.C = 0;
	while (pars->file_content[i])
	{
		status = search_color(pars, pars->file_content[i]);
		if (status == F)
			claim_color(pars, F, i);
		else if (status == C)
			claim_color(pars, C, i);
		n_setting_color_check(pars);
		if (pars->find_t_var.F == 1 && pars->find_t_var.C == 1)
            break;
		i++;
	}
	n_setting_color_is_find(pars);
	color_size_validity(pars);
}

/*
void	display(t_graphics *graph, int x, int side)
{
	int	y;
	int	color;
	t_img   *curr_tex;

	y = 0;
	while (y < graph->higher_px)
	{
		my_pixel_put(graph, x, y, 0x333333);
		y++;
	}
	if (side == 1)
		graph->tex_map.wall_x = graph->pos_x + graph->perpWallDist * graph->ray_x;
	else
		graph->tex_map.wall_x = graph->pos_y + graph->perpWallDist * graph->ray_y;
	graph->tex_map.wall_x = claim_decimal(graph->tex_map.wall_x);
	graph->tex_map.texX = (int)(graph->tex_map.wall_x * (double)TEX_WIDTH);
	if (graph->ray_x > 0)
			graph->tex_map.wall_x = TEX_WIDTH - graph->tex_map.texX - 1;
	if (graph->ray_y > 0)
		graph->tex_map.wall_x = TEX_WIDTH - graph->tex_map.wall_x - 1;
	graph->tex_map.step = 1.0 * TEX_HEIGHT / graph->wall_height;
	graph->tex_map.text_pos = (graph->higher_px - (HEIGHT / 2) + (graph->wall_height / 2)) * graph->tex_map.step;
	while (y <= graph->lower_px)
	{
		graph->tex_map.texY = (int)(graph->tex_map.text_pos) & (TEX_HEIGHT - 1);
		graph->tex_map.text_pos += graph->tex_map.step;
		if (side == 1)
		{
			if (graph->step_y == -1) // nord
				curr_tex = &graph->pars->tex.north_wall;
			else	// sud
				curr_tex = &graph->pars->tex.south_wall;
		}
		else
		{
			if (graph->step_x == 1) // est
				curr_tex = &graph->pars->tex.east_wall;
			else	// west
				curr_tex = &graph->pars->tex.west_wall;
		}
		color = *(int *)(curr_tex->img_addr
		+ (graph->tex_map.texY * curr_tex->size_line)
		+ (graph->tex_map.texX * (curr_tex->bits_pp / 8)));
		my_pixel_put(graph, x, y, color);
		y++;
	}
	while (y < HEIGHT)
	{
		my_pixel_put(graph, x, y, 0x666666);
		y++;
	}
}
*/