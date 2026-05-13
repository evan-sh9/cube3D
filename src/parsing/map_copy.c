#include "../../header/cub3D.h"

int width_line(char **s, int i)
{
    int count;

    count = 0;
    if (!s || !*s)
        return (0);
    while (s[i][count])
        count++;
    return (count);
}

void	map_copy(t_pars *pars)
{
	int	i;

	i = 0;
	pars->map_copy = malloc((pars->map_height + 1) * sizeof(char *));
	while (i < pars->map_height)
	{
        pars->map_width = width_line(pars->map, i);
		pars->map_copy[i] = malloc((pars->map_width + 1) * sizeof(char));
		i++;
	}
	i = 0;
	while (i < pars->map_height)
	{
		pars->map_copy[i] = ft_strcpy(pars->map_copy[i], pars->map[i]);
        // printf("map line cpy : %s \n", pars->map_copy[i]);
		i++;
	}
	pars->map_copy[i] = NULL;
}
