#include "../../../header/cub3D.h"

// int texture_path_checker(char *line, char c)
// {

// }

int	line_checker(char *line, int i)
{
	if (i == 1 && line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (0);
	else if (i == 2 && line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (0);
	else if (i == 3 && line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (0);
	else if (i == 4 && line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (0);
	else if (i == 5 && line[0] == '\n' && line[1] == '\0')
		return (0);
	else if (i == 6 && line[0] == 'F' && line[1] == ' ')
		return (0);
	else if (i == 6 && line[0] == 'C' && line[1] == ' ')
		return (0);
	return (1);
}

void	map_data(t_pars *pars)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(pars->map_file, O_RDONLY);
	while (i < 5)
	{
		line = get_next_line(fd);
		if (line_checker(line, i + 1))
		{
			printf("Error : Invalid map format\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	close(fd);
}
