/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:24:50 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/23 17:57:47 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

static void	*ft_create_string(char *str, int nbchar, long nb)
{
	if (nb < 0)
	{
		str = malloc(sizeof(char) * (nbchar + 2));
	}
	else
	{		
		str = malloc(sizeof(char) * (nbchar + 1));
	}
	return (str);
}

static int	ft_count(long n)
{
	int	count;

	count = 0;
	if (n >= 10 || n <= -10)
	{
		while (n >= 10 || n <= -10)
		{
			n = n / 10;
			count++;
		}
		return (count + 1);
	}
	else
		return (1);
}

static void	ft_fill1(char *str, long nb, int nbchar)
{
	int	y;

	y = 1;
	while (nb != 0)
	{
		str[nbchar - y] = nb % 10 + '0';
		y++;
		nb = nb / 10;
	}
	str[nbchar] = '\0';
}

static void	ft_fill2(char *str, long nb, int nbchar)
{
	int	y;

	y = 1;
	nb = -nb;
	while (nb != 0)
	{
		str[0] = '-';
		str[nbchar +1 - y] = nb % 10 + '0';
		y++;
		nb = nb / 10;
	}
	str[nbchar + 1] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbchar;
	long	nb;

	str = NULL;
	nb = n;
	nbchar = ft_count(nb);
	str = ft_create_string(str, nbchar, nb);
	if (!str)
		return (NULL);
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (nb >= 0)
		ft_fill1(str, nb, nbchar);
	else
		ft_fill2(str, nb, nbchar);
	return (str);
}
