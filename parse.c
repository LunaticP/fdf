/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 07:01:53 by aviau             #+#    #+#             */
/*   Updated: 2016/09/17 05:28:58 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		lenght(char *line)
{
	int	i;
	int c;

	i = 0;
	c = 0;
	ft_putstr(line);
	ft_putchar(' ');
	while (line[i])
	{
		c++;
		while (line[i] == ' ')
			i++;
		while (line[i] != ' ')
			i++;
		i++;
	}
	ft_putnbr(c);
	ft_putchar('\n');
	return (c);
}

int		conv(char *line, int	**grid)
{
	int		i;
	int		j;
	int		c;
	char	*num;

	i = 0;
	j = 0;
	c = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		j = i;
		while (line[j] != ' ')
			j++;
		num = ft_strncpy(num, &line[i], j - i);
		*grid[c] = ft_atoi(num);
		ft_putnbr(*grid[c]);
		ft_putchar('-');
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
	ft_putnbr(c);
	ft_putchar('\n');
	grid = (int **)ft_memalloc(sizeof(int *) * c);
	c = 0;
	close(fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		grid[c] = (int *)ft_memalloc(sizeof(int) * lenght(line));
		size = conv(line, &grid[c]);
		if (size > data->imax)
			data->imax = size;
		free(line);
		c++;
	}
	data->jmax = c;
	return (grid);
}
