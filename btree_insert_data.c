/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:43:13 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:06:52 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	t_btree *new;

	if (!root)
		return ;
	if (!(*root))
	{
		new = btree_create_node(item);
		*root = new;
		return ;
	}
	if (cmpf((*root)->item, item) <= 0)
	{
		if ((*root)->right)
			btree_insert_data(&((*root)->right), item, cmpf);
		else
			(*root)->right = btree_create_node(item);
	}
	else
	{
		if ((*root)->left)
			btree_insert_data(&((*root)->left), item, cmpf);
		else
			(*root)->left = btree_create_node(item);
	}
}
