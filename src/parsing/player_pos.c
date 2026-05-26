#include "../../header/cub3D.h"

int	find_pl_pos(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	while (pars->map[i])
	{
		j = 0;
		while (pars->map[i][j])
		{
			if (pars->map[i][j] == 'N' || pars->map[i][j] == 'S'
				|| pars->map[i][j] == 'E' || pars->map[i][j] == 'W')
			{
				pars->pl_pos[0] = i;
				pars->pl_pos[1] = j;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
