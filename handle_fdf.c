/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 13:35:32 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/14 17:39:26 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			set_minimum_maximum(t_intarr *array
											, int *minimum, int *maximum)
{
	int				value;
	int				max;
	int				min;
	int				horizontal;
	int				vertical;

	vertical = 0;
	while (vertical < array->height)
	{
		horizontal = 0;
		while (horizontal < array->width)
		{
			value = array->data[vertical][horizontal];
			if (value < min)
				min = value;
			else if (value > max)
				max = value;
			horizontal++;
		}
		vertical++;
	}
	*minimum = min;
	*maximum = max;
}

static void			setup_environment(t_environment *env, t_intarr *array
										, int pixel_width, int pixel_height)
{
	env->mlx = mlx_init();
	env->window = mlx_new_window(env->mlx, pixel_width, pixel_height
								, WINDOW_TITLE_TEXT);
	env->array = array;
	env->width = pixel_width;
	env->height = pixel_height;
	env->left_const = 20;
	env->right_const = 20;
	env->z_const = 50;
	set_minimum_maximum(array, &env->minimum_value, &env->maximum_value);
}

void				handle_fdf(t_intarr *array
								, int pixel_width
								, int pixel_height)
{
	t_environment		env;

	setup_environment(&env, array, pixel_width, pixel_height);
	mlx_expose_hook(env.window, expose_hook, &env);
	mlx_key_hook(env.window, key_hook, &env);
	mlx_mouse_hook (env.window, mouse_hook, &env);
	mlx_loop(env.mlx);
}
