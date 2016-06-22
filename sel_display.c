/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:20:55 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/22 19:11:05 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char					*get_color(t_arg *arg)
{
	char		*color_and_name;

	if (S_ISDIR(arg->stat_file.st_mode))
		color_and_name = ft_strjoin(C_YELLOW, arg->name);
	else if (S_ISLNK(arg->stat_file.st_mode))
		color_and_name = ft_strjoin(C_MAGENTA, arg->name);
	else if (S_ISREG(arg->stat_file.st_mode))
		color_and_name = ft_strjoin(C_RED, arg->name);
	else if (S_ISCHR(arg->stat_file.st_mode) || S_ISBLK(arg->stat_file.st_mode))
		color_and_name = ft_strjoin(C_BLUE, arg->name);
	else
		color_and_name = ft_strjoin(C_WHITE, arg->name);
	return (color_and_name);
}

static int				is_last(int pos, int max)
{
	return ((max - pos) < 1 ? 1 : 0);
}

static int				no_space(t_select *sel)
{
	char		*buffer2;
	char		buffer[1024];

	if ((sel->io->ws_col < 30 + sel->max_len)
		|| sel->io->ws_col < sel->max_len + 2 ||
		((sel->io->ws_col) * (sel->io->ws_row - 1)) <=
		(sel->nb_arg + (sel->io->ws_row - 1)) * (sel->max_len + 2)
		|| (((sel->max_len + 2) * (sel->io->ws_row - 1)) /
		((sel->io->ws_col) / (sel->max_len + 2)) >
		((sel->io->ws_row - 1) * (sel->io->ws_col))))
	{
		buffer2 = buffer;
		tputs(tgetstr("cl", &buffer2), 1, putint);
		ft_putstr_fd(CLU_RED, get_fd(-1));
		ft_putstr_fd("INSUFFICIENT SPACE", get_fd(-1));
		ft_putstr_fd(C_RES, get_fd(-1));
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
	char		*arg_color;

	i = ft_strlen(arg->name);
	if (arg->selected == 1)
		tputs(tgetstr("so", NULL), 1, putint);
	arg_color = get_color(arg);
	ft_putstr_fd(arg_color, get_fd(-1));
	if (arg->selected == 1)
		tputs(tgetstr("se", NULL), 1, putint);
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
