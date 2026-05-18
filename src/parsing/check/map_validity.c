#include "../../../header/cub3D.h"

void	flood_fill(t_pars *pars, int x, int y)
{
	if (pars->map_copy[x][y] == ' ' || pars->map_copy[x][y] == '\0')
		invalid_map();
	if (pars->map_copy[x][y] != '0' && pars->map_copy[x][y] != 'N'
		&& pars->map_copy[x][y] != 'S' && pars->map_copy[x][y] != 'E'
		&& pars->map_copy[x][y] != 'W')
		return ;
	pars->map_copy[x][y] = 'F';
	flood_fill(pars, x + 1, y);
	flood_fill(pars, x - 1, y);
	flood_fill(pars, x, y + 1);
	flood_fill(pars, x, y - 1);
}
