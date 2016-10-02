/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 07:43:39 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 06:15:16 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	r_rot_trans(int key, t_e *d)
{
	if ((d->key & ROT_XP) && KP_8)
		d->key -= ROT_XP;
	if ((d->key & ROT_XM) && KP_2)
		d->key -= ROT_XM;
	if ((d->key & ROT_YP) && KP_6)
		d->key -= ROT_YP;
	if ((d->key & ROT_YM) && KP_4)
		d->key -= ROT_YM;
	if ((d->key & ROT_ZP) && KP_1)
		d->key -= ROT_ZP;
	if ((d->key & ROT_ZM) && KP_3)
		d->key -= ROT_ZM;
	if ((d->key & POS_XP) && RIGHT)
		d->key -= POS_XP;
	if ((d->key & POS_XM) && LEFT)
		d->key -= POS_XM;
	if ((d->key & POS_YP) && DOWN)
		d->key -= POS_YP;
	if ((d->key & POS_YM) && UP)
		d->key -= POS_YM;
	if ((d->key & POS_ZP) && KP_P)
		d->key -= POS_ZP;
	if ((d->key & POS_ZM) && KP_M)
		d->key -= POS_ZM;
}

void	r_col_modif(int key, t_e *d)
{
	if ((d->key & CO_RED) && KEY_R)
		d->key -= CO_RED;
	if ((d->key & CO_GRE) && KEY_G)
		d->key -= CO_GRE;
	if ((d->key & CO_BLU) && KEY_B)
		d->key -= CO_BLU;
}

void	r_scale_fov_more(int key, t_e *d)
{
	if ((d->key & P_CTRL) && CTRL)
		d->key -= P_CTRL;
	if ((d->key & PSHIFT) && SHIFT)
		d->key -= PSHIFT;
	if ((d->key & FVIEWP) && KP_9)
		d->key -= FVIEWP;
	if ((d->key & FVIEWM) && KP_7)
		d->key -= FVIEWM;
	if ((d->key & SCALEP) && KP_F)
		d->key -= SCALEP;
	if ((d->key & SCALEM) && KP_D)
		d->key -= SCALEM;
}
