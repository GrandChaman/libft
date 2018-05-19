/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:20:30 by bluff             #+#    #+#             */
/*   Updated: 2018/05/19 18:05:29 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_rgxp_load(t_cdbuf *regexp, t_cdbuf *text,
	char *ori_regexp, char *ori_text)
{
	regexp->dbuf.buf = ft_strdup(ori_regexp);
	regexp->dbuf.cursor = ft_strlen(ori_regexp);
	regexp->dbuf.len = regexp->dbuf.cursor;
	text->dbuf.buf = ft_strdup(ori_text);
	text->dbuf.cursor = ft_strlen(ori_text);
	text->dbuf.len = text->dbuf.cursor;
	regexp->cursor = 0;
	text->cursor = 0;
}

t_rgxp_char_f				ft_rgxp_get_pfunc(t_cdbuf *rgxp)
{
	t_rgxp_char_f res;
	t_rgxp_char_f tmp;

	res = NULL;
	if (rgxp->cursor < rgxp->dbuf.cursor && rgxp->dbuf.buf[rgxp->cursor] > 0)
	{
		tmp = g_rgxp_char_list[(int)rgxp->dbuf.buf[rgxp->cursor]].c;
		if (tmp && rgxp->dbuf.buf[rgxp->cursor] != '\\')
			res = tmp;
		else if (rgxp->cursor + 1 < rgxp->dbuf.cursor &&
			(tmp = g_rgxp_char_list[(int)rgxp->dbuf.buf[rgxp->cursor + 1]].cb)
			&& rgxp->dbuf.buf[rgxp->cursor] == '\\')
			res = tmp;
	}
	return (res);
}
