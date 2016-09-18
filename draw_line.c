#include "fdf.h"
#include <math.h>
//******************//
#include <stdlib.h>
//******************//


int		ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int		get_color(int r, int g, int b)
{
int color;

	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		color = 0xFFFFFF;
	else
		color = (r * 256 * 256) + (g * 256) + b;
	return (color);
}

void	put_px(t_e *data, int x, int y, int color)
{
	int	pos;

	if (x < 0 || x > 2000 || y < 0 || y > 1250)
		return;
	pos = (x * data->bpp / 8) + (y * data->l_size);
	data->addr[pos] = color;
	data->addr[pos + 1] = color >> 8;
	data->addr[pos + 2] = color >> 16;
}

void	draw_line(t_e *X, double x, double y, int x2, int y2, int color, int color2)
{
	double	dx;
	double	dy;
	unsigned int	dd;
	unsigned int	i;

	dx = (x < x2) ? x2 - x : x - x2;
	dy = (y < y2) ? y2 - y : y - y2;
	dd = (dx > dy) ? dx : dy;
	i = 0;
	dx = x2 - x;
	dy = y2 - y;
	while (i <= dd)
	{
		X->color = get_color(127 - color * 6.35 - (i * ((double)ft_abs(color2 - color) / dd)),
		63 + color * 9.6 + (i * ((double)ft_abs((color2 - color) * 9.6) / dd)), 0);
		
		put_px(X, x, y, X->color);
		x += dx / dd;
		y += dy / dd;
		i++;
	}
}
