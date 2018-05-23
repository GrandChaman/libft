/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:52:03 by bluff             #+#    #+#             */
/*   Updated: 2018/05/23 19:28:06 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int main(int argc, char **argv)
{
	t_list		*res;
	t_str_piece	*tmp;

	res = NULL;
	if (argc != 3)
		return (argc);
	ft_printf("=> %d\n", ft_rgxp(argv[1], argv[2], &res));
	while (res)
	{
		tmp = (t_str_piece*)res->content;
		ft_printf("Param : %d -> %d\n", tmp->start,tmp->len);
		ft_printf("Match : \"%.*s\"\n",tmp->len, argv[2] + tmp->start);
		ft_lstdelone(&res, NULL);
	}
	return (0);
}
