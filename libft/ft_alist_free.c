/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alist_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:07:38 by tfleming          #+#    #+#             */
/*   Updated: 2014/11/29 23:17:49 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_alist_free(t_alist *list, t_free_item free_item)
{
	size_t		i;
	size_t		count;

	if (free_item)
	{
		count = ft_alist_count(list);
		i = 0;
		while (i < count)
		{
			free_item(list->array[i]);
			i++;
		}
	}
	free(list);
}
