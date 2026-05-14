#include "../../../header/cub3D.h"

int	map_height(char *s)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

char	*claim_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		line[i] = '\0';
	return (line);
}

void	claim(t_pars *pars, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (i < CONFIG_LINE)
	{
		line = get_next_line(fd);
		i++;
	}
	while (i < pars->map_height)
	{
		line = get_next_line(fd);
        if (!line)
            break;
		pars->map[j] = claim_line(line);
        printf("map line : %s \n", pars->map[j]);
		i++;
		j++;
	}
	pars->map[j] = NULL;
	get_next_line(fd);
}

void	claim_map(t_pars *pars)
{	
	int		fd;

	pars->map_height = map_height(pars->map_file);
	if (pars->map_height <= CONFIG_LINE)
	{
		printf("Error : Invalid file\n");
		exit(EXIT_FAILURE);
	}
	if (pars->map_height == -1)
		exit(EXIT_FAILURE);
	pars->map = malloc((pars->map_height + 1) * sizeof(char *));
	if (!pars->map)
		exit(EXIT_FAILURE);
	fd = open(pars->map_file, O_RDONLY);
	if (fd == -1)
	{
		free(pars->map);
		exit(EXIT_FAILURE);
	}
	claim(pars, fd);
	close(fd);
}

void map_load(t_pars *pars)
{
	file_check(pars);
	map_data(pars);
    claim_map(pars);
    map_copy(pars);
}
