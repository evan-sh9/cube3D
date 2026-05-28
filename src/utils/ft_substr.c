/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprieur <eprieur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:01:32 by eprieur           #+#    #+#             */
/*   Updated: 2026/05/28 14:02:36 by eprieur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3D.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*ns;
	int		i;
	int		str_size;

	i = 0;
	if (!s)
		return (NULL);
	str_size = ft_strlen(s);
	if (start >= str_size)
		return (ft_strdup(""));
	if (len + start > str_size)
		len = str_size - start;
	ns = ft_malloc((len + 1), sizeof(char));
	if (!ns)
		return (NULL);
	while (i < len)
	{
		ns[i] = s[start + i];
		i++;
	}
	ns[len] = '\0';
	return (ns);
}
