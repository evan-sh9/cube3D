#include "../../header/cub3D.h"

char	*ft_strdup(char *s)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_malloc(1, (ft_strlen(s) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
