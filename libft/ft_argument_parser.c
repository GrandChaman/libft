/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-roy <fle-roy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:54:14 by fle-roy           #+#    #+#             */
/*   Updated: 2017/12/15 14:14:19 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int				arg_searcher(void *data_ref, void *content)
{
	return (!(((t_args*)data_ref)->key == *((char*)content)));
}

static int				param_parser(t_list **list, t_args_config conf,
	const char *param, const char *nparam)
{
	t_args	res;
	int		i;
	int		h_no_args;
	int		h_args;

	i = -1;
	while (param[++i])
		if (!(h_no_args = ft_haschar(conf.no_args_keys, param[i])) &&
		!(h_args = ft_haschar(conf.args_keys, param[i])))
			return (0);
		else
		{
			res.key = param[i];
			if (h_args && param[i + 1] == '\0')
				res.value = (char*)nparam;
			else if (h_no_args)
				res.value = (NULL);
			else
				return (0);
			if (!ft_lstfind(*list, (void*)&param[i], arg_searcher))
				ft_lstpush_back(list, &res, sizeof(res));
		}
	return (i + 1);
}

static void				delete_args(void *content, size_t size)
{
	(void)size;
	free(((t_args*)content)->value);
}

static void				ft_delete_args(t_list **l)
{
	ft_lstdel(l, delete_args);
}

t_list					*get_param(t_args_config conf, int argc,
	const char **argv)
{
	int			i;
	t_list		*res;

	i = 0;
	res = NULL;
	while (++i < argc)
		if (argv[i][0] == '-')
			if (!param_parser(&res, conf, argv[i] + 1, argv[i + 1]))
			{
				if (res)
					ft_delete_args(&res);
				return (NULL);
			}
	return (res);
}
