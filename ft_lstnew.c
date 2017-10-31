/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:08:48 by bluff             #+#    #+#             */
/*   Updated: 2017/10/31 17:20:49 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list*		ft_lstnew(void const *content, size_t content_size)
{
	t_list	*el;

	if (!(el = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(el->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(el->content, content, content_size);
		el->content_size = content_size;
	}
	else
	{
		el->content = NULL;
		el->content_size = 0;
	}
	el->next = NULL;
	return (el);
}
