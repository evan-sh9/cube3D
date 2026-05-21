#include "../../header/cub3D.h"

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