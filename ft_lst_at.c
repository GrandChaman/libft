/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:41:20 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/06 11:41:24 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lst_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (begin_list == NULL)
		return (NULL);
	while (i++ < nbr && begin_list)
		begin_list = begin_list->next;
	return (begin_list);
}
