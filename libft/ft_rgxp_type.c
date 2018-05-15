/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:33:16 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/09 18:36:16 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_rgxp_dot(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
{
	int res;

	res = 1;
	(void)pfunc;
	if (text->dbuf.buf[text->cursor] == '\n')
		res = 0;
	if (inc)
	{
		rgxp->cursor++;
		text->cursor++;
	}
	return (res);
}

int			ft_rgxp_bckslash_d(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc,
	char inc)
{
	int	res;

	res = 0;
	(void)pfunc;
	if (rgxp->cursor + 1 >= rgxp->dbuf.cursor)
		return (E_RGXP_BAD_BACKLASH_ECP);
	if (rgxp->dbuf.buf[rgxp->cursor + 1] == 'd')
		res = ft_isdigit(text->dbuf.buf[text->cursor]);
	else if (rgxp->dbuf.buf[rgxp->cursor + 1] == 'D')
		res = !ft_isdigit(text->dbuf.buf[text->cursor]);
	if (inc)
	{
		rgxp->cursor += 2;
		text->cursor++;
	}
	return (res);
}

int			ft_rgxp_bckslash_s(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc,
	char inc)
{
	int	res;

	res = 0;
	(void)pfunc;
	if (rgxp->cursor + 1 >= rgxp->dbuf.cursor)
		return (E_RGXP_BAD_BACKLASH_ECP);
	if (rgxp->dbuf.buf[rgxp->cursor + 1] == 's')
		res = ft_iswhitespace(text->dbuf.buf[text->cursor]);
	else if (rgxp->dbuf.buf[rgxp->cursor + 1] == 'S')
		res = !ft_iswhitespace(text->dbuf.buf[text->cursor]);
	if (inc)
	{
		rgxp->cursor += 2;
		text->cursor++;
	}
	return (res);
}

int			ft_rgxp_bckslash_w(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc,
	char inc)
{
	int	res;

	res = 0;
	(void)pfunc;
	if (rgxp->cursor + 1 >= rgxp->dbuf.cursor)
		return (E_RGXP_BAD_BACKLASH_ECP);
	if (rgxp->dbuf.buf[rgxp->cursor + 1] == 'w')
		res = ft_isalnum(text->dbuf.buf[text->cursor]) ||
			text->dbuf.buf[text->cursor] == '_';
	else if (rgxp->dbuf.buf[rgxp->cursor + 1] == 'W')
		res = !(ft_isalnum(text->dbuf.buf[text->cursor]) ||
			text->dbuf.buf[text->cursor] == '_');
	if (inc)
	{
		rgxp->cursor += 2;
		text->cursor++;
	}
	return (res);
}
