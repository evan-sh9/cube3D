/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:01:48 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:01:49 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3D.h"

void	load_next_texture(t_graphics *graph)
{
	int	w;
	int	h;

	graph->pars->tex.east_wall.img = mlx_xpm_file_to_image(graph->mlx,
			graph->pars->config.east_texture, &w, &h);
	graph->pars->tex.east_wall.img_addr = mlx_get_data_addr(graph->pars->tex.east_wall.img,
			&graph->pars->tex.east_wall.bits_pp,
			&graph->pars->tex.east_wall.size_line,
			&graph->pars->tex.east_wall.endian);
	graph->pars->tex.west_wall.img = mlx_xpm_file_to_image(graph->mlx,
			graph->pars->config.west_texture, &w, &h);
	graph->pars->tex.west_wall.img_addr = mlx_get_data_addr(graph->pars->tex.west_wall.img,
			&graph->pars->tex.west_wall.bits_pp,
			&graph->pars->tex.west_wall.size_line,
			&graph->pars->tex.west_wall.endian);
}

void	load_texture(t_graphics *graph)
{
	int	w;
	int	h;

	graph->pars->tex.north_wall.img = mlx_xpm_file_to_image(graph->mlx,
			graph->pars->config.north_texture, &w, &h);
	graph->pars->tex.north_wall.img_addr = mlx_get_data_addr(graph->pars->tex.north_wall.img,
			&graph->pars->tex.north_wall.bits_pp,
			&graph->pars->tex.north_wall.size_line,
			&graph->pars->tex.north_wall.endian);
	graph->pars->tex.south_wall.img = mlx_xpm_file_to_image(graph->mlx,
			graph->pars->config.south_texture, &w, &h);
	graph->pars->tex.south_wall.img_addr = mlx_get_data_addr(graph->pars->tex.south_wall.img,
			&graph->pars->tex.south_wall.bits_pp,
			&graph->pars->tex.south_wall.size_line,
			&graph->pars->tex.south_wall.endian);
	load_next_texture(graph);
}
