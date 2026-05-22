#include "../../header/graphics.h"

void	put_sword(t_graphics **graph)
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
	int relative_y;
	int	relative_x;
	char	*ptr;
	unsigned int color;

	y = HEIGHT - (*graph)->height_sword;
	
	while (y < HEIGHT)
	{
		relative_y = y - (HEIGHT - (*graph)->height_sword);
		tex_y = (int)((double)relative_y * (64.0 / (double)(*graph)->height_sword));
		
		x = (WIDTH / 2) - ((*graph)->width_sword / 2);
		while (x < (WIDTH / 2) + ((*graph)->width_sword / 2))
		{
			relative_x = x - ((WIDTH / 2) - ((*graph)->width_sword / 2));
			tex_x = (int)((double)relative_x * (64.0 / (double)(*graph)->width_sword));

			ptr = (*graph)->sword_addr + (tex_y * (*graph)->sword_line_size + tex_x * ((*graph)->sword_pixel / 8));
			color = *(unsigned int *)ptr;

			if (color != 0x000000)
				my_pixel_put(*graph, x, y, color);
			x++;
		}
		y++;
	}
}
