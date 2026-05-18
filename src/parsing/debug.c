#include "../../header/cub3D.h"

void   print_double_tab(char **s)
{
    int i = 0;

    while (s[i])
    {
        printf("print d tab : %s\n", s[i]);
        i++;
    }
}

void   print_int_tab(int *s)
{
    int i = 0;

    while (i < 3)
    {
        printf("print int tab : %i\n", s[i]);
        i++;
    }
}