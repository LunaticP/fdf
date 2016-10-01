/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmphook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 08:23:56 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 08:12:58 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_color(int keys, t_e *data, short shift, short ctrl)
{
	if (!ctrl && !shift && (keys & CO_RED) && data->r_e < 255)
		data->r_e++;
	if (!ctrl && shift && (keys & CO_RED) && data->r_e > 0)
		data->r_e--;
	if (!ctrl && !shift && (keys & CO_GRE) && data->g_e < 255)
		data->g_e++;
	if (!ctrl && shift && (keys & CO_GRE) && data->g_e > 0)
		data->g_e--;
	if (!ctrl && !shift && (keys & CO_BLU) && data->b_e < 255)
		data->b_e++;
	if (!ctrl && shift && (keys & CO_BLU) && data->b_e > 0)
		data->b_e--;
	if (ctrl && !shift && (keys & CO_RED) && data->r_s < 255)
		data->r_s++;
	if (ctrl && shift && (keys & CO_RED) && data->r_s > 0)
		data->r_s--;
	if (ctrl && !shift && (keys & CO_GRE) && data->g_s < 255)
		data->g_s++;
	if (ctrl && shift && (keys & CO_GRE) && data->g_s > 0)
		data->g_s--;
	if (ctrl && !shift && (keys & CO_BLU) && data->b_s < 255)
		data->b_s++;
	if (ctrl && shift && (keys & CO_BLU) && data->b_s > 0)
		data->b_s--;
}

void	key_sclfov_trans(int keys, t_e *data)
{
	if (keys & FVIEWP)
		data->fov *= 1.02;
	if (keys & FVIEWM)
		data->fov /= 1.02;
	if (keys & SCALEP)
		data->scl *= 1.02;
	if (keys & SCALEM)
		data->scl /= 1.02;
	if (keys & POS_XP)
		data->x += 5;
	if (keys & POS_XM)
		data->x -= 5;
	if (keys & POS_YP)
		data->y += 5;
	if (keys & POS_YM)
		data->y -= 5;
	if (keys & POS_ZP)
		data->zz -= 0.02;
	if (keys & POS_ZM)
		data->zz += 0.02;
}

void	key_rotx(int keys, t_e *data)
{
	if (keys & ROT_XP)
	{
		c_x(-0.05, &data->m.x);
		c_x(-0.05, &data->m.y);
		c_x(-0.05, &data->m.z);
	}
	if (keys & ROT_XM)
	{
		c_x(0.05, &data->m.x);
		c_x(0.05, &data->m.y);
		c_x(0.05, &data->m.z);
	}
}

void	key_roty(int keys, t_e *data)
{
	if (keys & ROT_YP)
	{
		c_y(-0.05, &data->m.x);
		c_y(-0.05, &data->m.y);
		c_y(-0.05, &data->m.z);
	}
	if (keys & ROT_YM)
	{
		c_y(0.05, &data->m.x);
		c_y(0.05, &data->m.y);
		c_y(0.05, &data->m.z);
	}
}

void	key_rotz(int keys, t_e *data)
{
	if (keys & ROT_ZP)
	{
		c_z(0.05, &data->m.x);
		c_z(0.05, &data->m.y);
		c_z(0.05, &data->m.z);
	}
	if (keys & ROT_ZM)
	{
		c_z(-0.05, &data->m.x);
		c_z(-0.05, &data->m.y);
		c_z(-0.05, &data->m.z);
	}
}
