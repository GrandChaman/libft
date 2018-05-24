/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:52:03 by bluff             #+#    #+#             */
/*   Updated: 2018/05/24 20:45:24 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int main(int argc, char **argv)
{
	t_list		*res;
	t_str_piece	*tmp;
	int			rvalue;

	res = NULL;
	if (argc != 3)
		return (argc);
	rvalue = ft_rgxp(argv[1], argv[2], &res);
	while (res)
	{
		tmp = (t_str_piece*)res->content;
		ft_fprintf(2, "Param : %d -> %d\n", tmp->start,tmp->len);
		ft_printf("Match : %.*s\n",tmp->len, argv[2] + tmp->start);
		ft_lstdelone(&res, NULL);
	}
	ft_printf("=> %d\n", rvalue);
	return (0);
}
