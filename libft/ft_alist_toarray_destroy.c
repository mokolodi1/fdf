/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alist_to_array_destroy.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 18:06:54 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/29 16:22:55 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array			*ft_alist_toarray_destroy(t_alist *list)
{
	t_array	*array;

	array = ft_alist_toarray(list);
	ft_alist_free(list, &free);
	return (array);
}
