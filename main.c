/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:16:53 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/24 12:56:48 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_select	*sel;
	int			fd;

	if (ac < 2)
		return (sel_error(NO_ARG));
	if (!(sel = ft_memalloc(sizeof(t_select))))
		sel_error(MALLER);
	sel->nb_arg = ac - 1;
	if ((fd = open(ttyname(2), O_RDWR)) <= 0)
		return (sel_error(ENV_ERROR));
	argv_to_list(av + 1, sel);
	get_fd(fd);
	get_sel(sel);
	get_list(sel->first);
	init_env(sel);
}
