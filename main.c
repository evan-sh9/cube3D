#include "header/parsing.h"

int main(int ac, char **av)
{
    t_pars pars;

    if (ac != 2)
        return (1);
    pars.map_file = av[1];
    map_load(&pars);
    return 0;
}
