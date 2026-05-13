/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:48:53 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/24 13:59:19 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*ptr;

	if ((*lst) == NULL)
		*lst = new_node;
	else
	{
		ptr = *lst;
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = new_node;
	}
}
