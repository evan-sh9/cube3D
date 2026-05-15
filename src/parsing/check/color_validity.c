#include "../../../header/cub3D.h"

void   print_double_tab(char **s)
{
    int i = 0;

    while (s[i])
    {
        printf("tab %i : %s\n", i, s[i]);
        i++;
    }
}
void   print_int_double_tab(int *s)
{
    int i = 0;

    while (i < 3)
    {
        printf("tab %i : %i\n", i, s[i]);
        i++;
    }
}

int   double_tab_size(char **s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int     *char_split_to_int(char **s)
{
    int     i;
    int     size;
    int     *int_split;

    i = 0;
    size = double_tab_size(s);
    printf("size : %i\n", size);
    if (size != 3)
    {
        //free_all();
        printf("Error : Invalid map format\n");
        exit(EXIT_FAILURE);
    }
    int_split = malloc((size + 1) * sizeof(int));
    while (i < size)
    {
        int_split[i] = ft_atoi(s[i]);
        i++;
    }
    print_int_double_tab(int_split);
    return (int_split);
}

void    claim_color(t_pars *pars, int line_nb)
{
	char		*floor_color;
	char		*celling_floor;
    char		**split_floor_color;
    char		**split_celling_floor;

    if (line_nb == 6)
    {
		floor_color = claim_line(pars->file_content[5] + 2);
        split_floor_color = ft_split(floor_color, ',');
        // print_double_tab(split_floor_color);
        char_split_to_int(split_floor_color);
    }
    else if (line_nb == 7)
    {
        celling_floor = claim_line(pars->file_content[6] + 2);
        split_celling_floor = ft_split(celling_floor, ',');
        // print_double_tab(split_celling_floor);
    }
}
