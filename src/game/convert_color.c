#include "../../header/cub3D.h"

int	count_n(int nb)
{
	int	c;

	c = 0;
	while (nb >= 16)
	{
		nb = nb / 16;
		c++;
	}
	return (c + 1);
}

int dec_to_hexa(int n)
{
    int             tmp;
    int             len;
	char			*base;
    char            *convert;

	base = "0123456789ABCD";
    len = count_n(n);
	convert = ft_malloc(len ,sizeof(char));
    if (n == 0)
        convert[0] = '0';
    convert[len] = '\0';
    while (n > 0)
    {
        len--;
        convert[len] = base[n % 16];
        n /= 16;
    }
    return (/* atoi base */);
}

int rgb_to_hexa(int *tab)
{
    int convert;
    tab[0] = dec_to_hexa(tab[0]);
    tab[1] = dec_to_hexa(tab[1]);
    tab[2] = dec_to_hexa(tab[2]);

    printf("tab 0 : %i\n", tab[0]);
    printf("tab 1 : %i\n", tab[1]);
    printf("tab 2 : %i\n", tab[2]);
    return (convert);
}