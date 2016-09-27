/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 06:11:13 by aviau             #+#    #+#             */
/*   Updated: 2016/09/27 02:47:10 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

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
		color = 0xFF00FF;
	else
		color = (r * 256 * 256) + (g * 256) + b;
	return (color);
}

void	put_px(t_e *data, int x, int y)
{
	int	pos;

	if (x <= 0 || x >= 1000 || y <= 0 || y >= 1000)
		return ;
	pos = (x * data->bpp / 8) + (y * data->l_size);
	data->addr[pos] = data->color % 256;
	data->addr[pos + 1] = (data->color >> 8) % 256;
	data->addr[pos + 2] = data->color >> 16;
}

void	draw_line(t_e *data, t_draw *x)
{
	float			dx;
	float			dy;
	unsigned int	dd;
	unsigned int	i;

	dx = (x->x < x->x2) ? x->x2 - x->x : x->x - x->x2;
	dy = (x->y < x->y2) ? x->y2 - x->y : x->y - x->y2;
	dd = (dx > dy) ? dx : dy;
	i = 0;
	dx = (x->x2 - x->x) / dd;
	dy = (x->y2 - x->y) / dd;
	while (i <= dd)
	{
//		data->color = get_color(127 - x->z * 6.35 -
//		(i * ((double)ft_abs(x->z2 - x->z) / dd)),
//		63 + x->z * 9.6 + (i * ((double)ft_abs((x->z2 - x->z) * 9.6) / dd)),
//		0);
		data->color = get_color(255, 255, 255);
		put_px(data, x->x + (dx * i) + data->x , x->y + (dy * i) + data->y);
		i++;
	}
}
