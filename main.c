/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:16:53 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/22 16:23:11 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_select	*sel;
	int			fd;

	if (ac < 2)
		return (sel_error(NO_ARG));
	sel = ft_memalloc(sizeof(t_select));
	sel->nb_arg = ac - 1;
	if ((fd = open("/dev/tty", O_RDWR)) == -1)
		return (sel_error(ENV_ERROR));
	argv_to_list(av + 1, sel);
	get_fd(fd);
	get_sel(sel);
	get_list(sel->first);
	init_env(sel);
}
