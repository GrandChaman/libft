/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_quantifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:55:50 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/23 18:21:38 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_brace_param(t_pair *pair, int *lazy, t_cdbuf *rgxp, char inc)
{
	int i;
	int tmp;

	i = rgxp->cursor + 1;
	while (ft_isdigit(rgxp->dbuf.buf[i]))
		i++;
	if (!(i - (rgxp->cursor + 1)))
		return (E_RGXP_BRACE_NO_FIRST_MEMBER);
	pair->a = ft_atoi(rgxp->dbuf.buf + rgxp->cursor + 1);
	if (rgxp->dbuf.buf[i++] != ',')
		return (E_RGXP_BRACE_BAD_SEPARATOR);
	pair->b = ft_atoi(rgxp->dbuf.buf + i);
	tmp = i;
	while (ft_isdigit(rgxp->dbuf.buf[i]))
		i++;
	if (tmp != i && (pair->a >= pair->b || pair->a < 0 || pair->b < 0))
		return (E_RGXP_BRACE_BAD_RANGE);
	if (rgxp->dbuf.buf[i++] != '}')
		return (E_RGXP_BRACE_NO_END);
	if (rgxp->dbuf.buf[i] == '?')
		*lazy = 1;
	else
		*lazy = 0;
	if (inc)
		rgxp->cursor += (i - rgxp->cursor) + *lazy;
	return (0);
}


int		ft_rgxp_brace(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
{
	int		i;
	int		lazy;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;
	t_pair	pair;

	if (rgxp->cursor == 0)
		return (E_RGXP_QUANTIFIER_ON_NULL);
	ltext = *text;
	lrgxp = *rgxp;
	lrgxp.cursor--;
	if ((i = get_brace_param(&pair, &lazy, rgxp, inc)))
		return (i);
	ft_printf("Quantifier : %s (Lazy : %s)\n", "{x,[x]}", lazy ? "Yes" : "No");
	ft_printf("Brace {%d,%d}\n", pair.a, pair.b);
	i = 0;
	while (ltext.cursor < ltext.dbuf.cursor &&
		((t_rgxp_char_f)pfunc)(&lrgxp, &ltext, pfunc, RGXP_NO_INC) > 0
		&& (i < pair.b || pair.b == 0))
		if (i < pair.a || !lazy)
		{
			i++;
			ltext.cursor++;
		}
		else
			break ;
	text->cursor += ltext.cursor - text->cursor;
	return (i);
}

static long	ft_rgxp_star_local(t_cdbuf *lrgxp, t_cdbuf *ltext,
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
	ft_printf("Quantifier : %c (Lazy : %s)\n", '*', lazy ? "Yes" : "No");
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

int		ft_rgxp_star(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
{
	int i;
	int	lazy;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;

	if (rgxp->cursor == 0)
		return (E_RGXP_QUANTIFIER_ON_NULL);
	i = 0;
	lazy = 0;
	if (rgxp->dbuf.buf[rgxp->cursor + 1] == '?')
		lazy = 1;
	lrgxp = *rgxp;
	ltext = *text;
	lrgxp.cursor--;
	i = ft_rgxp_star_local(&lrgxp, &ltext, pfunc, lazy);
	if (inc)
	{
		rgxp->cursor += 1 + lazy;
		ft_printf("Before : %d - %s\n", text->cursor, text->dbuf.buf + text->cursor);
		text->cursor += (i < 0 ? ltext.cursor : i) - text->cursor;
		ft_printf("After : %d - %s\n", text->cursor, text->dbuf.buf + text->cursor);
	}
	return (1);
}

int		ft_rgxp_plus(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
{
	int	lazy;
	int	curr_diff;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;

	if (rgxp->cursor == 0)
		return (E_RGXP_QUANTIFIER_ON_NULL);
	lazy = 0;
	if (rgxp->dbuf.buf[rgxp->cursor + 1] == '?')
		lazy = 1;
	lrgxp = *rgxp;
	lrgxp.cursor--;
	ltext = *text;
	ft_printf("Quantifier : %c (Lazy : %s)\n", '+', lazy ? "Yes" : "No");
	while (ltext.cursor < ltext.dbuf.cursor &&
		((t_rgxp_char_f)pfunc)(&lrgxp, &ltext, pfunc, RGXP_NO_INC) > 0)
		if (!(curr_diff = ltext.cursor - text->cursor) || !lazy)
			ltext.cursor++;
		else
			break ;
	if (inc)
	{
		curr_diff++;
		rgxp->cursor += 1 + lazy;
		text->cursor += curr_diff;
	}
	return (curr_diff);
}

int		ft_rgxp_qmark(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
{
	int i;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;

	if (rgxp->cursor == 0)
		return (E_RGXP_QUANTIFIER_ON_NULL);
	i = 0;
	lrgxp = *rgxp;
	lrgxp.cursor--;
	ltext = *text;
	ft_printf("Quantifier : %c\n", '?');
	while (ltext.cursor < ltext.dbuf.cursor &&
		((t_rgxp_char_f)pfunc)(&lrgxp, &ltext, pfunc, RGXP_NO_INC) > 0)
		if (i < 1)
			ltext.cursor++;
		else
			break ;
	if (inc)
	{
		rgxp->cursor += 1;
		text->cursor += ltext.cursor - text->cursor;
	}
	return ((i <= 1));
}
