/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_conf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:57:28 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 13:57:29 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

void	n_setting_color_check(t_pars *pars)
{
	if (pars->find_t_var.f > 1)
		invalid_map();
	if (pars->find_t_var.c > 1)
		invalid_map();
}

void	n_setting_color_is_find(t_pars *pars)
{
	if (pars->find_t_var.f < 1)
		invalid_map();
	if (pars->find_t_var.c < 1)
		invalid_map();
}

int	search_color(t_pars *pars, char *line)
{
	if (line[0] == '\0')
		return (-1);
	if (line[0] == 'F' && line[1] == ' ')
	{
		pars->find_t_var.f++;
		return (F);
	}
	if (line[0] == 'C' && line[1] == ' ')
	{
		pars->find_t_var.c++;
		return (C);
	}
	return (-2);
}

void	find_color(t_pars *pars)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	pars->find_t_var.f = 0;
	pars->find_t_var.c = 0;
	while (pars->file_content[i])
	{
		status = search_color(pars, pars->file_content[i]);
		if (status == F)
			claim_color(pars, F, i);
		else if (status == C)
			claim_color(pars, C, i);
		n_setting_color_check(pars);
		if (pars->find_t_var.f == 1 && pars->find_t_var.c == 1)
			break ;
		i++;
	}
	n_setting_color_is_find(pars);
	color_size_validity(pars);
}
