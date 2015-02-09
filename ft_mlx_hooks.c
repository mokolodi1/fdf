/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 20:57:14 by tfleming          #+#    #+#             */
/*   Updated: 2015/01/31 17:58:31 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_expose_hook(t_environment *env)
{
	draw(env);
	return (0);
}

int		ft_key_hook(int keycode, t_environment *env)
{
	(void)env;
	ft_putstr("key: ");
	ft_putnbr(keycode);
	ft_putstr("\n");
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, t_environment *env)
{
	(void)env;
	ft_putstr("x = ");
	ft_putnbr(x);
	ft_putstr("\ty = ");
	ft_putnbr(y);
	ft_putstr("\tbutton = ");
	ft_putnbr(button);
	ft_putchar('\n');
	return (0);
}
