/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 14:17:47 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 17:51:03 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"

/*
** mlx.h: MiniLibX functions
** fcntl.h: open()
** math.h: math functions
** climits.h: INT_MIN
*/

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <limits.h>

typedef struct	s_environment
{
	void		*mlx;
	void		*window;
	t_intarr	*array;
	int			height;
	int			width;
	int			left_const;
	int			right_const;
	int			z_const;
}				t_environment;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}				t_point;

typedef struct	s_drawer
{
	int		x_slope;
	int		y_slope;
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	int		error;
}				t_drawer;

# define INPUT_SPLIT_ON		' '
# define WINDOW_TITLE		"fdf"
# define PIXEL_HEIGHT		1000
# define PIXEL_WIDTH		1000

# define KEY_ESC			65307
# define KEY_SHIFT			65506

# define MLX_MAX_COLOR		0xFFFFFF
# define COLOR_RANGE		20

int				main(int argc, char **argv);
void			fdf(t_intarr *array, int pixel_width, int pixel_height);

void			ft_mlx_draw_line(t_environment *env
									, t_point *start, t_point *end);
int				ft_mlx_to_color(int red, int green, int blue);

void			draw(t_environment *env);

int				ft_expose_hook(t_environment *env);
int				ft_key_hook(int keycode, t_environment *env);
int				ft_mouse_hook(int button, int x, int y, t_environment *env);

#endif
