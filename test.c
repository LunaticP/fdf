/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 10:56:54 by aviau             #+#    #+#             */
/*   Updated: 2016/09/18 11:12:01 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int i;
	int color;

	i = 0;
	color = 0;
	while (i <= 255)
	{
		printf("i = \e[33m%d\e[0m   color = \e[36m0x%06x\e[0m\n", i, color);
		i++;
		color += 256 * 256;
	}
	return (0);
}
