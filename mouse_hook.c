/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 17:08:49 by tfleming          #+#    #+#             */
/*   Updated: 2015/02/14 17:11:33 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_hook(int button, int x, int y, t_environment *env)
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
