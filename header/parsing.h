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
	int			pl_pos[2];
	int			file_height;
	int			map_height;
	int			map_width;
	t_config	config;
}				t_pars;

// load

void			map_load(t_pars *pars);
void			config_load(t_pars *pars);

// check

void			file_check(t_pars *pars);
void	        color_validity(char **s, int size);
void			flood_fill(t_pars *pars, int x, int y);

// claim

void    		claim_color(t_pars *pars, int line_nb);
char			*claim_line(char *line);
void			claim_map(t_pars *pars);
void			claim_map_copy(t_pars *pars);

int				find_pl_pos(t_pars *pars);

// debug

void 			print_double_tab(char **s);
void			print_int_tab(int *s);

#endif