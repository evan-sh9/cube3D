/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:58:47 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 13:58:48 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

void	n_check(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (count_element(s, ' ') != 1)
		invalid_file();
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ')
			invalid_map();
		if (s[i] >= '0' && s[i] <= '9')
			count++;
		i++;
	}
	if (count == 0)
		invalid_map();
}

void	color_size_validity(t_pars *pars)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (pars->config.celling_floor[i] > 255
			|| pars->config.celling_floor[i] < 0)
			invalid_map();
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (pars->config.floor_color[i] > 255
			|| pars->config.floor_color[i] < 0)
			invalid_map();
		i++;
	}
}

void	comma_check(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (j > 2)
			invalid_map();
		if (s[i] == ',')
			j++;
		i++;
	}
}

void	color_validity(char **s, int size)
{
	int	i;

	i = 0;
	if (size != 3)
		invalid_map();
	while (i < size)
	{
		n_check(s[i]);
		i++;
	}
}
