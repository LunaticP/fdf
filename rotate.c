/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 00:48:46 by aviau             #+#    #+#             */
/*   Updated: 2016/09/28 00:48:48 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	c_x(float rot, t_vec *vec)
{
	t_vec	tmp;

	tmp = (t_vec){vec->x, vec->y, vec->z};
	vec->x = tmp.x;
	vec->y = tmp.y * cos(rot) - tmp.z * sin(rot);
	vec->z = tmp.y * sin(rot) + tmp.z * cos(rot);
}

void	c_y(float rot, t_vec *vec)
{
	t_vec	tmp;

	tmp = (t_vec){vec->x, vec->y, vec->z};
	vec->x = tmp.x * cos(rot) + tmp.z * sin(rot);
	vec->y = tmp.y;
	vec->z = tmp.x * sin(rot) * -1 + tmp.z * cos(rot);
}

void	c_z(float rot, t_vec *vec)
{
	t_vec	tmp;

	tmp = (t_vec){vec->x, vec->y, vec->z};
	vec->x = tmp.x * cos(rot) - tmp.y * sin(rot);
	vec->y = tmp.x * sin(rot) + tmp.y * cos(rot);
	vec->z = tmp.z;
}
