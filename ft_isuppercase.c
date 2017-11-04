/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuppercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 13:22:35 by fle-roy           #+#    #+#             */
/*   Updated: 2017/11/04 00:40:33 by bluff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isuppercase(char *str)
{
	int res;
	int i;

	i = -1;
	res = 1;
	while (str[++i])
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			res = 0;
			break ;
		}
	}
	return (res);
}
