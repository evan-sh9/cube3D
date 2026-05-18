#include "../../../header/cub3D.h"

void n_setting_color_check(t_pars *pars)
{
	if (pars->find_t_var.F > 1)
		invalid_map();
	if (pars->find_t_var.C > 1)
		invalid_map();
}

void n_setting_color_is_find(t_pars *pars)
{
	if (pars->find_t_var.F < 1)
		invalid_map();
	if (pars->find_t_var.C < 1)
		invalid_map();
}

int	search_color(t_pars *pars, char *line)
{
    if (line[0] == '\0' || ft_strlen(line) < 3)
		return (-1);
	if (line[0] == 'F' && line[1] == ' ')
	{
		pars->find_t_var.F++;
		return (F);
	}
	else if (line[0] == 'C' && line[1] == ' ')
	{
		pars->find_t_var.C++;
		return (C);
	}
	n_setting_color_check(pars);
	return (-1);
}

void	find_color(t_pars *pars)
{
	int	i;
	int status;

	i = 0;
	status = 0;
	while (pars->file_content[i])
	{
		status = search_color(pars, pars->file_content[i]);
		if (status == F)
			claim_color(pars, F, i);
		else if (status == C)
        {
			claim_color(pars, C, i);
            i += 1;
            break;
        }
		i++;
	}
	n_setting_color_is_find(pars);
    pars->conf_height = i;
}
