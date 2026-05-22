#ifndef PARSING_H
# define PARSING_H

# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>

enum				texture
{
	NO,
	SO,
	WE,
	EA,
};

enum				color
{
	F,
	C
};

typedef struct s_find_texture
{
	int				NO;
	int				SO;
	int				WE;
	int				EA;
	int				F;
	int				C;
}					t_find_texture;

typedef	struct s_img
{
	void				*img;
	void				*img_addr;
	int					bits_pp;
	int 				size_line;
	int					endian;
} t_img;


typedef struct s_texture
{
    t_img               north_wall;
    t_img               south_wall;
    t_img               east_wall;
    t_img               west_wall;
}                        t_tex;

typedef struct config
{
	int				*floor_color;
	int				*celling_floor;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
}					t_config;

typedef struct s_pars
{
	char			**map;
	char 			**map_copy;
	char 			**file_content;
	char 			*map_file;
	double			pl_pos[2];
	int				file_height;
	int				conf_height;
	int				map_height;
	int				map_width;
	int				spawn_count;
    t_tex			tex;
    t_config		config;
	t_find_texture	find_t_var;
}					t_pars;

// load

void				map_load(t_pars *pars);
void				config_load(t_pars *pars);

// check

void				file_check(t_pars *pars);
void				color_validity(char **s, int size);
void				flood_fill(t_pars *pars, int x, int y);
void				spawn_checker(t_pars *pars);
void				texture_check(t_pars *pars);

// claim

void				claim_color(t_pars *pars, int status, int line);
char				*claim_line(char *line);
void				claim_map(t_pars *pars);
void				claim_map_copy(t_pars *pars);

int					find_pl_pos(t_pars *pars);

// other

void				find_color(t_pars *pars);

// debug

void				print_double_tab(char **s);
void				print_int_tab(int *s);


int					search_color(t_pars *pars, char *line);
void 				n_setting_check(t_pars *pars);
void 				n_setting_is_find(t_pars *pars);

#endif