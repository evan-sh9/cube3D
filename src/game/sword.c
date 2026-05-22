#include "../../header/graphics.h"

void	put_sword(t_graphics **graph)
{
	int	x;
	int	y;
	int	start_x;
	int	start_y;
	int	tex_x;
	int	tex_y;
	int relative_y;
	int	relative_x;
	char	*ptr;
	unsigned int color;

	y = HEIGHT - (int)((*graph)->height_sword * 0.60);
	start_y = y;
	while (y < HEIGHT)
	{
		relative_y = y - start_y;
		tex_y = (int)((double)relative_y * (64.0 / (double)(*graph)->height_sword));
		
		x = ((WIDTH / 2) - ((*graph)->width_sword / 2)) + 150;
		start_x = x;
		while (x < start_x + (*graph)->width_sword)
		{
			relative_x = x - start_x;
			tex_x = (int)((double)relative_x * (64.0 / (double)(*graph)->width_sword));

			ptr = (*graph)->sword_addr + (tex_y * (*graph)->sword_line_size + tex_x * ((*graph)->sword_pixel / 8));
			color = *(unsigned int *)ptr;

			if (color != 0x000000)
				my_pixel_put(*graph, x, y, color);
			x++;
		}
		y++;
	}
}


// void    put_sword(t_graphics **graph)
// {
//     int screen_x;
//     int screen_y;
//     int tex_x;
//     int tex_y;
//     unsigned int color;

//     // 1. POSITIONNEMENT DE LA BOÎTE (On triche ici !)
//     // On veut que l'épée soit décalée à droite (ex: +150 px)
//     int start_x = ((WIDTH / 2) - ((*graph)->width_sword / 2)) + 150; 
    
//     // On veut qu'elle descende TRÈS BAS pour cacher le manche (ex: on ne garde que les 60% du haut)
//     int start_y = HEIGHT - (int)((*graph)->height_sword * 0.60);

//     // 2. LA BOUCLE DU RENDU
//     screen_y = start_y;
//     while (screen_y < HEIGHT) // On s'arrête STRICTEMENT au bord de l'écran
//     {
//         // Le ratio utilise la vraie hauteur pour ne pas déformer l'image
//         int relative_y = screen_y - start_y;
//         tex_y = (int)((double)relative_y * (64.0 / (double)(*graph)->height_sword));

//         screen_x = start_x;
//         while (screen_x < start_x + (*graph)->width_sword)
//         {
//             // Sécurité : si on dépasse de l'écran à droite, on skip
//             if (screen_x >= WIDTH)
//                 break ;

//             int relative_x = screen_x - start_x;
//             tex_x = (int)((double)relative_x * (64.0 / (double)(*graph)->width_sword));

//             // Récupération du pixel dans la texture
//             char *ptr = (*graph)->sword_addr + (tex_y * (*graph)->sword_line_size + tex_x * ((*graph)->sword_pixel / 8));
//             color = *(unsigned int *)ptr;

//             // Affichage direct sans triche ni décalage
//             if (color != 0x000000)
//                 my_pixel_put(*graph, screen_x, screen_y, color);

//             screen_x++;
//         }
//         screen_y++;
//     }
// }