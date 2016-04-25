/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:09:56 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/25 13:41:03 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				cursor_move(int *pos, t_select *sel)
{
	char	buffer1[1024];
	char	*buffer2;

	if (sel->space == 0)
		return ;
	buffer2 = buffer1;
	tputs(tgoto(tgetstr("cm", &buffer2), pos[0], pos[1]), 1, putint);
	tputs(tgetstr("us", &buffer2), 1, putint);
	if (sel->first->selected == 1)
		tputs(tgetstr("so", &buffer2), 1, putint);
	ft_putstr_fd(sel->first->name, get_fd(-1));
	if (sel->first->selected == 1)
		tputs(tgetstr("se", &buffer2), 1, putint);
	tputs(tgetstr("ue", &buffer2), 1, putint);
	tputs(tgoto(tgetstr("cm", &buffer2), pos[0], pos[1]), 1, putint);
}

void				select_arg(t_select *sel, int *pos)
{
	char	buffer1[1024];
	char	*buffer2;

	buffer2 = buffer1;
	sel->first->selected = sel->first->selected ^ 1;
	if (sel->first->selected)
	{
		tputs(tgetstr("so", &buffer2), 1, putint);
		ft_putstr_fd(sel->first->name, get_fd(-1));
		tputs(tgetstr("se", &buffer2), 1, putint);
	}
	else
		ft_putstr_fd(sel->first->name, get_fd(-1));
	sel->first = sel->first->next;
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
	cursor_move(pos, sel);
}

void				delete_arg(t_select *sel, int *pos)
{
	char	buffer1[1024];
	char	*buffer2;

	buffer2 = buffer1;
	if (sel->nb_arg == 1)
	{
		env_sw();
		exit(EXIT_SUCCESS);
	}
	else
	{
		sel->tmp = sel->first;
		sel->first->next->prev = sel->first->prev;
		sel->first->prev->next = sel->first->next;
		sel->first = sel->first->next;
		free(sel->tmp->name);
		free(sel->tmp);
		tputs(tgetstr("cl", &buffer2), 1, putint);
		display_arg(get_first(sel->first, sel->nb_arg), sel);
		pos[0] = sel->first->x;
		pos[1] = sel->first->y;
		sel->nb_arg--;
	}
}

int					is_del_or_back(char *buffer)
{
	if ((buffer[0] == 033 && buffer[1] == '[' && buffer[2] == '3'
		&& buffer[3] == '~')
		|| (buffer[0] == 127))
		return (1);
	return (0);
}

void				ft_select(t_select *sel, int *pos)
{
	char	buffer[6];
	int		i;

	i = 0;
	display_arg(sel->first, sel);
	while (42)
	{
		cursor_move(pos, sel);
		ft_bzero(buffer, sizeof(buffer));
		read(0, buffer, 5);
		sel_buf(buffer, pos, sel);
	}
}
