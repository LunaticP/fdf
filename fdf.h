#ifndef FDF_H
# define FDF_H

# include "sources/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <math.h>


typedef struct	s_e
{
	void	*mlx;
	void	*win;
	void	*image;
	int		x;
	int		y;
	int		color;
	int		h_max;
	float	rot;
	int		**grid;
	int		xx;
	int		yy;
	int		ymax;
	int		imax;
	int		jmax;
	double	h;
	int		lastx;
	int		lasty;
	int		do_move;
	char	*addr;
	int		bpp;
	int		l_size;
	int		endian;
}				t_e;

void	draw_line(t_e *X, double x, double y, int x2, int y2, int color, int color2);
int		parse(char *file, t_e *data);

#endif
