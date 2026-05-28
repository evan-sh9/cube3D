/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:00:47 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:02:01 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

void	invalid_map(void)
{
	ft_free_all_malloc();
	printf("Error \nInvalid map format\n");
	exit(EXIT_FAILURE);
}

void	invalid_file(void)
{
	ft_free_all_malloc();
	printf("Error \nInvalid file\n");
	exit(EXIT_FAILURE);
}
