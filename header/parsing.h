#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_texture
{
	void				*north_wall;
	void				*south_wall;
	void				*east_wall;
	void				*west_wall;
}						t_tex;

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
	t_tex		tex;
	t_config	config;
}				t_pars;

void			map_load(t_pars *pars);
void			map_copy(t_pars *pars);
void			claim_map(t_pars *pars);
void			file_check(t_pars *pars);

/*
	graph->pars->conf
			   -> texture
*/

#endif

