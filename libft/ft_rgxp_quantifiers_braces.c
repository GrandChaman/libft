/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_quantifiers_braces.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:16:38 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/24 20:30:30 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_rgxp_braces_local(t_cdbuf *lrgxp, t_cdbuf *ltext,
	t_rgxp_char_f pfunc, int lazy)
{
	t_rgxp_char_f	npfunc;
	long			lres;
	t_cdbuf			nrgxp;

	npfunc = NULL;
	lres = -1;
	if (lrgxp->cursor + 2 + lazy < lrgxp->dbuf.cursor)
	{
		nrgxp = (t_cdbuf){.cursor = lrgxp->cursor + 2 + lazy,
			.dbuf = lrgxp->dbuf};
		npfunc = ft_rgxp_get_pfunc(nrgxp);
	}
	ft_fprintf(2, "Quantifier : %c (Lazy : %s)\n", '*', lazy ? "Yes" : "No");
	while (ltext->cursor < ltext->dbuf.cursor &&
		((t_rgxp_char_f)pfunc)(lrgxp, ltext, pfunc, RGXP_NO_INC) > 0)
	{
		if (npfunc && npfunc(&nrgxp, ltext, pfunc, RGXP_NO_INC) > 0)
				lres = ltext->cursor;
		if (!lazy)
			ltext->cursor++;
		else
			break ;
	}
	return (lres);
}

int		ft_rgxp_braces(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
{
	int i;
	int	lazy;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;

	i = 0;
	lazy = 0;
	if (rgxp->dbuf.buf[rgxp->cursor + 1] == '?')
		lazy = 1;
	lrgxp = *rgxp;
	ltext = *text;
	lrgxp.cursor--;
	i = ft_rgxp_braces_local(&lrgxp, &ltext, pfunc, lazy);
	if (inc)
	{
		rgxp->cursor += 1 + lazy;
		ft_printf("Before : %d - %s\n", text->cursor, text->dbuf.buf + text->cursor);
		text->cursor += (i < 0 ? ltext.cursor : i) - text->cursor;
		ft_printf("After : %d - %s\n", text->cursor, text->dbuf.buf + text->cursor);
	}
	return (1);
}
