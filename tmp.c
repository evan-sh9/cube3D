
void	display(t_graphics *graph, int x, int side)
{
	int	y;
	int	color;
	t_img   *current_tex;

	y = 0;
	while (y < graph->higher_px)
	{
		my_pixel_put(graph, x, y, 0x333333);
		y++;
	}
	/* =========================================================== */
	if (side == 1)
	{
		graph->tex_map.wall_x = graph->pos_x + graph->perpWallDist * graph->ray_x;
		graph->tex_map.wall_x = claim_decimal(graph->tex_map.wall_x);
		if (graph->ray_y > 0)
			graph->tex_map.wall_x = TEX_WIDTH - graph->tex_map.wall_x - 1;
	}
	else 
	{
		graph->tex_map.wall_x = graph->pos_y + graph->perpWallDist * graph->ray_y;
		graph->tex_map.wall_x = claim_decimal(graph->tex_map.wall_x);
		graph->tex_map.texX = (int)(graph->tex_map.wall_x * (double)TEX_WIDTH);
		if (graph->ray_x > 0)
			graph->tex_map.wall_x = TEX_WIDTH - graph->tex_map.texX - 1;
	}
	graph->tex_map.step = 1.0 * TEX_HEIGHT / graph->wall_height;
	graph->tex_map.text_pos = (graph->higher_px - (HEIGHT / 2) + (graph->wall_height / 2)) * graph->tex_map.step;
	/* ============================================================= */
	while (y <= graph->lower_px)
	{
		graph->tex_map.texY = (int)(graph->tex_map.text_pos) & (TEX_HEIGHT - 1);
		if (side == 1)
		{
			if (graph->step_y == -1) // nord
			{ 
				color = 0x7E75FA; // bleu
			}
			else	// sud
			{
				color = 0xF17EDC; // rose
			}
		}
		else
		{
			if (graph->step_x == 1) // est
			{
				color = 0xFFA570; // orange
			}
			else	// sud
			{
				color = 0x81FF70; // vert
			}
		}
		my_pixel_put(graph, x, y, color);
		y++;
	}
	/* =========================================================== */
	while (y < HEIGHT)
	{
		my_pixel_put(graph, x, y, 0x666666);
		y++;
	}
}