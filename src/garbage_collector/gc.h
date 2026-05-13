/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:42:25 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/24 12:59:22 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>

typedef struct	s_token
{
	char			*value; // le mot, la commande ou le separateur
	//t_enum			type; // pour l'enum 
	int				flag; // avec le bit shifting pour la priorite des operations
	struct s_token	*next; // le noeud d'apres (liste chainee)
}	t_token;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
t_list	*ft_lstnew(void *content);
void	*ft_malloc(size_t nmemb, size_t size);
void	ft_free_malloc(void *ptr);
void	ft_free_all_malloc(void); // une boucle qui free tout

#endif