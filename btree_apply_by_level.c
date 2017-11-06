/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:02:41 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/06 11:44:29 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int g_wanted_lvl;

int		btree_level_count(t_btree *root)
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

void	btree_apply_prefix_if(t_btree *root, int current_level, int *fe,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	if (!root || !applyf)
		return ;
	if (current_level == g_wanted_lvl)
	{
		applyf(root->item, current_level, *fe);
		*fe = 0;
	}
	if (root->left)
		btree_apply_prefix_if(root->left, current_level + 1, fe, applyf);
	if (root->right)
		btree_apply_prefix_if(root->right, current_level + 1, fe, applyf);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	int l;
	int fe;

	fe = 1;
	g_wanted_lvl = 0;
	l = btree_level_count(root);
	while (g_wanted_lvl < l)
	{
		btree_apply_prefix_if(root, 0, &fe, applyf);
		g_wanted_lvl++;
		fe = 1;
	}
}
