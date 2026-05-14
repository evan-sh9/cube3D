#include "../../../header/cub3D.h"

void	map_copy(t_pars *pars)
{
	int	i;

	i = 0;
	pars->map_copy = malloc(((pars->map_height + 1) - CONFIG_LINE) * sizeof(char *));
	if (!pars->map_copy)
		return ;
	while (i < pars->map_height - CONFIG_LINE)
	{
		pars->map_copy[i] = ft_strdup(pars->map[i]);
		printf("map line cpy : %s \n", pars->map_copy[i]);
		i++;
	}
	pars->map_copy[i] = NULL;
}
