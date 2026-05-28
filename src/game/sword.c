/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sword.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:47:03 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:47:04 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/graphics.h"

static void	put_sword3(t_graphics **graph)
{
	if ((*graph)->sword->x >= WIDTH)
		return ;
	(*graph)->sword->relative_x = (*graph)->sword->x - (*graph)->sword->start_x;
	(*graph)->sword->tex_x = (int)((double)(*graph)->sword->relative_x * (64.0
				/ (double)(*graph)->width_sword));
	(*graph)->sword->ptr = (*graph)->sword_addr + ((*graph)->sword->tex_y
			* (*graph)->sword_line_size + (*graph)->sword->tex_x
			* ((*graph)->sword_pixel / 8));
	(*graph)->sword->color = *(unsigned int *)(*graph)->sword->ptr;
	if ((*graph)->sword->color != 0x000000)
		my_pixel_put(*graph, (*graph)->sword->x, (*graph)->sword->y,
			(*graph)->sword->color);
}

static void	put_sword2(t_graphics **graph)
{
	(*graph)->sword->relative_y = (*graph)->sword->y - (*graph)->sword->start_y;
	(*graph)->sword->tex_y = (int)((double)(*graph)->sword->relative_y * (64.0
				/ (double)(*graph)->height_sword));
	(*graph)->sword->x = ((WIDTH / 2) - ((*graph)->width_sword / 2))
		+ (int)(WIDTH * 0.15);
	(*graph)->sword->start_x = (*graph)->sword->x;
	while ((*graph)->sword->x < (*graph)->sword->start_x
		+ (*graph)->width_sword)
	{
		put_sword3(graph);
		(*graph)->sword->x++;
	}
}

void	put_sword(t_graphics **graph)
{
	(*graph)->sword->y = HEIGHT - (int)((*graph)->height_sword * 0.60);
	(*graph)->sword->start_y = (*graph)->sword->y;
	while ((*graph)->sword->y < HEIGHT)
	{
		put_sword2(graph);
		(*graph)->sword->y++;
	}
}

int	hit_wall_next(t_graphics *graph, int map_x, int map_y)
{
	if (map_y < 0 || map_y >= graph->pars->map_height || map_x < 0
		|| map_x >= ft_strlen(graph->pars->map[map_y])
		|| graph->pars->map[map_y][map_x] == ' '
		|| graph->pars->map[map_y][map_x] == '1')
		return (1);
	return (0);
}
