#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

#define CONFIG_LINE 8

typedef struct config
{
	int			*floor_color;
	int			*celling_floor;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*est_texture;
}				t_config;

typedef struct s_pars
{
	char		**map;			// la carte
	char		**map_copy;		// copy de la carte
	char		**file_content; // tout le contenue du fichier
	char		*map_file;		// le fichie
	int			map_height;
	int			map_width;
	t_config	config;
}				t_pars;

void			map_load(t_pars *pars);
void			map_copy(t_pars *pars);
void    		claim_color(t_pars *pars, int line_nb);
void			config_validity(t_pars *pars);
void			file_check(t_pars *pars);
char			*claim_line(char *line);

#endif