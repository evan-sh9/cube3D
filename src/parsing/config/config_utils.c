/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:57:18 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 13:57:19 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

void	n_setting_check(t_pars *pars)
{
	if (pars->find_t_var.no > 1)
		invalid_map();
	if (pars->find_t_var.so > 1)
		invalid_map();
	if (pars->find_t_var.we > 1)
		invalid_map();
	if (pars->find_t_var.ea > 1)
		invalid_map();
}

void	n_setting_is_find(t_pars *pars)
{
	if (pars->find_t_var.no < 1)
		invalid_map();
	if (pars->find_t_var.so < 1)
		invalid_map();
	if (pars->find_t_var.we < 1)
		invalid_map();
	if (pars->find_t_var.ea < 1)
		invalid_map();
}
