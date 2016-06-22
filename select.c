/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 18:09:56 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/22 15:20:29 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				cursor_move(int *pos, t_select *sel)
{
	char		*color_and_name;

	if (sel->space == 0)
		return ;
	tputs(tgoto(tgetstr("cm", NULL), pos[0], pos[1]), 1, putint);
	tputs(tgetstr("us", NULL), 1, putint);
	if (sel->first->selected == 1)
		tputs(tgetstr("so", NULL), 1, putint);
	color_and_name = get_color(sel->first);
	ft_putstr_fd(color_and_name, get_fd(-1));
	free(color_and_name);
	if (sel->first->selected == 1)
		tputs(tgetstr("se", NULL), 1, putint);
	tputs(tgetstr("ue", NULL), 1, putint);
	tputs(tgoto(tgetstr("cm", NULL), pos[0], pos[1]), 1, putint);
}

void				select_arg(t_select *sel, int *pos)
{
	char	*color_and_name;

	sel->first->selected = sel->first->selected ^ 1;
	color_and_name = get_color(sel->first);
	if (sel->first->selected)
	{
		tputs(tgetstr("so", NULL), 1, putint);
		ft_putstr_fd(color_and_name, get_fd(-1));
		tputs(tgetstr("se", NULL), 1, putint);
	}
	else
		ft_putstr_fd(color_and_name, get_fd(-1));
	free(color_and_name);
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
	update_status(sel);
	cursor_move(pos, sel);
	while (42)
	{
		ft_bzero(buffer, sizeof(buffer));
		read(0, buffer, 5);
		sel_buf(buffer, pos, sel);
		update_status(sel);
	}
}
