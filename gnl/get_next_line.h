/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluff <bluff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:18:00 by bluff             #+#    #+#             */
/*   Updated: 2017/11/16 14:15:48 by fle-roy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# define BUFF_SIZE 32

typedef struct		s_gnl
{
	char			buffer[BUFF_SIZE + 1];
	char			*current_line;
	int				cursor;
	int				fd;
	int				ll;
}					t_gnl;

int					get_next_line(int const fd, char **line);

#endif
