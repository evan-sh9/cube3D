/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:45:55 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:45:56 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/graphics.h"

void	ft_exit(t_graphics *graph)
{
	mlx_destroy_image(graph->mlx, graph->pars->tex.north_wall.img);
	mlx_destroy_image(graph->mlx, graph->pars->tex.south_wall.img);
	mlx_destroy_image(graph->mlx, graph->pars->tex.east_wall.img);
	mlx_destroy_image(graph->mlx, graph->pars->tex.west_wall.img);
	mlx_destroy_image(graph->mlx, graph->sword_img);
	mlx_destroy_image(graph->mlx, graph->img);
	mlx_destroy_window(graph->mlx, graph->window);
	mlx_destroy_display(graph->mlx);
	free(graph->mlx);
	ft_free_all_malloc();
	exit(EXIT_SUCCESS);
}

void	mouv(int keycode, t_graphics **graph)
{
	if (keycode == 65307)
		ft_exit(*graph);
	else if (keycode == FLECHE_G)
		(*graph)->rotate_gauche = 1;
	else if (keycode == FLECHE_D)
		(*graph)->rotate_droite = 1;
	else if (keycode == W_AVANT)
		(*graph)->avancer = 1;
	else if (keycode == A_GAUCHE)
		(*graph)->a_gauche = 1;
	else if (keycode == S_ARRIERE)
		(*graph)->reculer = 1;
	else if (keycode == D_DROITE)
		(*graph)->a_droite = 1;
}

void	stop_mouv(int keycode, t_graphics **graph)
{
	if (keycode == FLECHE_G)
		(*graph)->rotate_gauche = 0;
	else if (keycode == FLECHE_D)
		(*graph)->rotate_droite = 0;
	else if (keycode == W_AVANT)
		(*graph)->avancer = 0;
	else if (keycode == A_GAUCHE)
		(*graph)->a_gauche = 0;
	else if (keycode == S_ARRIERE)
		(*graph)->reculer = 0;
	else if (keycode == D_DROITE)
		(*graph)->a_droite = 0;
}
