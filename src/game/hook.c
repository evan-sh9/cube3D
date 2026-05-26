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
	mlx_destroy_image(graph->mlx, graph->pars->tex.north_wall.img);
	mlx_destroy_image(graph->mlx, graph->pars->tex.south_wall.img);
	mlx_destroy_image(graph->mlx, graph->pars->tex.east_wall.img);
	mlx_destroy_image(graph->mlx, graph->pars->tex.west_wall.img);
	mlx_destroy_image(graph->mlx, graph->sword_img);
	mlx_destroy_image(graph->mlx, graph->img);
	mlx_destroy_window(graph->mlx, graph->window);
	mlx_destroy_display(graph->mlx);
	free(graph->mlx);
	ft_free_all_malloc();
	exit(EXIT_SUCCESS);
}

void	mouv(int keycode, t_graphics **graph)
{
	if (keycode == 65307)
		ft_exit(*graph);
	else if (keycode == FLECHE_G)
		(*graph)->rotate_gauche = 1;
	else if (keycode == FLECHE_D)
		(*graph)->rotate_droite = 1;
	else if (keycode == W_AVANT)
		(*graph)->avancer = 1;
	else if (keycode == A_GAUCHE)
		(*graph)->a_gauche = 1;
	else if (keycode == S_ARRIERE)
		(*graph)->reculer = 1;
	else if (keycode == D_DROITE)
		(*graph)->a_droite = 1;
}

void	stop_mouv(int keycode, t_graphics **graph)
{
	if (keycode == FLECHE_G)
		(*graph)->rotate_gauche = 0;
	else if (keycode == FLECHE_D)
		(*graph)->rotate_droite = 0;
	else if (keycode == W_AVANT)
		(*graph)->avancer = 0;
	else if (keycode == A_GAUCHE)
		(*graph)->a_gauche = 0;
	else if (keycode == S_ARRIERE)
		(*graph)->reculer = 0;
	else if (keycode == D_DROITE)
		(*graph)->a_droite = 0;
}
