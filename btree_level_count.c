/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:18:00 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/06 11:44:25 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	btree_level_count(t_btree *root)
{
	int l;
	int r;

	l = 0;
	r = 0;
	if (!root)
		return (0);
	if (root->left)
		l = btree_level_count(root->left);
	if (root->right)
		r = btree_level_count(root->right);
	if (l >= r)
		return (l + 1);
	else
		return (r + 1);
}
