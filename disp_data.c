/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 08:15:47 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 12:08:27 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*freejoin(char *dst, char *src)
{
	char	*tmp;

	tmp = src;
	dst = ft_strjoin(dst, src);
	free(tmp);
	return (dst);
}

static void	disp_rgb(t_e *d)
{
	char	*str1;
	char	*str2;
	char	*rgb[3];

	str1 = freejoin("R: ", ft_itoa(d->r_s));
	str2 = freejoin(" - r: ", ft_itoa(d->r_e));
	rgb[0] = free_join(str1, str2);
	free(str2);
	mlx_string_put(d->mlx, d->win, 10, 110, 0xFF0000, rgb[0]);
	free(rgb[0]);
	str1 = freejoin("G: ", ft_itoa(d->g_s));
	str2 = freejoin(" - g: ", ft_itoa(d->g_e));
	rgb[1] = free_join(str1, str2);
	free(str2);
	mlx_string_put(d->mlx, d->win, 10, 130, 0xFF00, rgb[1]);
	free(rgb[1]);
	str1 = freejoin("B: ", ft_itoa(d->b_s));
	str2 = freejoin(" - b: ", ft_itoa(d->b_e));
	rgb[2] = free_join(str1, str2);
	free(str2);
	mlx_string_put(d->mlx, d->win, 10, 150, 0xFF, rgb[2]);
	free(rgb[2]);
}

static void	disp_xy_zz(t_e *d)
{
	char	*str1;
	char	*str2;
	char	*xy;
	char	*zz;

	str1 = freejoin("x: ", ft_itoa(d->x));
	str2 = freejoin("   y: ", ft_itoa(d->y));
	xy = free_join(str1, str2);
	free(str2);
	mlx_string_put(d->mlx, d->win, 10, 35, 0xFF0000, xy);
	free(xy);
	zz = freejoin("height: ", ft_itoa(-d->zz * 10));
	mlx_string_put(d->mlx, d->win, 10, 60, 0xFF00, zz);
	free(zz);
}

void		disp_data(t_e *d)
{
	char	*str1;
	char	*str2;
	char	*data;
	char	*name;

	name = ft_strjoin("map: ", d->name);
	mlx_string_put(d->mlx, d->win, 10, 10, 0x7777FF, name);
	free(name);
	disp_xy_zz(d);
	str1 = freejoin("FOV: ", ft_itoa(d->fov));
	str2 = freejoin("   scale: ", ft_itoa(d->scl));
	data = free_join(str1, str2);
	free(str2);
	mlx_string_put(d->mlx, d->win, 10, 85, 0xFF00FF, data);
	free(data);
	if (d->do_color)
		disp_rgb(d);
}
