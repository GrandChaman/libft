/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 13:04:55 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/06 11:44:26 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree *new;

	if (!(new = malloc(sizeof(t_btree))))
		return (NULL);
	new->item = item;
	new->left = NULL;
	new->right = NULL;
	new->parent = NULL;
	return (new);
}
