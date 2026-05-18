#include "../../../header/cub3D.h"

int	file_height(char *s)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		// free(line);
		line = get_next_line(fd);
	}
	// free(line);
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
	char	*line;

	i = 0;
	while (i < pars->file_height)
	{
		line = get_next_line(fd);
		pars->file_content[i] = claim_line(line);
        // printf("file content : %s \n", pars->file_content[i]);
		i++;
	}
	pars->file_content[i] = NULL;
	get_next_line(fd);
}

void	claim_content(t_pars *pars)
{	
	int		fd;

	pars->file_height = file_height(pars->map_file);
	if (pars->file_height <= CONFIG_LINE)
		invalid_file();
	if (pars->file_height == -1)
		exit(EXIT_FAILURE);
	pars->file_content = malloc((pars->file_height + 1) * sizeof(char *));
	fd = open(pars->map_file, O_RDONLY);
	if (fd == -1)
	{
		// free all
		exit(EXIT_FAILURE);
	}
	claim(pars, fd);
	close(fd);
}

void map_load(t_pars *pars)
{
	file_check(pars);
    claim_content(pars);
	config_load(pars);
	claim_map(pars);
    claim_map_copy(pars);
	
	find_pl_pos(pars);
	flood_fill(pars, pars->pl_pos[0], pars->pl_pos[1]);
	// print_double_tab(pars->map_copy);
}

//	printf("start pos | x : %i, y : %i\n", pars->pl_pos[0], pars->pl_pos[1]);
//	claim all -> config -> map -> map copy