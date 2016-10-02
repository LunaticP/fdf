/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 12:28:14 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 12:28:17 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	y_rot_mouse(int x, t_e *data)
{
	float	a;

	if (x < data->lastx)
	{
		a = 0.015 * (data->lastx - x);
		c_y(a, &data->m.x);
		c_y(a, &data->m.y);
		c_y(a, &data->m.z);
		data->lastx = x;
	}
	if (x > data->lastx)
	{
		a = -0.015 * (x - data->lastx);
		c_y(a, &data->m.x);
		c_y(a, &data->m.y);
		c_y(a, &data->m.z);
		data->lastx = x;
	}
}

void	x_rot_mouse(int y, t_e *data)
{
	float	a;

	if (y < data->lasty)
	{
		a = -0.015 * (data->lasty - y);
		c_x(a, &data->m.x);
		c_x(a, &data->m.y);
		c_x(a, &data->m.z);
		data->lasty = y;
	}
	if (y > data->lasty)
	{
		a = 0.015 * (y - data->lasty);
		c_x(a, &data->m.x);
		c_x(a, &data->m.y);
		c_x(a, &data->m.z);
		data->lasty = y;
	}
}

int		mouse(int x, int y, t_e *data)
{
	if (data->do_move)
	{
		y_rot_mouse(x, data);
		x_rot_mouse(y, data);
	}
	return (0);
}
