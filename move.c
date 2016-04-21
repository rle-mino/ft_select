/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:59:19 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/21 21:34:58 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				move_right(int *pos, t_select *sel)
{
	ft_putstr_fd(sel->first->name, 1);
	sel->first = sel->first->next;
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
}

void				move_left(int *pos, t_select *sel)
{
	ft_putstr_fd(sel->first->name, 1);
	sel->first = sel->first->prev;
	pos[0] = sel->first->x;
	pos[1] = sel->first->y;
}

void				move_up(int *pos, t_select *sel)
{
	int		y;
	int		x;
	int		max;
	int		max_tmp;

	ft_putstr_fd(sel->first->name, 1);
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

void				move_down(int *pos, t_select *sel)
{
	int		y;
	int		x;
	int		max;
	int		max_tmp;

	ft_putstr_fd(sel->first->name, 1);
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
