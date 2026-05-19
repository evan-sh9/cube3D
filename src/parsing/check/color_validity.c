#include "../../../header/cub3D.h"

int	count_element(const char *s, char c)
{
	int	i;
	int	in_word;
	int	count;

	in_word = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (in_word == 0 && s[i] != c)
		{
			count++;
			in_word = 1;
		}
		else if (in_word == 1 && !(s[i] != c))
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

void	n_check(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (count_element(s, ' ') != 1)
		invalid_file();
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ')
			invalid_map();
		if (s[i] >= '0' && s[i] <= '9')
			count++;
		i++;
	}
	if (count == 0)
		invalid_map();
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
