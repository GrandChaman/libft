/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:43:13 by fle-roy           #+#    #+#             */
/*   Updated: 2017/12/03 11:55:09 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree *new;

	if (!root)
		return ;
	if (!(*root))
	{
		new = ft_btree_create_node(item);
		*root = new;
		return ;
	}
	if (cmpf((*root)->item, item) <= 0)
	{
		if ((*root)->right)
			ft_btree_insert_data(&((*root)->right), item, cmpf);
		else
			(*root)->right = ft_btree_create_node(item);
	}
	else
	{
		if ((*root)->left)
			ft_btree_insert_data(&((*root)->left), item, cmpf);
		else
			(*root)->left = ft_btree_create_node(item);
	}
}
