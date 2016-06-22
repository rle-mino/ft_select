/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_occur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 20:05:56 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/22 15:28:55 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		go_to_next_occur(t_select *sel, t_arg *old, t_arg *new)
{
	char			*color_and_name;

	if (!sel->space)
		return ;
	tputs(tgoto(tgetstr("cm", NULL), old->x, old->y), 1, putint);
	if (old->selected)
		tputs(tgetstr("so", NULL), 1, putint);
	color_and_name = get_color(old);
	ft_putstr_fd(color_and_name, get_fd(-1));
	free(color_and_name);
	if (old->selected)
		tputs(tgetstr("se", NULL), 1, putint);
	tputs(tgoto(tgetstr("cm", NULL), new->x, new->y), 1, putint);
	if (new->selected)
		tputs(tgetstr("so", NULL), 1, putint);
	tputs(tgetstr("us", NULL), 1, putint);
	color_and_name = get_color(new);
	ft_putstr_fd(color_and_name, get_fd(-1));
	free(color_and_name);
	tputs(tgetstr("ue", NULL), 1, putint);
	if (new->selected)
		tputs(tgetstr("se", NULL), 1, putint);
	tputs(tgoto(tgetstr("cm", NULL), new->x, new->y), 1, putint);
}

void			get_next_occur(t_select *sel, char find)
{
	t_arg		*ori;
	int			loop;
	int			pos[2];

	ori = sel->first;
	loop = 0;
	while (loop < sel->nb_arg)
	{
		loop++;
		sel->first = sel->first->next;
		if (sel->first->name[0] == find)
			break ;
	}
	if (sel->first->name[0] != find)
		sel->first = ori;
	else
	{
		pos[0] = sel->first->x;
		pos[1] = sel->first->y;
		go_to_next_occur(sel, ori, sel->first);
	}
}
