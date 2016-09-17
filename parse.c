/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 07:01:53 by aviau             #+#    #+#             */
/*   Updated: 2016/09/17 03:58:48 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		conv(char *line, int	**grid)
{
	int		i;
	int		j;
	int		c;
	char	*num;

	i = 0;
	j = 0;
	c = 0;
	ft_putstr("test\n");
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		j = i;
		while (line[i] != ' ')
			j++;
		num = ft_strncpy(num, &line[i], j - i);
		ft_putstr(num);
		*grid[c] = ft_atoi(num);
		free(num);
		c++;
		i++;
	}
	return (c);
}

void	ex_err(void)
{
	ft_putstr("usage : ./fdf <file>\n");
	exit(1);
}

int		**parse(char *file, t_e *data)
{
	int 	fd;
	int		c;
	int 	size;
	int		**grid;
	char	*line;

	if (file == NULL)
		ex_err();
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		c++;
	}
	grid = (int **)ft_memalloc(sizeof(int *) * c);
	c = -1;
	close(fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		 size = conv(line, &grid[c]);
		 if (size > data->imax)
			 data->imax = size;
		 free(line);
		 c++;
	}
	data->jmax = c;
	return (grid);
}
