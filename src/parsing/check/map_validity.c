#include "../../../header/cub3D.h"

int	element_check(t_pars *pars, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 'N' || s[i] == 'S' || s[i] == 'W'
			|| s[i] == 'E')
			pars->spawn_count++;
		if ((s[i] != 'N' && s[i] != 'S' && s[i] != 'W'
			&& s[i] != 'E' && s[i] != '0' && s[i] != '1') 
			&& s[i] != ' ' && s[i] != '2')
			invalid_file();
		i++;
	}
	return (0);
}

void	spawn_checker(t_pars *pars)
{
	int	i;

	i = 0;
	pars->spawn_count = 0;
	while (pars->map_copy[i])
	{
		if (element_check(pars, pars->map_copy[i]))
			invalid_map();
		i++;
	}
	if (pars->spawn_count != 1)
		invalid_map();
}

void	flood_fill(t_pars *pars, int x, int y)
{
	if (pars->map_copy[x][y] == ' ' || pars->map_copy[x][y] == '\0')
		invalid_map();
	if (pars->map_copy[x][y] != '0' && pars->map_copy[x][y] != 'N'
		&& pars->map_copy[x][y] != 'S' && pars->map_copy[x][y] != 'E'
		&& pars->map_copy[x][y] != 'W' && pars->map_copy[x][y] != '2')
		return ;
	pars->map_copy[x][y] = 'F';
	flood_fill(pars, x + 1, y);
	flood_fill(pars, x - 1, y);
	flood_fill(pars, x, y + 1);
	flood_fill(pars, x, y - 1);
}
