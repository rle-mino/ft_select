/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:22:24 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/24 11:36:42 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			sel_buf(char *buffer, int *pos, t_select *sel)
{
	if (buffer[0] == 033 && buffer[1] == 0)
		end_select(sel, W_NORET);
	else if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'C')
		move_right(pos, sel);
	else if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'D')
		move_left(pos, sel);
	else if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'A')
		move_up(pos, sel);
	else if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'B')
		move_down(pos, sel);
	else if (buffer[0] == ' ' && buffer[1] == 0)
		select_arg(sel, pos);
	else if (is_del_or_back(buffer))
		delete_arg(sel, pos);
	else if (buffer[0] == '\n' && buffer[1] == 0)
		end_select(sel, W_RET);
}
