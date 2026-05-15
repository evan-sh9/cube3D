/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:38:30 by adjelili          #+#    #+#             */
/*   Updated: 2026/05/15 17:12:50 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

// int main(void)
// {
// 	t_token *tok = ft_malloc(1, sizeof(t_token));
// 	if (tok)
// 	{
//     	tok->flag = 0;
//     	tok->next = NULL;
// 	}
// 	ft_free_all_malloc();
// }

static	t_list	**return_adress(void)
{
	static t_list	*list;

	return (&list);
}

void	ft_free_all_malloc()
{
	t_list	**list_ptr;
	t_list	*tmp;
	t_list	*next;

	list_ptr = return_adress();
	if (!list_ptr || !*list_ptr)
		exit(EXIT_FAILURE);
	tmp = (*list_ptr);
	while (tmp)
	{
		next = tmp->next;
		tmp->next = NULL;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
		tmp = next;
	}
	(*list_ptr) = NULL;
}

void	ft_free_malloc(void *ptr)
{
	t_list	**head;
	t_list	*prev;
	t_list	*current;

	head = return_adress();
	current = (*head);
	prev = NULL;
	while (current)
	{
		if (current->content == ptr)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->content);
			free(current);
		}
		prev = current;
		current = current->next;
	}
}

void	*ft_malloc(size_t nmemb, size_t size)
{
	t_list	**list_ptr;
	t_list	*new;
	void	*ptr;

	list_ptr = return_adress();
	ptr = ft_calloc(nmemb, size);
	if (!ptr)
	{
		ft_free_all_malloc();
		exit(EXIT_FAILURE);
	}
	new = ft_lstnew(ptr);
	if (!new)
		ft_free_all_malloc();
	ft_lstadd_back(list_ptr, new);
	
	return (ptr);
}
