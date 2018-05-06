/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:20:30 by bluff             #+#    #+#             */
/*   Updated: 2018/05/06 23:33:03 by bluff            ###   ########.fr       */
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
