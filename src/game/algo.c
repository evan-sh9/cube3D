#include "../../header/graphics.h"

void	algo(t_graphics **graph)
{
	int	x; // pour la boucle pour faire toutes les colonnes de pixel de l'ecran

	x = 0;
	while (x < WIDTH)
	{
		(*graph)->camera_x = 2 * x / (double)WIDTH - 1;
		(*graph)->ray_x = (*graph)->dir_x + (*graph)->plane_x * (*graph)->camera_x;
		(*graph)->ray_y = (*graph)->dir_y + (*graph)->plane_y * (*graph)->camera_x;
		*graph = dda((*graph)->ray_x, (*graph)->ray_y, *graph, x);
		x++;
	}
	mlx_put_image_to_window((*graph)->mlx, (*graph)->window, (*graph)->img, 0, 0);
}

double	ft_abs(double num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

t_graphics	*dda(double ray_x, double ray_y, t_graphics *graph, int x)
{
	int hit;

	hit = 0;
	int side;
	graph->map_x = (int)graph->pos_x; // on arrondit la position a la case sur laquelle on se trouve
	graph->map_y = (int)graph->pos_y;
	
	
	if (ray_x != 0) // si le rayon est == 0 ca veut dire que le delta est tellement grand que le vecteur ne croisera jamais un mur en x car il est en aprallele
		graph->delta_x = ft_abs(1 / ray_x); // on calcule la distance que chque rayon doit traverser pour atteindre le prochain mur
	else
		graph->delta_x = 1e30;
	if (ray_y != 0) // pareil si le y = 0 c'est qu'il ne touchera jamais un mur en y car il est en parallele
		graph->delta_y = ft_abs(1 / ray_y);
	else
		graph->delta_y = 1e30;
	
	if (ray_x < 0) // si le rayon est negatif c'est que les steps qu'on fait sont en negatif car on va a gauche donc on va soustraire le step pour aller a gauche
	{
		graph->step_x = -1;
		graph->side_x = (graph->pos_x - graph->map_x) * graph->delta_x;
	}
	else // sinon c'est positif
	{
		graph->step_x = 1;
		graph->side_x = (graph->map_x + 1.0 - graph->pos_x) * graph->delta_x;
	}
	if (ray_y < 0) // pareil mais pour le y
	{
		graph->step_y = -1;
		graph->side_y = (graph->pos_y - graph->map_y) * graph->delta_y;
	}
	else
	{
		graph->step_y = 1;
		graph->side_y = (graph->map_y + 1.0 - graph->pos_y) * graph->delta_y;
	}


	while (hit == 0) // tant qu'on a pas toucher de mur on fait avancer
	{
		if (graph->side_x < graph->side_y) // si la longeur de du y est plus grande que celle du x on fait avancer le x (en gros on fait avancer le plus petit a chaque fois)
		{
			graph->side_x += graph->delta_x;
			graph->map_x += graph->step_x;
			side = 0;
		}
		else // pareil mais pour le x
		{
			graph->side_y += graph->delta_y;
			graph->map_y += graph->step_y;
			side = 1;
		}
		if (graph->map[(int)graph->map_y][(int)graph->map_x] == '1') // on check si on a touche un mur 
			hit = 1;
	}

	// une fois qu'on a trouve un mur il faut qu'on calcule sa perp distance pour eviter le fisheye effect
	if (side == 0) // side = 0 veut dire que le rayon a touche une ligne verticale en dernier et que le mur est oriente est ou ouest
		graph->perpWallDist = (graph->side_x - graph->delta_x);
	else // side != 0 veut dire qu'il a touche une ligne horizontale et que le mur est oriente nord ou sud
		graph->perpWallDist = (graph->side_y - graph->delta_y);
		
	graph->wall_height = (int)(HEIGHT / graph->perpWallDist); // pour calculer la hauteur du mur a afficher on divise la hauteur de la fenetre par la distance du mur 
	graph->higher_px = - graph->wall_height / 2 + HEIGHT / 2; // on calcule la position du pixel du haut 
	if (graph->higher_px < 0)
		graph->higher_px = 0;
	graph->lower_px = graph->wall_height / 2 + HEIGHT / 2; // pareil pour le pixel du bas
	if (graph->lower_px >= HEIGHT)
		graph->lower_px = HEIGHT - 1;
	
	int y;
	y = 0; // ensuite on affiche
	while (y < graph->higher_px)
	{
		my_pixel_put(graph, x, y, 0x333333);
		y++;
	}
	while (y <= graph->lower_px)
	{
		int color = 0xFF0000;
		if (side == 1)
			color = color / 2;
		my_pixel_put(graph, x, y, color);
		y++;
	}
	while (y < HEIGHT)
	{
		my_pixel_put(graph, x, y, 0x666666);
		y++;
	}
	return (graph);
}

void	my_pixel_put(t_graphics *graph, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = graph->addr + (y * graph->line_size + x * (graph->bits_per_px / 8));
	*(unsigned int*)dst = color;
}
