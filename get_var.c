/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 21:57:27 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/23 22:02:08 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg		*get_list(t_arg *l)
{
	static t_arg *list = NULL;

	if (l)
		list = l;
	return (list);
}

int			get_fd(int fd)
{
	static int	o_fd = -1;

	if (o_fd == -1)
		o_fd = fd;
	return (o_fd);
}

t_select	*get_sel(t_select *sel)
{
	static t_select		*o_sel;

	if (o_sel == NULL)
		o_sel = sel;
	return (o_sel);
}
