#ifndef FDF_H
# define FDF_H

# include "sources/mlx.h"
# include "libft/libft.h"
# include <math.h>


typedef struct	s_e
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	float	rot;
	void	*grid;
}				t_e;

void	draw_line(t_e *X, double x, double y, int x2, int y2);

#endif