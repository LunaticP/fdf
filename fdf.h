#ifndef FDF_H
# define FDF_H

# include "libmlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <math.h>


typedef struct	s_e
{
	void	*mlx;
	void	*win;
	void	*image;
	char	*addr;
	int		bpp;
	int		l_size;
	int		endian;
	int		x;
	int		y;
	int		z;
	double	xx;
	double	yy;
	double	zz;
	double	imax;
	double	jmax;
	double	xmax;
	double	ymax;
	double	zmax;
	int		color;
	double	rotx;
	double	roty;
	double	rotz;
	int		**grid;
	int		lastx;
	int		lasty;
	int		do_move;
}				t_e;

typedef struct	s_draw
{
	double	tx;
	double	ty;
	double	tz;
	double	tx2;
	double	ty2;
	double	tz2;
	double	x;
	double	y;
	double	z;
	int		x2;
	int		y2;
	int		z2;
	int		color;
	int		color2;
}				t_draw;

void	draw_line(t_e *data, t_draw *X);
void	draw_grid(t_e *d);
int		parse(char *file, t_e *data);
int		ft_abs(int num);
int		mouse(int x, int y, t_e *data);
int		keyboard(int key, t_e *data);

#endif
