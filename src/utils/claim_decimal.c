/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claim_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:00:38 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:00:42 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

double	claim_decimal(double n)
{
	double	integer;
	double	dec;

	dec = modf(n, &integer);
	return (dec);
}
