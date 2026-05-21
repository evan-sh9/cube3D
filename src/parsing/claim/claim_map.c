#include "../../../header/cub3D.h"

void	claim_map_copy(t_pars *pars)
{
	int	i;

	i = 0;
	pars->map_copy = ft_malloc((pars->map_height + 1), sizeof(char *));
	if (!pars->map_copy)
		return ;
	while (pars->map[i])
	{
		pars->map_copy[i] = ft_strdup(pars->map[i]);
		i++;
	}
	pars->map_copy[i] = NULL;
}

void	claim_map(t_pars *pars)
{
	int	i;

	i = 0;
	pars->map_height = pars->file_height - pars->conf_height;
	pars->map = ft_malloc((pars->map_height + 1) ,sizeof(char *));
	if (!pars->map)
		return ;
	while (i < pars->map_height)
	{
		pars->map[i] = ft_strdup(pars->file_content[i + pars->conf_height]);
		i++;
	}
	pars->map[i] = NULL;
}
