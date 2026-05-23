#include "../../header/graphics.h"

// void	minimap(t_graphics *graph)
// {
// 	graph->mini_map->start_x = WIDTH * 0.1;
// 	graph->mini_map->start_y = HEIGHT * 0.20;
// 	while (graph->mini_map->start_x < graph->mini_map)
// 	{
// 		my_pixel_put(graph, graph->mini_map->start_x, graph->mini_map->start_y, 0x000000);
// 		graph->mini_map->start_x++;
// 	}
// }

// int	
// je dois calculer l'endroit ou je veux display la map avec x de debut et x de fin, y de debut et y de fin
// je pourrais la coller en heau de la fenetre pour que ca soit plus simple ou en bas de la fentre 
// je dois calculer le ratio de l'affichage, je pourrais reprendre le mm que celui de l'epee 
// ensuite je dois trouver le moyen d'afficher la map en entier, donc soit je chosit de faire toute la map et en fonction d'ou je suis j'affiche le joueur en rouge 
// ou bien je l'affiche dynamiquement et la ca va etre plus complique je pense 