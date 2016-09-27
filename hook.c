/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:36:56 by aviau             #+#    #+#             */
/*   Updated: 2016/09/27 01:31:06 by aviau            ###   ########.fr       */
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
	if (key == 123)
		data->x -= 5;
	if (key == 124)
		data->x += 5;
	if (key == 126)
		data->y -= 5;
	if (key == 125)
		data->y += 5;
	if (key == 67)
		data->scl *= 1.02;
	if (key == 75)
		data->scl /= 1.02;
	if (key == 69)
		data->zz += 0.01;
	if (key == 78)
		data->zz -= 0.01;
	else if (key == 12)
	{
		mlx_destroy_image(data->mlx, data->image);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
//	ft_putnbr(key);
//	ft_putchar('\n');
	if (key == 86)
		data->roty -= 0.0174533 * 1;
	if (key == 88)
		data->roty += 0.0174533 * 1;
	if (key == 84)
		data->rotx -= 0.0174533 * 1;
	if (key == 91)
		data->rotx += 0.0174533 * 1;
	if (key == 83)
		data->rotz += 0.0174533 * 1;
	if (key == 85)
		data->rotz -= 0.0174533 * 1;
	if (key == 49)
		data->do_move = 1;
	else if (key == 53)
		data->do_move = 0;
	if (key == 87)
	{
		data->x = 500;
		data->y = 500;
		data->scl = 50;
		data->zz = 0.25;
		data->rotx = 0.0174533 * 70;
		data->roty = 0.0174533 * 30;
		data->rotz = 0.0174533 * -10;
	}
//	printf("x = %d y = %d\n", data->x, data->y);
	mlx_string_put(data->mlx, data->win, 50, 50, 0xFFFF00, "Coucou");
	draw_grid(data);
	return (0);
}
