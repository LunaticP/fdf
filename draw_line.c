/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 06:11:13 by aviau             #+#    #+#             */
/*   Updated: 2016/09/20 08:48:30 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

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

void	put_px(t_e *data, int x, int y)
{
	int	pos;

	if (x < 0 || x > 1000 || y < 0 || y > 1000)
		return ;
	pos = (x * data->bpp / 8) + (y * data->l_size);
	data->addr[pos] = data->color;
	data->addr[pos + 1] = data->color >> 8;
	data->addr[pos + 2] = data->color >> 16;
}

void	draw_line(t_e *data, t_draw *X)
{
	data->color = 0xFF0000;
	double			dx;
	double			dy;
	unsigned int	dd;
	unsigned int	i;

	dx = (X->x < X->x2) ? X->x2 - X->x : X->x - X->x2;
	dy = (X->y < X->y2) ? X->y2 - X->y : X->y - X->y2;
	dd = (dx > dy) ? dx : dy;
	i = 0;
	dx = X->x2 - X->x;
	dy = X->y2 - X->y;
	while (i <= dd)
	{
		put_px(data, X->x, X->y);
		X->x += dx / dd;
		X->y += dy / dd;
		i++;
	}
}
