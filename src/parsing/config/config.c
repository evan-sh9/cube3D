#include "../../../header/cub3D.h"

int	line_checker_next(t_pars *pars, char *line)
{
	if (line[0] == 'W' && line[1] == 'E' && (line[2] == ' ' || line[2] == '\t'))
	{
		pars->find_t_var.WE++;
		return (WE);
	}
	else if (line[0] == 'E' && line[1] == 'A' && (line[2] == ' '
			|| line[2] == '\t'))
	{
		pars->find_t_var.EA++;
		return (EA);
	}
	n_setting_check(pars);
	return (-1);
}

int	line_checker(t_pars *pars, char *line)
{
	if (line[0] == '\0' || ft_strlen(line) < 3)
		return (-1);
	if (line[0] == 'N' && line[1] == 'O' && (line[2] == ' ' || line[2] == '\t'))
	{
		pars->find_t_var.NO++;
		return (NO);
	}
	else if (line[0] == 'S' && line[1] == 'O' && (line[2] == ' '
			|| line[2] == '\t'))
	{
		pars->find_t_var.SO++;
		return (SO);
	}
	return (line_checker_next(pars, line));
}

int	conf_validation(t_pars *pars, int i)
{
	if (pars->find_t_var.NO && pars->find_t_var.SO && pars->find_t_var.WE
		&& pars->find_t_var.EA && pars->find_t_var.F && pars->find_t_var.C)
	{
		pars->conf_height = i;
		return (1);
	}
	invalid_map();
	return (0);
}

void	find_texture(t_pars *pars)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (pars->file_content[i])
	{
		status = line_checker(pars, pars->file_content[i]);
		if (status == NO)
			pars->config.north_texture = claim_line(pars->file_content[i] + 3);
		else if (status == SO)
			pars->config.south_texture = claim_line(pars->file_content[i] + 3);
		else if (status == WE)
			pars->config.west_texture = claim_line(pars->file_content[i] + 3);
		else if (status == EA)
			pars->config.east_texture = claim_line(pars->file_content[i] + 3);
		else if (search_color(pars, pars->file_content[i]) == -2)
			if (conf_validation(pars, i))
				return ;
		i++;
	}
	n_setting_is_find(pars);
}

void	config_load(t_pars *pars)
{
	pars->find_t_var.NO = 0;
	pars->find_t_var.SO = 0;
	pars->find_t_var.WE = 0;
	pars->find_t_var.EA = 0;
	pars->find_t_var.F = 0;
	pars->find_t_var.C = 0;
	find_texture(pars);
	find_color(pars);
	texture_check(pars);
	printf("north path : %s \n", pars->config.north_texture);
	printf("south path : %s \n", pars->config.south_texture);
	printf("west path : %s \n", pars->config.west_texture);
	printf("east path : %s \n", pars->config.east_texture);
	printf("floor color : \n");
	print_int_tab(pars->config.floor_color);
	printf("celling color : \n");
	print_int_tab(pars->config.celling_floor);
}

/*
	printf("north path : %s \n", pars->config.north_texture);
	printf("south path : %s \n", pars->config.south_texture);
	printf("west path : %s \n", pars->config.west_texture);
	printf("east path : %s \n", pars->config.east_texture);
	printf("floor color : \n");
	print_int_tab(pars->config.floor_color);
	printf("celling color : \n");
	print_int_tab(pars->config.celling_floor);
*/