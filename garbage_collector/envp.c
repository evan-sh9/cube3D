/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:52:59 by adjelili          #+#    #+#             */
/*   Updated: 2026/02/28 11:02:36 by adjelili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

typedef struct s_env
{
	char *key;
	char *value;
	struct s_env *next;
} t_env;

int main(int argc, char **argv, char **envp)
{
	int y;
	(void)argc;
	(void)argv;
	t_env *env;
	t_env *new;

	env = NULL;
	y = 0;
	while (envp[y])
	{
		new = ft_malloc(1, sizeof(t_env));
		new->key = create_key(envp[y]);
		new->key = ft_strchr(envp[y], '=')
			y++;
	}

	return (0);
}