/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_pattern.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 13:03:59 by aviau             #+#    #+#             */
/*   Updated: 2016/10/01 13:17:22 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	c_pattern4(int key, t_e *d)
{
	if (NUM_7)
	{
		d->r_e = 128;
		d->g_e = 128;
		d->b_e = 128;
		d->r_s = 128;
		d->g_s = 128;
		d->b_s = 128;
	}
	if (NUM_8)
	{
		d->r_e = 128;
		d->g_e = 128;
		d->b_e = 128;
		d->r_s = 128;
		d->g_s = 128;
		d->b_s = 128;
	}
}

void	c_pattern3(int key, t_e *d)
{
	if (NUM_5)
	{
		d->r_e = 128;
		d->g_e = 50;
		d->b_e = 25;
		d->r_s = 255;
		d->g_s = 32;
		d->b_s = 16;
	}
	if (NUM_6)
	{
		d->r_e = 128;
		d->g_e = 128;
		d->b_e = 128;
		d->r_s = 128;
		d->g_s = 128;
		d->b_s = 128;
	}
	c_pattern4(key, d);
}

void	c_pattern2(int key, t_e *d)
{
	if (NUM_3)
	{
		d->r_e = 0;
		d->g_e = 181;
		d->b_e = 255;
		d->r_s = 255;
		d->g_s = 152;
		d->b_s = 235;
	}
	if (NUM_4)
	{
		d->r_e = 70;
		d->g_e = 0;
		d->b_e = 255;
		d->r_s = 255;
		d->g_s = 61;
		d->b_s = 183;
	}
	c_pattern3(key, d);
}

void	c_pattern(int key, t_e *d)
{
	if (NUM_1)
	{
		d->r_e = 128;
		d->g_e = 64;
		d->b_e = 0;
		d->r_s = 0;
		d->g_s = 255;
		d->b_s = 0;
	}
	if (NUM_2)
	{
		d->r_e = 0;
		d->g_e = 0;
		d->b_e = 0;
		d->r_s = 255;
		d->g_s = 255;
		d->b_s = 255;
	}
	c_pattern2(key, d);
}
