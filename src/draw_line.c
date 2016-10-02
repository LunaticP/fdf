/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 06:11:13 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 07:11:51 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdio.h>

int		get_color(int r, int g, int b)
{
	int color;

	if (r > 255 || g > 255 || b > 255)
	{
		r = (r > 255) ? 255 : r;
		g = (g > 255) ? 255 : g;
		b = (b > 255) ? 255 : b;
	}
	if (r < 0 || g < 0 || b < 0)
		color = 0x000000;
	else
		color = (r * 256 * 256) + (g * 256) + b;
	return (color);
}

void	put_px(t_e *data, int x, int y)
{
	int	pos;

	if (x <= 0 || x >= 2400 || y <= 0 || y >= 1350)
		return ;
	pos = (x * data->bpp / 8) + (y * data->l_size);
	data->addr[pos] = data->color;
	data->addr[pos + 1] = (data->color >> 8);
	data->addr[pos + 2] = data->color >> 16;
}

t_color	col(t_draw *x, int i, t_e *d, int dd)
{
	t_color	c;

	c.start = d->r_e - ((d->r_e - d->r_s) / d->zmax * x->c);
	c.end = d->r_e - ((d->r_e - d->r_s) / d->zmax * x->c2);
	c.step = (c.end - c.start) / dd;
	c.r = c.start + i * c.step;
	c.start = d->g_e - ((d->g_e - d->g_s) / d->zmax * x->c);
	c.end = d->g_e - ((d->g_e - d->g_s) / d->zmax * x->c2);
	c.step = (c.end - c.start) / dd;
	c.g = c.start + i * c.step;
	c.start = d->b_e - ((d->b_e - d->b_s) / d->zmax * x->c);
	c.end = d->b_e - ((d->b_e - d->b_s) / d->zmax * x->c2);
	c.step = (c.end - c.start) / dd;
	c.b = c.start + i * c.step;
	return (c);
}

void	init_d(float *dx, float *dy, unsigned int *dd, t_draw *x)
{
	*dx = (x->x < x->x2) ? x->x2 - x->x : x->x - x->x2;
	*dy = (x->y < x->y2) ? x->y2 - x->y : x->y - x->y2;
	*dd = (*dx > *dy) ? *dx : *dy;
	*dx = *dd != 0 ? (x->x2 - x->x) / *dd : 1;
	*dy = *dd != 0 ? (x->y2 - x->y) / *dd : 1;
}

void	draw_line(t_e *data, t_draw *x)
{
	float			dx;
	float			dy;
	unsigned int	dd;
	unsigned int	i;
	t_color			c;

	i = 0;
	init_d(&dx, &dy, &dd, x);
	if ((x->x + (dx * i) + data->x < 0 || x->y + (dy * i) + data->y < 0)
	&& (x->x2 + (dx * i) + data->x < 0 || x->y2 + (dy * i) + data->y < 0))
		return ;
	if ((x->x + (dx * i) + data->x > 2400 || x->y + (dy * i) + data->y > 1350)
	&& (x->x2 + (dx * i) + data->x > 2400 || x->y2 + (dy * i) + data->y > 1350))
		return ;
	c.r = 255;
	c.g = 255;
	c.b = 255;
	while (i < dd)
	{
		if (data->do_color)
			c = col(x, i, data, dd);
		data->color = get_color(c.r, c.g, c.b);
		put_px(data, x->x + (dx * i) + data->x, x->y + (dy * i) + data->y);
		i++;
	}
}
