/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_quantifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:55:50 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/07 13:24:53 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rgxp_star(t_cdbuf *rgxp, t_cdbuf *text, char lchar)
{
	int i;

	i = 0;
	while (i < text->dbuf.cursor && text->dbuf.buf[text->cursor + i] == lchar)
		i++;
	while (i && rgxp->dbuf.buf[rgxp->cursor] == '*')
		rgxp->cursor++;
	if (!i)
	{
		text->cursor--;
		rgxp->cursor++;
		i = 1;
	}
	return (i);
}

int		ft_rgxp_plus(t_cdbuf *rgxp, t_cdbuf *text, char lchar)
{
	int i;

	i = 0;
	while (i < text->dbuf.cursor && text->dbuf.buf[text->cursor + i] == lchar)
		i++;
	while (i && rgxp->dbuf.buf[rgxp->cursor] == '+')
		rgxp->cursor++;
	return (i);
}

int		ft_rgxp_qmark(t_cdbuf *rgxp, t_cdbuf *text, char lchar)
{
	int i;

	i = 0;
	while (i < text->dbuf.cursor && text->dbuf.buf[text->cursor + i] == lchar)
		i++;
	while (i && rgxp->dbuf.buf[rgxp->cursor] == '?')
		rgxp->cursor++;
	return ((i <= 1));
}
