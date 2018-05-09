/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:34:29 by bluff             #+#    #+#             */
/*   Updated: 2018/05/09 15:35:17 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int						ft_rgxp_backtrack(t_cdbuf *rgxp, t_cdbuf *text, char lc, char inc)
{
	t_rgxp_char_f	c;
	t_rgxp_char_f	cb;
	int				ret;

	ret = 0;
	if (rgxp->cursor < rgxp->dbuf.cursor && rgxp->dbuf.buf[rgxp->cursor] > 0)
	{
		c = g_rgxp_char_list[(int)rgxp->dbuf.buf[rgxp->cursor]].c;
		ft_printf("At : %s\n", text->dbuf.buf + text->cursor);
		if (c && rgxp->dbuf.buf[rgxp->cursor] != '\\')
			ret = c(rgxp, text, lc, inc);
		else if (rgxp->cursor + 1 < rgxp->dbuf.cursor &&
			(cb = g_rgxp_char_list[(int)rgxp->dbuf.buf[rgxp->cursor + 1]].cb) &&
			rgxp->dbuf.buf[rgxp->cursor] == '\\')
			ret = cb(rgxp, text, lc, inc);
		if (ret <= 0)
			return (ret);
	}
	else
		return (1);
	return (ret);
}

int						ft_rgxp_routine(t_cdbuf regexp, t_cdbuf text,
	t_list *tmp_res)
{

	int				ret;
	char			lchar;
	char			lchar_tmp;
	unsigned int	ori_cursor;

	regexp.cursor = 0;
	lchar = 0;
	(void)tmp_res;
	ori_cursor = text.cursor;
	while (regexp.cursor < regexp.dbuf.cursor &&
		(lchar_tmp = regexp.dbuf.buf[regexp.cursor]) > 0)
	{
		if ((ret = ft_rgxp_backtrack(&regexp, &text, lchar, RGXP_INC)) <= 0)
			break ;
		lchar = lchar_tmp;
	}
	char *res;

	if (ret)
	{
		res = ft_strndup(text.dbuf.buf + ori_cursor, text.cursor - ori_cursor);
		ft_printf("Match : %s\n", res);
		free(res);
	}
	return (ret);
}

int						ft_rgxp(char *regexp_ori, char *text_ori)
{
	t_cdbuf	regexp;
	t_cdbuf	text;
	t_list	*tmp_res;
	int		res;

	tmp_res = NULL;
	ft_rgxp_load(&regexp, &text, regexp_ori, text_ori);
	res = 0;
	while (text.cursor < text.dbuf.cursor)
	{
		if ((res = ft_rgxp_routine(regexp, text, tmp_res)) < 0)
			break ;
		text.cursor++;
	}
	ft_rgxp_unload(&regexp, &text);
	return (res);
}
