#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "parsing.h"
#include "gnl.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_pars t_pars;

// utils

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
char	*ft_strcpy(char *s1, char *s2);

#endif