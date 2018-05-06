/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgxp_unload.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:24:41 by bluff             #+#    #+#             */
/*   Updated: 2018/05/06 23:34:18 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_rgxp_unload(t_cdbuf *regexp, t_cdbuf *text)
{
	dbuf_destroy(&regexp->dbuf);
	dbuf_destroy(&text->dbuf);
	regexp->cursor = 0;
}
