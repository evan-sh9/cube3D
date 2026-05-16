#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "gnl.h"
# include "parsing.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pars	t_pars;
typedef struct config	t_config;

// utils

void                    invalid_map();
void                    invalid_file();
void	                comma_check(char *s);
char					*get_next_line(int fd);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strchr(char *s, int c);
char					*ft_substr(char *s, int start, int len);
char					*ft_strdup(char *s);
char					*ft_strcpy(char *s1, char *s2);
char					**ft_split(char const *s, char c);
int						ft_atoi(const char *nptr);
int						ft_strlen(char *s);
int						ft_strncmp(const char *s1, const char *s2, int n);

#endif