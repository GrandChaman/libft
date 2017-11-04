/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 12:16:00 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:27:44 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_foreach(t_list *begin_list, void (*f)(void *))
{
	if (begin_list == NULL)
		return ;
	while (begin_list)
	{
		f(begin_list->content);
		begin_list = begin_list->next;
	}
}
