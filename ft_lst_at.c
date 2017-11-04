/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:00:19 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:27:07 by bluff            ###   ########.fr       */
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
