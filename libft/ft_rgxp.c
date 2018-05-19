/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:34:29 by bluff             #+#    #+#             */
/*   Updated: 2018/05/19 18:06:36 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int						ft_rgxp_backtrack(t_cdbuf *rgxp, t_cdbuf *text, t_rgxp_char_f *pfunc, char inc)
{
	t_rgxp_char_f	tmp;
	int				ret;

	ret = 0;
	ft_printf("At : %s\n", text->dbuf.buf + text->cursor);
	tmp = ft_rgxp_get_pfunc(rgxp);
	if (tmp)
	{
		ret = tmp(rgxp, text, *pfunc, inc);
		*pfunc = tmp;
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
	t_rgxp_char_f	pfunc;
	unsigned int	ori_cursor;

	regexp.cursor = 0;
	pfunc = NULL;
	(void)tmp_res;
	ori_cursor = text.cursor;
	while (regexp.cursor < regexp.dbuf.cursor &&
		regexp.dbuf.buf[regexp.cursor] > 0)
		if ((ret = ft_rgxp_backtrack(&regexp, &text, &pfunc, RGXP_INC)) <= 0)
			break ;
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
