/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_normal_cmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:32:40 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/07 13:49:35 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rgxp_normal_cmp(t_cdbuf *regexp, t_cdbuf *text, char lchar)
{
	int res;

	(void)lchar;
	if ((res = (regexp->dbuf.buf[regexp->cursor] ==
		text->dbuf.buf[text->cursor])))
	{
		regexp->cursor++;
		text->cursor++;		
	}
	return (res);
}
