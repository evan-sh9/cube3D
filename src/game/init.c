/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:46:11 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:46:12 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/graphics.h"

static void	mlx_init_game(t_graphics *graph)
{
	graph->mlx = mlx_init();
	graph->window = mlx_new_window(graph->mlx, WIDTH, HEIGHT, "game");
	graph->img = mlx_new_image(graph->mlx, WIDTH, HEIGHT);
	graph->addr = mlx_get_data_addr(graph->img, &graph->bits_per_px,
			&graph->line_size, &graph->endian);
	graph->sword_img = get_addr_img(graph->mlx, "textures/diamond_sword.xpm");
	graph->sword_addr = get_addr_sword(graph);
}

t_graphics	*init_data(t_pars *parse)
{
	t_graphics	*graph;

	graph = ft_malloc(1, sizeof(t_graphics));
	graph->pars = parse;
	graph->pos_x = parse->pl_pos[1];
	graph->pos_y = parse->pl_pos[0];
	dir_spawn(graph);
	graph->camera_x = 0;
	graph->step_x = 0;
	graph->step_y = 0;
	mlx_init_game(graph);
	graph->height_sword = HEIGHT * 0.30;
	graph->width_sword = graph->height_sword * (64.0 / 64.0);
	graph->time_now = get_time_of_day_ms();
	load_texture(graph);
	graph->mini_map = ft_malloc(1, sizeof(t_mini_map));
	map_dimensions(graph);
	graph->sword = ft_malloc(1, sizeof(t_sword));
	return (graph);
}

static void	dir_spawn2(t_graphics *graph)
{
	if (graph->pars->map[(int)graph->pars->pl_pos[0]]
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
	else
		dir_spawn2(graph);
}
