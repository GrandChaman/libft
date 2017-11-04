/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:00:42 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:29:07 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lst_last(t_list *begin_list)
{
	if (begin_list == NULL)
		return (NULL);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}
