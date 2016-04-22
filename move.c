/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:59:19 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/22 20:11:40 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void				put_move(t_select *sel)
{
	char	buffer[1024];
	char	*buffer2;

	buffer2 = buffer;
	if (sel->first->selected == 1)
		tputs(tgetstr("so", &buffer2), 1, putint);
	ft_putstr_fd(sel->first->name, 1);
	if (sel->first->selected == 1)
		tputs(tgetstr("se", &buffer2), 1, putint);
}

void					move_right(int *pos, t_select *sel)
{
	put_move(sel);
	sel->first = sel->first->next;
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
}

void					move_left(int *pos, t_select *sel)
{
	put_move(sel);
	sel->first = sel->first->prev;
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
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
}
