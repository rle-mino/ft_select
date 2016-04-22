/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:30:49 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/22 18:39:44 by rle-mino         ###   ########.fr       */
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
	char		buffer[1024];
	char		*buffer2;

	buffer2 = buffer;
	i = ft_strlen(arg->name);
	if (arg->selected == 1)
		tputs(tgetstr("so", &buffer2), 1, putint);
	ft_putstr_fd(arg->name, 1);
	if (arg->selected == 1)
		tputs(tgetstr("se", &buffer2), 1, putint);
	if (is_last(pos + ft_strlen(arg->name), max_col))
		return (i);
	while (i < (size_t)max_len + 2)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
	return (i);
}

void						display_arg(t_arg *arg,
										int max_len,
										struct winsize *io)
{
	int				i;
	int				y;
	t_arg			*tmp;

	i = 0;
	y = 0;
	ioctl(0, TIOCGWINSZ, io);
	tmp = arg;
	while (tmp != arg || i == 0)
	{
		tmp->x = i;
		tmp->y = y;
		if (i + ft_strlen(tmp->name) >= io->ws_col - 10 && !(i = 0) && ++y)
		{
			tmp->x = i;
			tmp->y = y;
			ft_putchar_fd('\n', 1);
		}
		i += anarg(tmp, max_len, io->ws_col, i);
		tmp = tmp->next;
	}
}
