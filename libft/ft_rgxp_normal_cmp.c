/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_normal_cmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:32:40 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/09 18:36:16 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rgxp_normal_cmp(t_cdbuf *regexp, t_cdbuf *text, void *pfunc, char inc)
{
	int res;

	(void)pfunc;
	res = (regexp->dbuf.buf[regexp->cursor] == text->dbuf.buf[text->cursor]);
	if (inc)
	{
		regexp->cursor++;
		text->cursor++;
	}
	return (res);
}
