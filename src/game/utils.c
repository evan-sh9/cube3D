/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:47:31 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:47:32 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/graphics.h"

double	get_time_of_day_ms(void)
{
	struct timeval	start;
	double			return_value;

	gettimeofday(&start, NULL);
	return_value = ((start.tv_sec) + ((double)start.tv_usec / 1000000.0));
	return (return_value);
}

void	my_pixel_put(t_graphics *graph, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = graph->addr + (y * graph->line_size + x * (graph->bits_per_px / 8));
	*(unsigned int *)dst = color;
}

double	ft_abs(double num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void	*get_addr_img(void *mlx_ptr, char *filename)
{
	int		h;
	int		l;
	void	*ptr;

	ptr = mlx_xpm_file_to_image(mlx_ptr, filename, &h, &l);
	if (!ptr)
	{
		ft_free_all_malloc();
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	*get_addr_sword(t_graphics *graph)
{
	void	*ptr;

	ptr = mlx_get_data_addr(graph->sword_img, &graph->sword_pixel,
			&graph->sword_line_size, &graph->sword_endian);
	return (ptr);
}
