#ifndef PARSING_H
#define PARSING_H

# include <stdio.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_pars
{
	char				**map;
	char				**map_copy;
	char				*map_file;
	int					map_height;
	int					map_width;

}						t_pars;

void	map_load(t_pars *pars);
void	map_copy(t_pars *pars);
void	claim_map(t_pars *pars);

#endif