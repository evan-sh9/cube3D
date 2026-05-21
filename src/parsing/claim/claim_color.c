#include "../../../header/cub3D.h"

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
    color_validity(s, size);
    int_split = ft_malloc((size + 1) , sizeof(int));
    while (i < size)
    {
        int_split[i] = ft_atoi(s[i]);
        i++;
    }
    // print_int_tab(int_split);
    return (int_split);
}

void    claim_color(t_pars *pars, int status, int line)
{
	char		*floor_color;
	char		*celling_floor;
    char		**split_floor_color;
    char		**split_celling_floor;

    if (status == F)
    {
		floor_color = claim_line(pars->file_content[line] + 2);
        comma_check(floor_color);
        split_floor_color = ft_split(floor_color, ',');
        pars->config.floor_color = char_split_to_int(split_floor_color);
        // print_int_tab(pars->config.floor_color);
    }
    else if (status == C)
    {
        celling_floor = claim_line(pars->file_content[line] + 2);
        comma_check(celling_floor);
        split_celling_floor = ft_split(celling_floor, ',');
        pars->config.celling_floor = char_split_to_int(split_celling_floor);
        // print_int_tab(pars->config.celling_floor);
    }
}
