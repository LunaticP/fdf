/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 16:15:31 by aviau             #+#    #+#             */
/*   Updated: 2016/09/17 16:25:12 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse(int x, int y, t_e *data)
{
	if (data->do_move)
	{
		printf("x : %d - y : %d\n", x, y);
		if (x < data->lastx)
		{
			data->rot -= 0.0174533 * (data->lastx - x);
			data->lastx = x;
		}
		if (x > data->lastx)
		{
			data->rot += 0.0174533 * (x - data->lastx);
			data->lastx = x;
		}
		if (y < data->lasty)
		{
			data->lasty = y;
			data->yy--;
		}
		if (y > data->lasty)
		{
			data->lasty = y;
			data->yy++;
		}
	}
	return (0);	
}

int		keyboard(int key, t_e *data)
{
	printf("key : \e[36m%d\e[0m\n", key);
	data->x += (key == 124) ? 5 : 0;
	data->x -= (key == 123) ? 5 : 0;
	data->y += (key == 125) ? 5 : 0;
	data->y -= (key == 126) ? 5 : 0;
	data->xx += (key == 67) ? 1 : 0;
	data->xx -= (key == 75) ? 1 : 0;
	data->h += (key == 69) ? 0.1 : 0;
	data->h -= (key == 78) ? 0.1 : 0;
	data->rot -= (key == 86) ? 0.0174533 * 3 : 0;
	data->rot += (key == 88) ? 0.0174533 * 3 : 0;
	data->yy -= (key == 84) ? 1 : 0;
	data->yy += (key == 91) ? 1 : 0;
	if (key == 49)
		data->do_move = 1;
	else if (key == 53)
		data->do_move = 0;
	else if (key == 87)
	{
		data->x = 30;
		data->y = 50;
		data->xx = 52;
		data->yy = 20;
		data->h = 13;
		data->rot = 5.040033;
	}
	else if (key == 12)
	{
		mlx_destroy_image (data->mlx, data->image);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
