/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:19:25 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/19 17:17:53 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_env(t_select *sel)
{
	struct termios	term;
	struct termios	reset;
	char		buffer[3];

	(void)sel;
	if (tcgetattr(0, &term))
		return (sel_error(ENV_ERROR));
	reset = term;
	term.c_lflag = ~(ICANON);
	ft_putstr("\033[?1049h\033[H");
	tcsetattr(1, TCSANOW, &term);
	while (read(0, buffer, 3))
		if (buffer[0] == 27)
			break ;
	ft_putstr("\033[?1049l");
	tcsetattr(1, TCSANOW, &reset);
	return (0);
}
