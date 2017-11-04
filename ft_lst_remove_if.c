/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:27:11 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:30:53 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lst_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;
	t_list *todel;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	tmp = *begin_list;
	while (tmp && !(*cmp)(tmp->content, data_ref))
	{
		todel = tmp;
		tmp = tmp->next;
		free(todel);
		*begin_list = tmp;
	}
	while (tmp && tmp->next)
	{
		if (!(*cmp)(tmp->next->content, data_ref))
		{
			todel = tmp->next;
			tmp->next = tmp->next->next;
			free(todel);
			continue ;
		}
		tmp = tmp->next;
	}
}
