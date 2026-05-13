#include "../../header/cub3D.h"

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

void	claim_map(t_pars *pars)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	pars->map_height = map_height(pars->map_file);
	if (pars->map_height == -1)
		exit(EXIT_FAILURE); //tmp
	pars->map = malloc((pars->map_height + 1) * sizeof(char *));
	if (!pars->map)
		exit(EXIT_FAILURE); //tmp
	fd = open(pars->map_file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE); //tmp
	while (i < pars->map_height)
	{
		line = get_next_line(fd);
		pars->map[i] = claim_line(line);
        // printf("map line : %s \n", pars->map[i]);
		i++;
	}
	get_next_line(fd);
	pars->map[i] = NULL;
	close(fd);
}

void map_load(t_pars *pars)
{
    claim_map(pars);
    map_copy(pars);
}