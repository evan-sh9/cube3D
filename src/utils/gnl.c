#include "../../header/cub3D.h"

char	*fill_line(char *stash)
{
	char	*line;
	int		start;
	int		i;

	start = 0;
	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[start] != '\n' && stash[start])
		start++;
	line = malloc((start + 2) * sizeof(char));
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

void	stash_sort(char **stash)
{
	int		i;
	char	*new_stash;

	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if (!(*stash)[i])
	{
		free(*stash);
		*stash = NULL;
		return ;
	}
	new_stash = ft_substr(*stash, i + 1, ft_strlen(*stash) - (i + 1));
	free(*stash);
	*stash = new_stash;
}

char	*fill_all(char **stash, int byte, char *buffer, int fd)
{
	char	*tmp;
	char	*line;

	line = NULL;
	while (!ft_strchr(*stash, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		if (byte == 0)
			break ;
		buffer[byte] = '\0';
		tmp = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = tmp;
	}
	line = fill_line(*stash);
	stash_sort(&(*stash));
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	int			byte;
	char		*buffer;

	byte = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	line = fill_all(&stash, byte, buffer, fd);
	free(buffer);
	return (line);
}
