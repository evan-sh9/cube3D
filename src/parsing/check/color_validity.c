#include "../../../header/cub3D.h"

void	n_check(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			invalid_map();
		i++;
	}
}
void	comma_check(char *s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (j > 2)
			invalid_map();
		if (s[i] == ',')
			j++;
		i++;
	}
}

void	color_validity(char **s, int size)
{
    int i;

	i = 0;
    if (size != 3)
		invalid_map();
	while (i < size)
	{
		n_check(s[i]);
		i++;
	}
}
