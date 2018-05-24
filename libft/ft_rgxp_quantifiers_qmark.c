/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_quantifiers_qmark.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 17:09:57 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/24 20:29:33 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_rgxp_qmark_local(t_cdbuf *lrgxp, t_cdbuf *ltext,
	t_rgxp_char_f pfunc)
{
	unsigned int	i;

	i = 0;
	ft_fprintf(2, "Quantifier : %c (Lazy : %s)\n", '?', "Yes");
	if (ltext->cursor < ltext->dbuf.cursor &&
		((t_rgxp_char_f)pfunc)(lrgxp, ltext, pfunc, RGXP_NO_INC) > 0)
		i++;
	return (i);
}

int		ft_rgxp_qmark(t_cdbuf *rgxp, t_cdbuf *text, void *pfunc, char inc)
{
	int i;
	t_cdbuf	lrgxp;
	t_cdbuf	ltext;

	i = 0;
	lrgxp = *rgxp;
	ltext = *text;
	lrgxp.cursor--;
	i = ft_rgxp_qmark_local(&lrgxp, &ltext, pfunc);
	if (inc)
	{
		rgxp->cursor += 1;
		ft_printf("Before : %d - %s\n", text->cursor, text->dbuf.buf + text->cursor);
		text->cursor += i;
		ft_printf("After : %d - %s\n", text->cursor, text->dbuf.buf + text->cursor);
	}
	return (1);
}
