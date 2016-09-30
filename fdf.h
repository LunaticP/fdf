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
	float		scl;
	float		zz;
	float		imax;
	float		jmax;
	float		zmax;
	float		zbufmax;
	float		shadow;
	int			lastx;
	int			lasty;
	int			color;
	int			**grid;
	int			do_move;
	float		fov;
	char		*name;
	short		do_shadow;
	short		do_color;
	int			r_s;
	int			r_e;
	int			g_s;
	int			g_e;
	int			b_s;
	int			b_e;
	t_matrix	m;
}				t_e;

typedef struct	s_draw
{
	float			c;
	float			c2;
	float			tx;
	float			ty;
	float			tz;
	float			tx2;
	float			ty2;
	float			tz2;
	float			x;
	float			y;
	float			z;
	float			x2;
	float			y2;
	float			z2;
}				t_draw;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
	float	start;
	float	end;
	float	step;
}				t_color;

void	draw_line(t_e *data, t_draw *X);
void	draw_grid(t_e *d);
int		parse(char *file, t_e *data);
float	ft_abs(float num);
int		mouse(int x, int y, t_e *data);
int		keyboard(int key, t_e *data);
void	c_x(float rot, t_vec *vec);
void	c_y(float rot, t_vec *vec);
void	c_z(float rot, t_vec *vec);

#endif
