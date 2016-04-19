/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:16:53 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/19 18:02:48 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_select	*sel;
	t_arg		*args;

	if (ac < 2)
		return (sel_error(NO_ARG));
	if (!(sel = ft_memalloc(sizeof(t_select))))
		sel_error(MALLER);
	argv_to_list(av + 1, sel);
	args = sel->first;
	//init_env(av);
}
