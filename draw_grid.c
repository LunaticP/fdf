/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:51:29 by aviau             #+#    #+#             */
/*   Updated: 2016/09/25 06:38:42 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	c_x(t_e *d, t_draw *x)
{
	x->x = x->tx;
	x->x2 = x->tx2;
	x->y = x->ty * cos(d->rotx) - x->tz * sin(d->rotx);
	x->y2 = x->ty2 * cos(d->rotx) - x->tz2 * sin(d->rotx);
	x->z = x->y * sin(d->rotx) + x->tz * cos(d->rotx);
	x->z2 = x->y2 * sin(d->rotx) + x->tz2 * cos(d->rotx);
}

void	c_y(t_e *d, t_draw *x)
{
	x->x = x->x * cos(d->roty) + x->z * sin(d->roty);
	x->x2 = x->x2 * cos(d->roty) + x->z2 * sin(d->roty);
	x->y = x->y;
	x->y2 = x->y2;
	x->z = x->x * sin(d->roty) * -1 + x->z * cos(d->roty);
	x->z2 = x->x2 * sin(d->roty) * -1 + x->z2 * cos(d->roty);
}

void	c_z(t_e *d, t_draw *x)
{
	x->x = x->x * cos(d->rotz) - x->y * sin(d->rotz);
	x->x2 = x->x2 * cos(d->rotz) - x->y2 * sin(d->rotz);
	x->y = x->x * sin(d->rotz) + x->y * cos(d->rotz);
	x->y2 = x->x2 * sin(d->rotz) + x->y2 * cos(d->rotz);
	x->z = x->z;
	x->z2 = x->z2;
}

void	calc(t_e *d, t_draw *x, int j, int i)
{
	x->tx = ((double)i - ((double)(d->imax - 1) / 2)) * d->xx;
	x->ty = ((double)j - ((double)(d->jmax - 1) / 2)) * d->yy;
	x->tz = (double)d->grid[j][i] * d->zz;
	if (j < d->jmax - 1)
	{
		x->tx2 = ((double)i - ((double)(d->imax - 1) / 2)) * d->xx;
		x->ty2 = ((double)j - ((double)(d->jmax - 1) / 2) + 1) * d->yy;
		x->tz2 = (double)d->grid[j + 1][i] * d->zz;
		c_x(d, x);
		c_y(d, x);
		c_z(d, x);
		draw_line(d, x);
	}
	if (i < d->imax - 1)
	{
		x->tx2 = ((double)i - ((double)(d->imax - 1) / 2) + 1) * d->xx;
		x->ty2 = ((double)j - ((double)(d->jmax - 1) / 2)) * d->yy;
		x->tz2 = (double)d->grid[j][i + 1] * d->zz;
		c_x(d, x);
		c_y(d, x);
		c_z(d, x);
		draw_line(d, x);
	}
}

void	draw_grid(t_e *d)
{
	int		i;
	int		j;
	t_draw	x;

	mlx_destroy_image(d->mlx, d->image);
	d->image = mlx_new_image(d->mlx, 1000, 1000);
	d->addr = mlx_get_data_addr(d->image, &d->bpp, &d->l_size, &d->endian);
	j = 0;
	while (j < d->jmax)
	{
		i = 0;
		while (i < d->imax)
		{
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putstr(" j = ");
			ft_putnbr(j);
			ft_putstr("\n");
			calc(d, &x, j, i);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->image, 0, 0);
}
