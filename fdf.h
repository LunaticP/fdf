#ifndef FDF_H
# define FDF_H

# include "libmlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"
# include <math.h>

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

typedef struct	s_matrix
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
}				t_matrix;

typedef struct	s_e
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*addr;
	int			bpp;
	int			l_size;
	int			endian;
	int			x;
	int			y;
	int			z;
	float		scl;
	float		zz;
	float		imax;
	float		jmax;
	float		xmax;
	float		ymax;
	float		zmax;
	int			color;
	float		rotx;
	float		roty;
	float		rotz;
	int			**grid;
	int			lastx;
	int			lasty;
	int			do_move;
	t_matrix	mtrx;
}				t_e;

typedef struct	s_draw
{
	float	tx;
	float	ty;
	float	tz;
	float	tx2;
	float	ty2;
	float	tz2;
	float	x;
	float	y;
	float	z;
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
