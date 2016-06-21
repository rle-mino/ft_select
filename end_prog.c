/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 11:30:32 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/21 13:14:55 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		end_select(t_select *sel, int info)
{
	t_arg		*args;

	env_sw();
	args = get_first(sel->first, sel->nb_arg);
	if (info == W_RET)
	{
		while (sel->nb_arg--)
		{
			if (args->selected == 1)
			{
				ft_putstr(args->name);
				ft_putchar(' ');
			}
			args = args->next;
		}
	}
	exit(EXIT_SUCCESS);
}
