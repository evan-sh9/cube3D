#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

#define CONFIG_LINE 8

typedef struct config
{
	char		*floor_color;
	char		*celling_floor;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*est_texture;
}				t_config;

typedef struct s_pars
{
	char		**map;
	char		**map_copy;
	char		*map_file;
	int			map_height;
	int			map_width;
	t_config	config;
}				t_pars;

void			map_load(t_pars *pars);
void			map_copy(t_pars *pars);
void			map_data(t_pars *pars);
void			file_check(t_pars *pars);

#endif