/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:36:56 by aviau             #+#    #+#             */
/*   Updated: 2016/09/20 10:40:09 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		mouse(int x, int y, t_e *data)
{
	if (data->do_move)
	{
		if (x < data->lastx)
		{
			data->rotx -= 0.0174533 * (data->lastx - x);
			data->lastx = x;
		}
		if (x > data->lastx)
		{
			data->rotx += 0.0174533 * (x - data->lastx);
			data->lastx = x;
		}
		if (y < data->lasty)
		{
			data->roty -= 0.0174533 * (data->lasty - y);
			data->lasty = y;
		}
		if (y > data->lasty)
		{
			data->roty += 0.0174533 * (data->lasty - y);
			data->lasty = y;
		}
	}
	draw_grid(data);
	return (0);	
}

int		keyboard(int key, t_e *data)
{
	if (key == 123) // left
		data->x -= 5;
	if (key == 124) // right
		data->x += 5;
	if (key == 126) // up
		data->y -= 5;
	if (key == 125) // down
		data->y += 5;
	if (key == 67) // *
		data->xx++;
	if (key == 75) // /
		data->xx--;
	if (key == 69) // +
		data->zz += 1;
	if (key == 78) // -
		data->zz -= 1;
	else if (key == 12)
	{
		mlx_destroy_image (data->mlx, data->image);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (key == 86)
		data->rotx -= 0.0174533 * 3;
	if (key == 88)
		data->rotx += 0.0174533 * 3;
	if (key == 84)
		data->roty -= 0.0174533 * 3;
	if (key == 91)
		data->roty += 0.0174533 * 3;
	if (key == 49)
		data->do_move = 1;
	else if (key == 53)
		data->do_move = 0;
	if (key == 87)
	{
		data->x = 30;
		data->y = 50;
		data->xx = 52;
		data->yy = 20;
		data->zz = 13;
		data->rotx = 5.040033;
		data->roty = 5.040033;
	}
	mlx_string_put(data->mlx, data->win, 50, 50, 0xFFFF00,"Coucou");
	draw_grid(data);
	return (0);
}
