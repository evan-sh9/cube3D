/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:46:04 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:46:05 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/graphics.h"

void	minimap(t_graphics *graph)
{
	graph->mini_map->width_minimap = (int)(WIDTH * 0.20);
	graph->mini_map->size_square = graph->mini_map->width_minimap / 5;
	graph->mini_map->x_start = (int)(WIDTH * 0.02);
	graph->mini_map->y_start = (int)(HEIGHT * 0.02);
	graph->mini_map->offset_x = -2;
	graph->mini_map->offset_y = -2;
	graph->mini_map->realmap_idx_x = (int)(graph)->pos_x
		+ graph->mini_map->offset_x;
	graph->mini_map->realmap_idx_y = (int)(graph)->pos_y
		+ graph->mini_map->offset_y;
	graph->mini_map->grid_x = graph->mini_map->offset_x + 2;
	graph->mini_map->grid_y = graph->mini_map->offset_y + 2;
	graph->mini_map->x_minimap = graph->mini_map->x_start
		+ (graph->mini_map->grid_x * graph->mini_map->size_square);
	graph->mini_map->y_minimap = graph->mini_map->y_start
		+ (graph->mini_map->grid_y * graph->mini_map->size_square);
	minimap_two(graph);
}

void	minimap_two(t_graphics *graph)
{
	while (graph->mini_map->offset_y <= 2)
	{
		graph->mini_map->offset_x = -2;
		while (graph->mini_map->offset_x <= 2)
		{
			graph->mini_map->realmap_idx_x = (int)(graph)->pos_x
				+ graph->mini_map->offset_x;
			graph->mini_map->realmap_idx_y = (int)(graph)->pos_y
				+ graph->mini_map->offset_y;
			graph->mini_map->grid_x = graph->mini_map->offset_x + 2;
			graph->mini_map->grid_y = graph->mini_map->offset_y + 2;
			graph->mini_map->x_minimap = graph->mini_map->x_start
				+ (graph->mini_map->grid_x * graph->mini_map->size_square);
			graph->mini_map->y_minimap = graph->mini_map->y_start
				+ (graph->mini_map->grid_y * graph->mini_map->size_square);
			draw_minimap(graph);
			graph->mini_map->offset_x++;
		}
		graph->mini_map->offset_y++;
	}
	put_pos(graph);
}

// j'ai la hauteur et la largeur de la map
// l'offset est de -2 pour la hauteur et la largeur
// j'ai besoin des coordonnes de debut et de fin 