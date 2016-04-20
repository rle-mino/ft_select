/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:19:25 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/21 00:28:46 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		reset_env(struct termios reset)
{
	ft_putstr("\033[?1049l");
	tcsetattr(1, TCSANOW, &reset);
	return (1);
}

static void		ft_select(t_select *sel, struct termios term)
{
	char	buffer[6];

	(void)term;
	while (42)
	{
		buffer[1] = 0;
		display_arg(sel->first, sel->max_len);
		read(0, buffer, 5);
		if (buffer[0] == 27 && buffer[1] == 0)
			break ;
	}
}

int				init_env(t_select *sel)
{
	struct termios	term;
	struct termios	reset;

	sel->term_name = getenv("TERM");
	if (tcgetattr(0, &term) == -1)
		return (sel_error(ENV_ERROR));
	if (tgetent(NULL, sel->term_name) == ERR)
		return (sel_error(ENV_ERROR));
	reset = term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	ft_putstr("\033[?1049h\033[H");
	tcsetattr(0, TCSADRAIN, &term);
	ft_select(sel, term);
	return (reset_env(reset));
}
