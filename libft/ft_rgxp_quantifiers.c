/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_quantifiers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:55:50 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/07 16:38:04 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_rgxp_star(t_cdbuf *rgxp, t_cdbuf *text, char lchar)
{
	int i;
	int	lazy;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;

	i = 0;
	lazy = 0;
	while (rgxp->dbuf.buf[rgxp->cursor] == '*')
		rgxp->cursor++;
	if (rgxp->dbuf.buf[rgxp->cursor] == '?' && (lazy = 1))
		rgxp->cursor++;
	lrgxp = *rgxp;
	ltext = *text;
	ft_printf("Quantifier : %c (Lazy : %s)\n", '*', lazy ? "Yes" : "No");
	while (i < text->dbuf.cursor && text->dbuf.buf[text->cursor + i] == lchar)
		if (!lazy || !ft_rgxp_backtrack(&lrgxp, &ltext, lchar))
			i++;
		else
			break ;
	if (!i)
		rgxp->cursor++;
	text->cursor += i;
	return (i + 1);
}

int		ft_rgxp_plus(t_cdbuf *rgxp, t_cdbuf *text, char lchar)
{
	int i;
	int	lazy;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;

	i = 0;
	lazy = 0;
	while (rgxp->dbuf.buf[rgxp->cursor] == '+')
		rgxp->cursor++;
	if (rgxp->dbuf.buf[rgxp->cursor] == '?' && (lazy = 1))
		rgxp->cursor++;
	lrgxp = *rgxp;
	ltext = *text;
	ft_printf("Quantifier : %c (Lazy : %s)\n", '+', lazy ? "Yes" : "No");
	while (i < text->dbuf.cursor && text->dbuf.buf[text->cursor + i] == lchar)
		if (i == 0 || !lazy || !ft_rgxp_backtrack(&lrgxp, &ltext, lchar))
			i++;
		else
			break ;
	text->cursor += i;
	return (i);
}

int		ft_rgxp_qmark(t_cdbuf *rgxp, t_cdbuf *text, char lchar)
{
	int i;
	int	lazy;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;

	i = 0;
	lazy = -1;
	ft_printf("Quantifier : %c\n", '?');
	while (rgxp->dbuf.buf[rgxp->cursor] == '?')
	{
		rgxp->cursor++;
		lazy = (lazy < 0 ? 0 : 1);
	}
	lrgxp = *rgxp;
	ltext = *text;
	ft_printf("Quantifier : %c (Lazy : %s)\n", '?', lazy ? "Yes" : "No");
	while (i < text->dbuf.cursor && text->dbuf.buf[text->cursor + i] == lchar)
		if ((!lazy || !ft_rgxp_backtrack(&lrgxp, &ltext, lchar)) && i <= 1)
			i++;
		else
			break ;
	text->cursor += i;
	return ((i <= 1));
}
