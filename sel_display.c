/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:30:49 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/21 00:22:39 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int					is_last(int pos, int max)
{
	return ((max - pos) < 10 ? 1 : 0);
}

static int					anarg(t_arg *arg,
									int max_len,
									size_t max_col,
									int pos)
{
	size_t		i;

	i = ft_strlen(arg->name);
	ft_putstr_fd(arg->name, 1);
	if (is_last(pos + ft_strlen(arg->name), max_col))
		return (i);
	while (i < (size_t)max_len + 2)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}

/*
***	t_arg				*get_next_arg(t_arg *tmp_x, size_t ws_row)
***	{
***		t_arg		*to_ret;
***		size_t		i;
***
***		i = -1;
***		to_ret = tmp_x;
***		while (++i < ws_row && to_ret)
***			to_ret = to_ret->next;
***		return (to_ret);
***	}
*/

static void					last_arg(t_arg *tmp)
{
	ft_putstr_fd(tmp->name, 2);
	ft_putchar_fd('\n', 2);
}

void						display_arg(t_arg *arg, int max_len)
{
	struct winsize	w;
	int				i;
	t_arg			*tmp;

	i = -1;
	ioctl(0, TIOCGWINSZ, &w);
	tmp = arg;
	while (tmp != arg || i == -1)
	{
		if (i >= w.ws_col - 10 && !(i = 0))
			ft_putchar_fd('\n', 1);
		if (tmp->next == arg)
			last_arg(tmp);
		else
			i += anarg(tmp, max_len, w.ws_col, i);
		tmp = tmp->next;
	}
}
