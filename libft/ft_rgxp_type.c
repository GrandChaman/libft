/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:33:16 by fle-roy           #+#    #+#             */
/*   Updated: 2018/05/09 14:25:16 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_rgxp_bckslash_d(t_cdbuf *rgxp, t_cdbuf *text, char lchar, char inc)
{
	int	res;

	res = 0;
	(void)lchar;
	if (rgxp->cursor + 1 >= rgxp->dbuf.cursor)
		return (E_RGXP_BAD_BACKLASH_ECP);
	if (rgxp->dbuf.buf[rgxp->cursor + 1] == 'd')
		res = ft_isdigit(text->dbuf.buf[text->cursor]);
	else if (rgxp->dbuf.buf[rgxp->cursor + 1] == 'D')
		res = !ft_isdigit(text->dbuf.buf[text->cursor]);
	if (inc)
	{
		rgxp->cursor += 2;
		text->cursor++;
	}
	return (res);
}
