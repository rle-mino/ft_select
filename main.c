/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:16:53 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/22 20:56:22 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_select	*sel;

	if (ac < 2)
		return (sel_error(NO_ARG));
	if (!(sel = ft_memalloc(sizeof(t_select))))
		sel_error(MALLER);
	sel->nb_arg = ac - 1;
	argv_to_list(av + 1, sel);
	init_env(sel);
}
