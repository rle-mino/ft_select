/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:59:19 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/22 15:14:40 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void				put_move(t_select *sel)
{
	char	*name_and_color;

	if (sel->first->selected == 1)
		tputs(tgetstr("so", NULL), 1, putint);
	name_and_color = get_color(sel->first);
	ft_putstr_fd(name_and_color, get_fd(-1));
	free(name_and_color);
	if (sel->first->selected == 1)
		tputs(tgetstr("se", NULL), 1, putint);
}

void					move_right(int *pos, t_select *sel)
{
	put_move(sel);
	sel->first = sel->first->next;
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
	cursor_move(pos, sel);
}

void					move_left(int *pos, t_select *sel)
{
	put_move(sel);
	sel->first = sel->first->prev;
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
	cursor_move(pos, sel);
}

void					move_up(int *pos, t_select *sel)
{
	int		y;
	int		x;
	int		max;
	int		max_tmp;

	put_move(sel);
	y = sel->first->y;
	x = sel->first->x;
	max = ((sel->io->ws_col - 10) / (sel->max_len + 2));
	max_tmp = max;
	while (max > 0 || x != sel->first->x)
	{
		sel->first = sel->first->prev;
		max--;
		if (max != max_tmp && x == sel->first->x)
			break ;
	}
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
	cursor_move(pos, sel);
}

void					move_down(int *pos, t_select *sel)
{
	int		y;
	int		x;
	int		max;
	int		max_tmp;

	put_move(sel);
	y = sel->first->y;
	x = sel->first->x;
	max = ((sel->io->ws_col - 10) / (sel->max_len + 2));
	max_tmp = max;
	while (max > 0 || x != sel->first->x)
	{
		sel->first = sel->first->next;
		max--;
		if (max != max_tmp && x == sel->first->x)
			break ;
	}
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
	cursor_move(pos, sel);
}
