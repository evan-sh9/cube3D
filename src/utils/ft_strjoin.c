#include "../../header/cub3D.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ns;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ns = ft_malloc((ft_strlen(s1) + ft_strlen(s2) + 1) ,sizeof(char));
	if (!ns)
		return (NULL);
	while (s1[i])
	{
		ns[i] = s1[i];
		i++;
	}
	while (s2[j])
		ns[i++] = s2[j++];
	ns[i] = '\0';
	return (ns);
}