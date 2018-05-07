/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:34:29 by bluff             #+#    #+#             */
/*   Updated: 2018/05/07 13:25:15 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_rgxp_routine(t_cdbuf regexp, t_cdbuf text,
	t_list *tmp_res)
{
	t_rgxp_char_f	c;
	t_rgxp_char_f	cb;
	int				ret;
	char			lchar;
	char			lchar_tmp;

	regexp.cursor = 0;
	lchar = 0;
	(void)tmp_res;
	while (regexp.cursor < regexp.dbuf.cursor &&
		(lchar_tmp = regexp.dbuf.buf[regexp.cursor]) > 0)
	{
		c = g_rgxp_char_list[(int)regexp.dbuf.buf[regexp.cursor]].c;
		cb = g_rgxp_char_list[(int)regexp.dbuf.buf[regexp.cursor]].cb;
		ft_printf("At : %s\n", text.dbuf.buf + text.cursor);
		if (c)
			ret = c(&regexp, &text, lchar);
		if (!ret)
			break ;
		lchar = lchar_tmp;
		text.cursor += ret;
	}
	return (ret);
}

int						ft_rgxp(char *regexp_ori, char *text_ori)
{
	t_cdbuf	regexp;
	t_cdbuf	text;
	t_list	*tmp_res;

	tmp_res = NULL;
	ft_rgxp_load(&regexp, &text, regexp_ori, text_ori);
	while (text.cursor < text.dbuf.cursor)
	{
		if (ft_rgxp_routine(regexp, text, tmp_res))
			ft_printf("Match at : %s\n", text.dbuf.buf + text.cursor);
		text.cursor++;
	}
	ft_rgxp_unload(&regexp, &text);
	return (0);
}
