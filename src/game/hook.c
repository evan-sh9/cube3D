#include "../../header/graphics.h"

// je dois faire en sorte que quand je bouge je ne ca fais l'algo aussi 
// je dois faire en sorte de gerer les differente texture de mur avec une fonction get direction qui va me renvoyer si je regarde un mur
// si je regarde a l'est c'est que je vois la face ouest du mur, si je regarde l'ouest c'est que c'est la face est.
// si je regarde vers le nord c'est que je vois la face sud du mur et si je regarde vers le sud c'est que je vois la face nord du mur
// la fleche de gauche et de droite me permnettent de regarder a gauche et a droite 
// je dois donc trouver une vitesse de rotation stable qui ne va pas saccader l'image mais avec une sensi plutot agreable a jouer
// il faut gerer le plafond et le sol
// il faut gerer les touches WASD pour bouger
// esc et la croix pour fermer le jeu 
// on doit gerer la colision avec les murs 
// faire une mini map
// les portes si on veut faire tout les bonus 
// les animations ?? je ne sais pas comment faire ca 
// tourner avec la souris

void	ft_exit(t_graphics *graph)
{
	mlx_destroy_image(graph->mlx, graph->img);
	mlx_destroy_window(graph->mlx, graph->window);
	mlx_destroy_display(graph->mlx);
	free(graph->mlx);
	ft_free_all_malloc();
	exit(EXIT_SUCCESS);
}

void	mouv(int keycode, t_graphics **graph) // pour gerer les mouvements de cmaera et du joeurs
{
	if (keycode == 65307)
		ft_exit(*graph);
	// else if (keycode == 65363)
	// 	turn_camera_to_right();
	// else if (keycode == 65361)
	// 	turn_camera_to_left();
	// if else pour toutes les touches
	// en fonction de la touche on va soit modifier la posriiton du jouer soit la direction des rayons
}

// void	turn_camera_to_right(t_graphics **graph)
// {
// 	(*graph)->dir_x = 
// }
