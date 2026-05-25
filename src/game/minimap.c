#include "../../header/graphics.h"

void	draw_minimap(int x_de_chaque_carre, int	y_de_chaque_carre, t_graphics *graph, int taille_de_chaque_case, int check_x, int check_y);

void	minimap(t_graphics *graph)
{
	int	largeur_de_minimap = (int)(WIDTH * 0.20);
	int	taille_de_chaque_case = largeur_de_minimap / 5;
	int	x_depart = (int)(WIDTH * 0.02);
	int	y_depart = (int)(HEIGHT * 0.02);

	int	offset_x = -2;
	int	offset_y = -2;

	int	check_x = (int)(graph)->pos_x + offset_x; // les cases de la map a checke
	int	check_y = (int)(graph)->pos_y + offset_y;

	int	grid_x = offset_x + 2; // les index dans la minimap
	int	grid_y = offset_y + 2;

	int	x_de_chaque_carre = x_depart + (grid_x * taille_de_chaque_case);
	int	y_de_chaque_carre = y_depart + (grid_y * taille_de_chaque_case);

	while (offset_y <= 2)
	{
		offset_x = -2;
		while (offset_x <= 2)
		{
			check_x = (int)(graph)->pos_x + offset_x;
			check_y = (int)(graph)->pos_y + offset_y;

			grid_x = offset_x + 2;
			grid_y = offset_y + 2;

			x_de_chaque_carre = x_depart + (grid_x * taille_de_chaque_case);
			y_de_chaque_carre = y_depart + (grid_y * taille_de_chaque_case);

			draw_minimap(x_de_chaque_carre, y_de_chaque_carre, graph, taille_de_chaque_case, check_x, check_y);
			offset_x++;
		}
		offset_y++;
	}
	int center_x = x_depart + (2 * taille_de_chaque_case) + (taille_de_chaque_case / 2) - 3;
    int center_y = y_depart + (2 * taille_de_chaque_case) + (taille_de_chaque_case / 2) - 3;
    int p_y = center_y;
    while (p_y < center_y + 9)
    {
        int p_x = center_x;
        while (p_x < center_x + 9)
        {
            my_pixel_put(graph, p_x, p_y, 0xFF0000);
            p_x++;
        }
        p_y++;
    }
}

static void	draw_outside_map(t_graphics *graph, int x, int y, int size)
{
	int old_x = x;
	int old_y = y;
	while (y < old_y + size)
	{
		x = old_x;
		while (x < old_x + size)
		{
			my_pixel_put(graph, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

static void	draw_floor(t_graphics *graph, int x, int y, int size)
{
	int old_x = x;
	int old_y = y;
	while (y < old_y + size)
	{
		x = old_x;
		while (x < old_x + size)
		{
			my_pixel_put(graph, x, y, 0xD3D3D3);
			x++;
		}
		y++;
	}
}

static void	draw_walls_minimap(t_graphics *graph, int x, int y, int size)
{
	int old_x = x;
	int old_y = y;
	while (y < old_y + size)
	{
		x = old_x;
		while (x < old_x + size)
		{
			my_pixel_put(graph, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	draw_minimap(int x_de_chaque_carre, int	y_de_chaque_carre, t_graphics *graph, int taille_de_chaque_case, int check_x, int check_y)
{
	if (check_x < 0 || check_y < 0 || check_x > ft_strlen(graph->pars->map[check_y]))
		draw_outside_map(graph, x_de_chaque_carre, y_de_chaque_carre, taille_de_chaque_case); // dessiner en noir en dehors de la map
	else if (graph->pars->map[check_y][check_x] && (graph->pars->map[check_y][check_x] == '0' || graph->pars->map[check_y][check_x] == 'N' ))
		draw_floor(graph, x_de_chaque_carre, y_de_chaque_carre, taille_de_chaque_case);
	else
		draw_walls_minimap(graph, x_de_chaque_carre, y_de_chaque_carre, taille_de_chaque_case);
}

// j'ai la hauteur et la largeur de la map
// l'offset est de -2 pour la hauteur et la largeur
// j'ai besoin des coordonnes de debut et de fin 