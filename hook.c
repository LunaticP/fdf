/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 13:36:56 by aviau             #+#    #+#             */
/*   Updated: 2016/09/30 03:41:12 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	disp_data(t_e *d)
{
	char	*xy;
	char	*zz;
	char	*name;
	char	*data;
	char	*rgb[3];

	name = ft_strjoin("map: ", d->name);
	mlx_string_put(d->mlx, d->win, 10, 10, 0x7777FF, name);
	xy = ft_strjoin(ft_strjoin("x: ", ft_itoa(d->x)), ft_strjoin("   y: ", ft_itoa(d->y)));
	mlx_string_put(d->mlx, d->win, 10, 35, 0xFF0000, xy);
	zz = ft_strjoin("height: ", ft_itoa(d->zz));
	mlx_string_put(d->mlx, d->win, 10, 60, 0xFF00, zz);
	data = ft_strjoin("FOV: ", ft_itoa(d->fov));
	data = ft_strjoin(data, ft_strjoin("   scale: ", ft_itoa(d->scl)));
	mlx_string_put(d->mlx, d->win, 10, 85, 0xFF00FF, data);
	rgb[0] = ft_strjoin(ft_strjoin("R: ", ft_itoa(d->r_e)), ft_strjoin(" - r: ", ft_itoa(d->r_s)));
	rgb[1] = ft_strjoin(ft_strjoin("G: ", ft_itoa(d->g_e)), ft_strjoin(" - g: ", ft_itoa(d->g_s)));
	rgb[2] = ft_strjoin(ft_strjoin("B: ", ft_itoa(d->b_e)), ft_strjoin(" - b: ", ft_itoa(d->b_s)));
	mlx_string_put(d->mlx, d->win, 10, 110, 0xFF0000, rgb[0]);
	mlx_string_put(d->mlx, d->win, 10, 130, 0xFF00, rgb[1]);
	mlx_string_put(d->mlx, d->win, 10, 150, 0xFF, rgb[2]);
}

int		mouse(int x, int y, t_e *data)
{
	if (data->do_move)
	{
		double	a;
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
		if (y > data->lasty)
		{
			a = 0.015 * (y - data->lasty);
			c_x(a, &data->m.x);
			c_x(a, &data->m.y);
			c_x(a, &data->m.z);
			data->lasty = y;
		}
		if (y < data->lasty)
		{
			a = -0.015 * (data->lasty - y);
			c_x(a, &data->m.x);
			c_x(a, &data->m.y);
			c_x(a, &data->m.z);
			data->lasty = y;
		}
	}
	draw_grid(data);
	disp_data(data);
	return (0);
}

int		keyboard(int key, t_e *data)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 16 && data->r_e < 255)
		data->r_e++;
	if (key == 32 && data->r_e > 0)
		data->r_e--;
	if (key == 38 && data->g_e < 255)
		data->g_e++;
	if (key == 40 && data->g_e > 0)
		data->g_e--;
	if (key == 46 && data->b_e < 255)
		data->b_e++;
	if (key == 43 && data->b_e > 0)
		data->b_e--;

	if (key == 15 && data->r_s < 255)
		data->r_s++;
	if (key == 17 && data->r_s > 0)
		data->r_s--;
	if (key == 5 && data->g_s < 255)
		data->g_s++;
	if (key == 4 && data->g_s > 0)
		data->g_s--;
	if (key == 11 && data->b_s < 255)
		data->b_s++;
	if (key == 45 && data->b_s > 0)
		data->b_s--;

	if (key == 8 && data->do_color == 0)
		data->do_color = 1;
	else if (key == 8 && data->do_color == 1)
		data->do_color = 0;
	if (key == 1 && data->do_shadow == 0)
		data->do_shadow = 1;
	else if (key == 1 && data->do_shadow == 1)
		data->do_shadow = 0;
	if (key == 24)
		data->shadow *= 1.2;
	if (key == 27)
		data->shadow /= 1.2;
	if (key == 33)
		data->zbufmax *= 1.2;
	if (key == 30)
		data->zbufmax /= 1.2;
	if (key == 25)
		data->fov /= 1.02;
	if (key == 29)
		data->fov *= 1.02;
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
		data->zz += 0.1;
	if (key == 78)
		data->zz -= 0.1;
	else if (key == 12 || key == 53)
	{
		mlx_destroy_image(data->mlx, data->image);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	//	ft_putnbr(key);
	//	ft_putchar('\n');
	if (key == 86)
	{
		c_y(0.05, &data->m.x);
		c_y(0.05, &data->m.y);
		c_y(0.05, &data->m.z);
	}
	if (key == 88)
	{
		c_y(-0.05, &data->m.x);
		c_y(-0.05, &data->m.y);
		c_y(-0.05, &data->m.z);
	}
	if (key == 84)
	{
		c_x(0.05, &data->m.x);
		c_x(0.05, &data->m.y);
		c_x(0.05, &data->m.z);
	}
	if (key == 91)
	{
		c_x(-0.05, &data->m.x);
		c_x(-0.05, &data->m.y);
		c_x(-0.05, &data->m.z);
	}
	if (key == 83)
	{
		c_z(0.05, &data->m.x);
		c_z(0.05, &data->m.y);
		c_z(0.05, &data->m.z);
	}
	if (key == 85)
	{
		c_z(-0.05, &data->m.x);
		c_z(-0.05, &data->m.y);
		c_z(-0.05, &data->m.z);
	}
	if (key == 49 && data->do_move == 0)
		data->do_move = 1;
	else if (key == 49 && data->do_move == 1)
		data->do_move = 0;
	if (key == 87)
	{
		data->x = 1200;
		data->y = 700;
		data->scl = 50;
		data->fov = 60;
		data->zz = 0.25;
	}
	//	printf("x = %d y = %d\n", data->x, data->y);
	draw_grid(data);
	disp_data(data);
	return (0);
}
