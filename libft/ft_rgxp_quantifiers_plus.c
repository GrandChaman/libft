/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_quantifiers_plus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:09:06 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/24 20:30:36 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_rgxp_plus_local(t_cdbuf *lrgxp, t_cdbuf *ltext,
	t_rgxp_char_f pfunc, int lazy)
{
	t_rgxp_char_f	nfunc;
	long			lres;
	t_cdbuf			nrgxp;
	int				i;

	nfunc = NULL;
	lres = -1;
	if (lrgxp->cursor + 2 + lazy < lrgxp->dbuf.cursor)
	{
		nrgxp = (t_cdbuf){.cursor = lrgxp->cursor + 2 + lazy,
			.dbuf = lrgxp->dbuf};
		nfunc = ft_rgxp_get_pfunc(nrgxp);
	}
	i = 0;
	ft_fprintf(2, "Quantifier : %c (Lazy : %s)\n", '*', lazy ? "Yes" : "No");
	while (ltext->cursor < ltext->dbuf.cursor &&
		((t_rgxp_char_f)pfunc)(lrgxp, ltext, pfunc, RGXP_NO_INC) > 0)
	{
		if (nfunc && nfunc(&nrgxp, ltext, pfunc, RGXP_NO_INC) > 0)
			lres = ltext->cursor;
		ltext->cursor++;
		i++;
		if ((lazy && lres > 0) || (lazy && !nfunc))
			break ;
	}
	return (i > 0 ? lres : 0);
}

int		ft_rgxp_plus(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
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
	i = ft_rgxp_plus_local(&lrgxp, &ltext, pfunc, lazy);
	if (inc)
	{
		rgxp->cursor += 1 + lazy;
		text->cursor += (i < 0 ? ltext.cursor : i) - text->cursor;
	}
	return (i < 0 ? 1 : i);
}
