/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlst_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 15:12:45 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/28 15:39:25 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** note: expects initial_length to be > 0
*/

t_alist			*ft_alist_new(size_t initial_length)
{
	t_alist		*new;

	new = malloc(sizeof(t_alist));
	new->length = initial_length;
	new->array = malloc(new->length * sizeof(void*));
	new->last = new->array - 1;
	return (new);
}
