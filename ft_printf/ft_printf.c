/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:38:11 by fle-roy           #+#    #+#             */
/*   Updated: 2018/01/25 15:07:00 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_utils.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

void	handle_colors(t_ptf_buf *buf, const char *format, int *li, int *i)
{
	int ii;
	int len;

	ii = -1;
	len = *i + 1;
	while (format[len] && format[len] != '}')
		len++;
	while (g_color_list[++ii].trigger && format[len] == '}')
		if (!ft_strncmp(g_color_list[ii].trigger, format + *i + 1,
			len - *i - 1))
		{
			if ((*i) - *li)
				ft_putnstr(buf, format + *li, (*i) - *li);
			ft_putnstr(buf, g_color_list[ii].code, 0);
			*li = len + 1;
			*i = len;
			break ;
		}
}

int		ft_printf_routine(t_ptf_buf *buf, const char *format)
{
	int			i;
	int			li;

	li = 0;
	i = -1;
	while (format[++i])
		if (format[i] == '%')
		{
			format_handler(buf, get_toprint(format, li, i), &i);
			li = i;
			i--;
		}
		else if (format[i] == '{')
			handle_colors(buf, format, &li, &i);
	dbuf_append(&buf->buf, (char*)format + li);
	dbuf_print(&buf->buf, STDOUT_FILENO);
	return (buf->buf.cursor);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			res;
	t_ptf_buf	buf;

	if (!format)
		return (-1);
	va_start(buf.ap, format);
	buf.fd = 1;
	dbuf_init(&buf.buf);
	res = ft_printf_routine(&buf, format);
	dbuf_destroy(&buf.buf);
	va_end(ap);
	return (res);
}

int		ft_fprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			res;
	t_ptf_buf	buf;

	if (!format)
		return (-1);
	va_start(buf.ap, format);
	buf.fd = fd;
	dbuf_init(&buf.buf);
	res = ft_printf_routine(&buf, format);
	dbuf_destroy(&buf.buf);
	va_end(ap);
	return (res);
}
