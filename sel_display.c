/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:20:55 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/25 16:55:58 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int				is_last(int pos, int max)
{
	return ((max - pos) < 1 ? 1 : 0);
}

static int				no_space(t_select *sel)
{
	char		*buffer2;
	char		buffer[1024];

	if (sel->io->ws_col < sel->max_len + 2 ||
		((sel->io->ws_col) * (sel->io->ws_row)) <=
		(sel->nb_arg + sel->io->ws_row) * (sel->max_len + 2)
		|| (((sel->max_len + 2) * sel->io->ws_row) /
		((sel->io->ws_col) / (sel->max_len + 2)) >
		(sel->io->ws_row * (sel->io->ws_col))))
	{
		buffer2 = buffer;
		tputs(tgetstr("cl", &buffer2), 1, putint);
		ft_putstr_fd("INSUFFICIENT SPACE", get_fd(-1));
		sel->space = 0;
		return (1);
	}
	sel->space = 1;
	return (0);
}

static int				anarg(t_arg *arg,
								t_select *sel,
								int pos)
{
	size_t		i;
	char		buffer[1024];
	char		*buffer2;

	buffer2 = buffer;
	i = ft_strlen(arg->name);
	if (arg->selected == 1)
		tputs(tgetstr("so", &buffer2), 1, putint);
	ft_putstr_fd(arg->name, get_fd(-1));
	if (arg->selected == 1)
		tputs(tgetstr("se", &buffer2), 1, putint);
	if (is_last(pos + ft_strlen(arg->name), sel->io->ws_col))
		return (i);
	while (i < (size_t)sel->max_len + 2)
	{
		ft_putchar_fd(' ', get_fd(-1));
		i++;
	}
	return (i);
}

void					display_arg(t_arg *arg, t_select *sel)
{
	int				i;
	int				y;
	t_arg			*tmp;

	i = 0;
	y = 0;
	ioctl(0, TIOCGWINSZ, sel->io);
	if (no_space(sel))
		return ;
	tmp = arg;
	while (tmp != arg || i == 0)
	{
		tmp->x = i;
		tmp->y = y;
		if ((i + (sel->max_len + 2)) >= (sel->io->ws_col - 1))
		{
			i = 0;
			++y;
			tmp->x = i;
			tmp->y = y;
			ft_putchar_fd('\n', get_fd(-1));
		}
		i += anarg(tmp, sel, i);
		tmp = tmp->next;
	}
}
