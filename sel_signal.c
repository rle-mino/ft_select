/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 17:40:25 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/23 22:05:45 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		res_and_quit(int sig)
{
	(void)sig;
	env_sw();
	exit(EXIT_FAILURE);
}

void		suspend(int sig)
{
	char z[2];

	z[0] = 26;
	z[1] = '\0';
	(void)sig;
	env_sw();
	signal(SIGTSTP, SIG_DFL);
	ioctl(1, TIOCSTI, z);
	write(get_fd(-1), "\b \b", 3);
	write(get_fd(-1), "\b \b", 3);
}

void		restart(int sig)
{
	t_select	*sel;
	char		buffer[1024];
	char		*buffer2;

	(void)sig;
	buffer2 = buffer;
	sel = get_sel(NULL);
	env_sw();
	signal(SIGTSTP, suspend);
	sel->first = get_first(sel->first, sel->nb_arg);
	display_arg(sel->first, sel);
	tputs(tgoto(tgetstr("cm", &buffer2), 0, 0), 1, putint);
}
