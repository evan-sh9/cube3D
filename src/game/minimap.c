#include "../../header/graphics.h"

void	minimap(t_graphics *graph)
{
	graph->mini_map->nb_square_x = -2; // l'offset_x
	graph->mini_map->nb_square_y = -2; // l'offset_y, ils vont de -2 a 2 donc on affiche 5 cases autour du joueur 
	graph->mini_map->ray_minimap = 2; // le rayon de la map 
	graph->mini_map->totalnb_squares = graph->mini_map->ray_minimap * 2 + 1;
	graph->mini_map->size_of_block = (int)(HEIGHT * 0.20) / graph->mini_map->totalnb_squares; // la taille de chaque block de la map
	int map_start_x = 20;
	int	map_start_y = 20;
	
	while (graph->mini_map->nb_square_y <= 2)
	{
		while (graph->mini_map->nb_square_x <= 2)
		{
			int check_x = (int)(graph)->pos_x + (graph)->mini_map->nb_square_x;
			int check_y = (int)(graph)->pos_y + (graph)->mini_map->nb_square_y;

			int grid_x = graph->mini_map->nb_square_x + 2;
			int	grid_y = graph->mini_map->nb_square_y + 2;
			int	x = map_start_x + (grid_x * graph->mini_map->size_of_block);
			int	y = map_start_y + (grid_y * graph->mini_map->size_of_block);

			unsigned int color = 0x000000;

			if (check_y >= 0 && check_x >= 0)
			{
				if (graph->pars->map[check_y][check_x] == '0')
					color = 0x00FF00;
			}

			int draw_y = y;
			while (draw_y < y + graph->mini_map->size_of_block)
			{
				int draw_x = x;
				while (draw_x < x + graph->mini_map->size_of_block)
				{
					my_pixel_put(graph, draw_x, draw_y, color);
					draw_x++;
				}
				draw_y++;
			}
			graph->mini_map->nb_square_x++;
		}
		graph->mini_map->nb_square_y++;	
	}
}
// 

// je dois calculer l'endroit ou je veux display la map avec x de debut et x de fin, y de debut et y de fin
// je pourrais la coller en heau de la fenetre pour que ca soit plus simple ou en bas de la fentre 
// je dois calculer le ratio de l'affichage, je pourrais reprendre le mm que celui de l'epee 
// ensuite je dois trouver le moyen d'afficher la map en entier, donc soit je chosit de faire toute la map et en fonction d'ou je suis j'affiche le joueur en rouge 
// ou bien je l'affiche dynamiquement et la ca va etre plus complique je pense 