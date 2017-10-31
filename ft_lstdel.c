/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:29:58 by bluff             #+#    #+#             */
/*   Updated: 2017/10/31 17:46:44 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void(*del)(void*, size_t))
{
	if ((*alst)->next != NULL)
		ft_lstdel(&((*alst)->next), del);
	ft_lstdelone(alst, del);
}
