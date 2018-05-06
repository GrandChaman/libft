/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:34:29 by bluff             #+#    #+#             */
/*   Updated: 2018/05/07 00:03:15 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_rgxp_routine(t_cdbuf regexp, t_cdbuf text,
	t_list *tmp_res)
{
	regexp.cursor = 0;
	(void)tmp_res;
	while (regexp.cursor < regexp.dbuf.cursor &&
		regexp.dbuf.buf[regexp.cursor] > 0)
	{
		ft_printf("At : %s\n", text.dbuf.buf + text.cursor);
		ft_printf("%p\n", g_rgxp_char_list[(int)regexp.dbuf.buf[regexp.cursor]].c);
		ft_printf("%p\n", g_rgxp_char_list[(int)regexp.dbuf.buf[regexp.cursor]].cb);
		ft_printf("%p\n--\n", g_rgxp_char_list[(int)regexp.dbuf.buf[regexp.cursor]].is_char);
		regexp.cursor++;
	}
	return (0);
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
		ft_rgxp_routine(regexp, text, tmp_res);
		text.cursor++;
	}
	ft_rgxp_unload(&regexp, &text);
	return (0);
}
