#include "../../../header/cub3D.h"

int	extention_check(char *s)
{
	int	start;
	int size;

	size = ft_strlen(s);
	start = size - 4;
	if (size <= 4)
		invalid_file();
	if (ft_strncmp(s + start, ".cub", 4) != 0)
		return (1);
	return (0);
}

void	file_check(t_pars *pars)
{
	if (ft_strlen(pars->map_file) <= 4)
		invalid_file();
	if (extention_check(pars->map_file))
		invalid_file();
}
