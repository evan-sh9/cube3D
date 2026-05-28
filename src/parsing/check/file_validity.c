/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:58:43 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 13:59:40 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

int	extention_check(char *s)
{
	int	start;
	int	size;

	size = ft_strlen(s);
	start = size - 4;
	if (size <= 4)
		invalid_file();
	if (ft_strncmp(s + start, ".cub", 4) != 0)
		return (1);
	return (0);
}

void	file_check(t_pars *pars)
{
	if (ft_strlen(pars->map_file) <= 4)
		invalid_file();
	if (extention_check(pars->map_file))
		invalid_file();
}
