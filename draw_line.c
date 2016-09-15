#include "fdf.h"
#include <math.h>
#include <stdio.h>
//******************//
#include <stdlib.h>
//******************//

void draw_line(t_e *X, double x, double y, int x2, int y2)
{
	double	dx;
	double	dy;
	unsigned int	dd;
	unsigned int	i;

	dx = (x < x2) ? x2 - x : x - x2;
	dy = (y < y2) ? y2 - y : y - y2;
	dd = (dx > dy) ? dx : dy;
	i = 0;
	printf ("dx = %f - dy = %f - dd = %u\n", dx, dy, dd);
	dx = x2 - x;
	dy = y2 - y;
	while (i <= dd)
	{
		mlx_pixel_put(X->mlx, X->win, x, y, 0x00FFFFFF);
		x += dx / dd;
		y += dy / dd;
		i++;
	}
}
