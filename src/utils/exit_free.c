#include "../../header/cub3D.h"

void	invalid_map()
{
	ft_free_all_malloc();
	printf("Error \nInvalid map format\n");
	exit(EXIT_FAILURE);
}

void	invalid_file()
{
	ft_free_all_malloc();
	printf("Error \nInvalid file\n");
	exit(EXIT_FAILURE);
}