/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:58:02 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 13:58:04 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3D.h"

int	xpm_check(char *s)
{
	int	start;
	int	size;

	size = ft_strlen(s);
	start = size - 4;
	if (size <= 4)
		invalid_file();
	if (ft_strncmp(s + start, ".xpm", 4) != 0)
		return (1);
	return (0);
}

void	path_join(t_pars *pars)
{
	char	**tmp;

	if (count_element(pars->config.north_texture, ' ') > 1)
		invalid_map();
	if (count_element(pars->config.east_texture, ' ') > 1)
		invalid_map();
	if (count_element(pars->config.west_texture, ' ') > 1)
		invalid_map();
	if (count_element(pars->config.east_texture, ' ') > 1)
		invalid_map();
	tmp = ft_split(pars->config.north_texture, ' ');
	pars->config.north_texture = tmp[0];
	tmp = ft_split(pars->config.east_texture, ' ');
	pars->config.east_texture = tmp[0];
	tmp = ft_split(pars->config.west_texture, ' ');
	pars->config.west_texture = tmp[0];
	tmp = ft_split(pars->config.east_texture, ' ');
	pars->config.east_texture = tmp[0];
}

void	path_check(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		invalid_map();
	close(fd);
}

void	texture_check(t_pars *pars)
{
	path_join(pars);
	xpm_check(pars->config.north_texture);
	path_check(pars->config.north_texture);
	xpm_check(pars->config.south_texture);
	path_check(pars->config.south_texture);
	xpm_check(pars->config.west_texture);
	path_check(pars->config.west_texture);
	xpm_check(pars->config.east_texture);
	path_check(pars->config.east_texture);
}
