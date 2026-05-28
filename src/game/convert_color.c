/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:27:22 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:27:23 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

int	rgb_to_hexa(int *tab)
{
	int	convert;

	convert = (tab[2] * 1) + (tab[1] * 16 * 16) + (tab[0] * 16 * 16 * 16 * 16);
	return (convert);
}

/*
	un composant a besoin de 8 bits :
	1 chiffre hexa = 4 bits
	4 bits * 2 = 8 bits
	donc decale de puissant de 2 :

	(n * 16^4) + (n * 16^2) + (n * 16^0)
	(n * 65536) + (n * 256) + (n * 1)
	multiplier par des puissance au meme titre
	qu'une base 10 :
	4 * 10^0
	4 * 10^1
	4 * 10^2
	= 444
*/
