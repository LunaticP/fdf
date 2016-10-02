/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 08:22:12 by aviau             #+#    #+#             */
/*   Updated: 2016/10/02 02:20:14 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "key.h"
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

typedef struct		s_matrix
{
	t_vec			x;
	t_vec			y;
	t_vec			z;
}					t_matrix;

typedef struct		s_e
{
	void			*mlx;
	void			*win;
	void			*image;
	char			*addr;
	int				bpp;
	int				l_size;
	int				endian;
	int				x;
	int				y;
	float			scl;
	float			zz;
	float			imax;
	float			jmax;
	float			zmax;
	int				lastx;
	int				lasty;
	int				color;
	int				**grid;
	int				do_move;
	float			fov;
	char			*name;
	short			do_shadow;
	short			do_color;
	int				r_s;
	int				r_e;
	int				g_s;
	int				g_e;
	int				b_s;
	int				b_e;
	unsigned int	key;
	t_matrix		m;
}					t_e;

typedef struct		s_draw
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
}					t_draw;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	float			start;
	float			end;
	float			step;
}					t_color;

void				draw_line(t_e *data, t_draw *x);
void				draw_grid(t_e *d);
int					parse(char *file, t_e *data);
float				ft_abs(float num);
int					mouse(int x, int y, t_e *data);
int					keypress(int key, t_e *data);
int					keyrel(int key, t_e *data);
void				c_x(float rot, t_vec *vec);
void				c_y(float rot, t_vec *vec);
void				c_z(float rot, t_vec *vec);
void				disp_data(t_e *d);
void				p_scale_fov_more(int key, t_e *d);
void				p_rot_trans(int key, t_e *d);
void				p_col_modif(int key, t_e *d);
void				r_scale_fov_more(int key, t_e *d);
void				r_rot_trans(int key, t_e *d);
void				r_col_modif(int key, t_e *d);
void				key_color(int keys, t_e *data, short shift, short ctrl);
void				key_sclfov_trans(int keys, t_e *data);
void				key_rotx(int keys, t_e *data);
void				key_roty(int keys, t_e *data);
void				key_rotz(int keys, t_e *data);
void				disp_data(t_e *d);
void				c_pattern(int key, t_e *d);
char				*free_join(char *dst, char *src);

#endif
