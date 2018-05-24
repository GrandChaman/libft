/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_quantifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:55:50 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/24 17:44:04 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int toto()
{
	return (0);
}

// static int	get_brace_param(t_pair *pair, int *lazy, t_cdbuf *rgxp, char inc)
// {
// 	int i;
// 	int tmp;
//
// 	i = rgxp->cursor + 1;
// 	while (ft_isdigit(rgxp->dbuf.buf[i]))
// 		i++;
// 	if (!(i - (rgxp->cursor + 1)))
// 		return (E_RGXP_BRACE_NO_FIRST_MEMBER);
// 	pair->a = ft_atoi(rgxp->dbuf.buf + rgxp->cursor + 1);
// 	if (rgxp->dbuf.buf[i++] != ',')
// 		return (E_RGXP_BRACE_BAD_SEPARATOR);
// 	pair->b = ft_atoi(rgxp->dbuf.buf + i);
// 	tmp = i;
// 	while (ft_isdigit(rgxp->dbuf.buf[i]))
// 		i++;
// 	if (tmp != i && (pair->a >= pair->b || pair->a < 0 || pair->b < 0))
// 		return (E_RGXP_BRACE_BAD_RANGE);
// 	if (rgxp->dbuf.buf[i++] != '}')
// 		return (E_RGXP_BRACE_NO_END);
// 	if (rgxp->dbuf.buf[i] == '?')
// 		*lazy = 1;
// 	else
// 		*lazy = 0;
// 	if (inc)
// 		rgxp->cursor += (i - rgxp->cursor) + *lazy;
// 	return (0);
// }
//
//
// int		ft_rgxp_brace(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
// {
// 	int		i;
// 	int		lazy;
// 	t_cdbuf	lrgxp;
// 	t_cdbuf	ltext;
// 	t_pair	pair;
//
// 	ltext = *text;
// 	lrgxp = *rgxp;
// 	lrgxp.cursor--;
// 	if ((i = get_brace_param(&pair, &lazy, rgxp, inc)))
// 		return (i);
// 	ft_printf("Quantifier : %s (Lazy : %s)\n", "{x,[x]}", lazy ? "Yes" : "No");
// 	ft_printf("Brace {%d,%d}\n", pair.a, pair.b);
// 	i = 0;
// 	while (ltext.cursor < ltext.dbuf.cursor &&
// 		((t_rgxp_char_f)pfunc)(&lrgxp, &ltext, pfunc, RGXP_NO_INC) > 0
// 		&& (i < pair.b || pair.b == 0))
// 		if (i < pair.a || !lazy)
// 		{
// 			i++;
// 			ltext.cursor++;
// 		}
// 		else
// 			break ;
// 	text->cursor += ltext.cursor - text->cursor;
// 	return (i);
// }
