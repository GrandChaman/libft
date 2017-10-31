/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:01:02 by bluff             #+#    #+#             */
/*   Updated: 2017/10/31 18:15:01 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list*		ft_lstmap(t_list *lst, t_list* (*f)(t_list *elem))
{
	t_list *nlist;
	t_list *bckup;

	bckup = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!bckup)
		{
			nlist = f(lst);
			bckup = nlist;
		}
		else
		{
			nlist->next = f(lst);
			nlist = nlist->next;
		}
		lst = lst->next;
	}
	nlist->next = NULL;
	return (bckup);
}
