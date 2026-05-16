#include "../../header/cub3D.h"

int color_check(char *line, int line_nb)
{
	if (line_nb == 5 && line[0] == '\0')
		return (0);
	else if (line_nb == 6 && line[0] == 'F' && line[1] == ' ')
		return (0);
	else if (line_nb == 7 && line[0] == 'C' && line[1] == ' ')
		return (0);
	else if (line_nb == 8 && line[0] == '\0')
		return (0);
	return (1);
}

int	line_checker(char *line, int line_nb)
{
	if (line_nb == 1 && line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (0);
	else if (line_nb == 2 && line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (0);
	else if (line_nb == 3 && line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (0);
	else if (line_nb == 4 && line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (0);
	return (color_check(line, line_nb));
}

void	fill_config_struct(t_pars *pars, int line_nb)
{

	if (line_nb == 1)
		pars->config.north_texture = claim_line(pars->file_content[0] + 3);
	else if (line_nb == 2)
		pars->config.south_texture = claim_line(pars->file_content[1] + 3);
	else if (line_nb == 3)
		pars->config.west_texture = claim_line(pars->file_content[2] + 3);
	else if (line_nb == 4)
		pars->config.est_texture = claim_line(pars->file_content[3] + 3);
	claim_color(pars, line_nb);
}

void	config_validity(t_pars *pars)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	while (i < CONFIG_LINE)
	{
		if (line_checker(pars->file_content[i], i + 1))
			invalid_map();
		else
			fill_config_struct(pars, i + 1);
		i++;
	}
}

/*
	printf("north path : %s \n", pars->config.north_texture);
	printf("south path : %s \n", pars->config.south_texture);
	printf("west path : %s \n", pars->config.west_texture);
	printf("est path : %s \n", pars->config.est_texture);
	printf("floor color : \n");
	print_int_tab(pars->config.floor_color);
	printf("celling color : \n");
	print_int_tab(pars->config.celling_floor);
*/