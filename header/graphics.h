#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WIDTH 1160
# define HEIGHT 820
# define TEX_WIDTH 16
# define TEX_HEIGHT 16
# define FLECHE_G 65363
# define FLECHE_D 65361
# define W_AVANT 119
# define A_GAUCHE 97
# define S_ARRIERE 115
# define D_DROITE 100
# define SPEED 5.0
# define ROT_SPEED 4.0


#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include "parsing.h"
#include <math.h>
#include "../src/garbage_collector/gc.h"
#include <stdlib.h>
#include <sys/time.h>
typedef struct s_mini_map t_mini_map;

typedef struct s_texture_mapping
{
	double	wall_x;
	double	wall_y;
	double	text_pos;
	double	step;
	int		texX;
	int		texY;
}		t_texture_mapping;


/*

    int texX = int(wallX * double(texWidth));
    if(side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
    if(side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

 */

typedef struct s_graphics
{
	int		rotate_droite;
	int		rotate_gauche;
	int		avancer;
	int		reculer;
	int		a_droite;
	int		a_gauche;
	double	pos_x; // position x du joueur
	double	pos_y; // position y du joueur
	double	dir_x; // direction y du joueur (vecteur de direction)
	double	dir_y; // direction y du joueur (vecteur de direction)
	double	plane_x; // le plan x
	double	plane_y; // le plan y
	double	delta_time;
	double	old_time;
	double	time_now;
	double	ray_x; // le rayon qu'on calcule pour chaque camera_x (pour chaque colonne de l'ecran)
	double	ray_y; // pareil mais en y
	double	camera_x; 
	double	map_x; // la case sur laquelle se trouve le joueur
	double	map_y; // pareil mais en y
	double	delta_x; // la distance que doit parcourir un vecteur pour traverser une case
	double	delta_y; // pareil mais en y
	int		step_x;
	int		step_y;
	double	side_x; // la distcance que doit parcourir le rayon pour atteindre la prochaine case a partir de la 
	double	side_y; // pareil mais en y
	double	perpWallDist; // la distcance qu'on va utiliser pour eviter le fisheye effect
	double	wall_height; // la taille du mur apres avoir calcule la distance avec perpwall
	double	higher_px; // les coordonnes du pixel du haut
	double	lower_px; // les coordonnes des pixels du bas
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	char	**map;
	int		bits_per_px; // la taille de chaque pixel en octets, vu que chaque pixel est en rgba on a 4 int de 8 bits donc 32bits par pixel
	int		line_size; // la taille d'une ligne en byte
	int		endian;
	t_pars	*pars;
	t_texture_mapping tex_map;
	double	angle;
	void	*sword_img;
	void	*sword_addr;
	int		sword_pixel;
	int		sword_line_size;
	int		sword_endian;
	double	height_sword;
	double	width_sword;
	t_mini_map	*mini_map;
} t_graphics;

typedef struct s_mini_map
{
	int		start_x;
	int		start_y;
	int		height;
	int		width;
	double	pos_plyr_x; // le joueur sera tout le temps au millieu de la map
	double	pos_plyr_y;
	int		component_height; // la hauter de chaque carre de la map
	int		component_width; // la largeur de chaque element de la map
} t_mini_map;

void		algo(t_graphics **graph);
t_graphics	*dda(double ray_x, double ray_y, t_graphics *graph, int x);
double		ft_abs(double num);
void		my_pixel_put(t_graphics *graph, int x, int y, int color);
void		ft_exit(t_graphics *graph);
void		mouv(int keycode, t_graphics **graph);
void		stop_mouv(int keycode, t_graphics **graph);
t_graphics	*init_data(t_pars *parse);
void		load_texture(t_graphics *graph);
void		game(t_graphics **graph);
void		to_left(t_graphics **graph);
void		to_right(t_graphics **graph);
void		up(t_graphics **graph);
void		down(t_graphics **graph);
void		right(t_graphics **graph);
void		left(t_graphics **graph);
double		get_time_of_day_ms(void);
void		display(t_graphics *graph, int x, int side);
int			hit_wall(t_graphics *graph);
void		set_delta(t_graphics *graph, double ray_x, double ray_y);
void		set_side_step(t_graphics *graph, double ray_x, double ray_y);
void		*get_addr_img(void *mlx_ptr, char *filename);
void		*get_addr_sword(t_graphics *graph);
void		put_sword(t_graphics **graph);
void		minimap(t_graphics *graph);

#endif

/*

for(int y = drawStart; y<drawEnd; y++)
{
	// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
	int texY = (int)texPos & (texHeight - 1);
	texPos += step;
	Uint32 color = texture[texNum][texWidth * texY + texX];
	//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
	if(side == 1) color = (color >> 1) & 8355711;
	buffer[y][x] = color;
      }

*/