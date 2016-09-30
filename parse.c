/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 07:01:53 by aviau             #+#    #+#             */
/*   Updated: 2016/09/30 03:58:03 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		lenght(char *line)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i])
	{
		while (line[i] != ' ' && line[i])
			i++;
		c++;
		while (line[i] == ' ' && line[i])
			i++;
	}
	return (c);
}

int		conv(int **grid, char *line, int size)
{
	int			i;
	int			c;
	static int	max = 0;

	i = 0;
	c = 0;
	*grid = (int *)ft_memalloc(sizeof(int) * size);
	while (line[i])
	{
		if (line[i] == ',')
			while (line[i] != ' ')
				i++;
		while (line[i] && line[i] == ' ')
			i++;
		grid[0][c] = ft_atoi(&line[i]);
		if (grid[0][c] >= max)
			max = grid[0][c];
		c++;
		while (line[i] && line[i] != ' ' && line[i] != ',')
			i++;
	}
	return (max);
}

void	ex_err(void)
{
	ft_putstr("usage : ./fdf <file>\n");
	exit(1);
}

int		mem(t_e *data, int c, int fd)
{
	data->grid = (int **)ft_memalloc(sizeof(int *) * (c + 1));
	data->grid[c] = NULL;
	data->jmax = c;
	close(fd);
	return (0);
}

int		parse(char *file, t_e *data)
{
	int		fd;
	int		c;
	int		size;
	char	*line;

	if (file == NULL)
		ex_err();
	fd = open(file, O_RDONLY);
	c = 0;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		c++;
	}
	c = mem(data, c, fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		size = lenght(line);
		if (size > data->imax)
			data->imax = size;
		data->zmax = conv(&data->grid[c++], line, size);
		free(line);
	}
	return (0);
}
