/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbuf_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:00:15 by fle-roy           #+#    #+#             */
/*   Updated: 2018/01/24 11:44:11 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		dbuf_append(t_dbuf *buf, char *to_append)
{
	unsigned long	len;
	unsigned long	i;
	char			*tmp;

	if (!buf || !buf->buf || !to_append || !buf->len)
		return (LIBFT_ERR);
	i = buf->len / BUFF_SIZE;
	len = ft_strlen(to_append);
	if (buf->cursor + len > buf->len)
	{
		while (buf->cursor + len > i)
			i += BUFF_SIZE;
		tmp = ft_strnew(i);
		buf->len = i;
		ft_strcpy(tmp, buf->buf);
		free(buf->buf);
		buf->buf = tmp;
	}
	ft_strcpy(buf->buf + buf->cursor, to_append);
	buf->cursor += len;
	return (LIBFT_OK);
}
