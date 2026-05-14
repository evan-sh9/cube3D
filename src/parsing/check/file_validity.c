#include "../../../header/cub3D.h"

int	extention_check(char *s)
{
	int	start;

	start = ft_strlen(s) - 4;
	if (ft_strncmp(s + start, ".cub", 4) != 0)
		return (1);
	if (s[start - 1] == '/')
		return (1);
	return (0);
}

void	file_check(t_pars *pars)
{
	if (ft_strlen(pars->map_file) <= 4)
	{
		// free();
		printf("Error :Invalid file\n");
		exit(EXIT_FAILURE);
	}
	if (extention_check(pars->map_file))
	{
		// free();
		printf("Error : Invalid file\n");
		exit(EXIT_FAILURE);
	}
}
