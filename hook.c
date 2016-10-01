/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <aviau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 04:29:58 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 13:08:33 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rev_col(t_e *d)
{
	int r;
	int g;
	int b;

	r = d->r_s;
	g = d->g_s;
	b = d->b_s;
	d->r_s = d->r_e;
	d->g_s = d->g_e;
	d->b_s = d->b_e;
	d->r_e = r;
	d->g_e = g;
	d->b_e = b;
}

int		keypress(int key, t_e *d)
{
	if (d->do_move == 0 && SPACE)
		d->do_move = 1;
	else if (d->do_move == 1 && SPACE)
		d->do_move = 0;
	if (KEY_C && d->do_color == 0)
		d->do_color = 1;
	else if (KEY_C && d->do_color == 1)
		d->do_color = 0;
	if (ESC)
	{
		mlx_destroy_image(d->mlx, d->image);
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
	c_pattern(key, d);
	p_scale_fov_more(key, d);
	p_rot_trans(key, d);
	p_col_modif(key, d);
	return (0);
}

int		keyrel(int key, t_e *d)
{
	if (KP_5)
	{
		d->x = 1200;
		d->y = 675;
		d->scl = 40;
		d->fov = 60;
		d->zz = -0.2;
		d->m.x.x = 0.817374;
		d->m.x.y = -0.187947;
		d->m.x.z = 0.544589;
		d->m.y.x = 0.451567;
		d->m.y.y = 0.796020;
		d->m.y.z = -0.403037;
		d->m.z.x = -0.357754;
		d->m.z.y = 0.575350;
		d->m.z.z = 0.735516;
	}
	if (NUM_0)
		rev_col(d);
	r_scale_fov_more(key, d);
	r_rot_trans(key, d);
	r_col_modif(key, d);
	return (0);
}
