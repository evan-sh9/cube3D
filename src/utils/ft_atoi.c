/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:00:52 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:02:13 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	exit_atoi(void)
{
	ft_free_all_malloc();
	printf("Error : Invalid size\n");
	exit(EXIT_FAILURE);
}

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		c;
	long	nb;

	i = 0;
	c = 1;
	nb = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			c = -c;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		exit_atoi();
	return (nb * c);
}
