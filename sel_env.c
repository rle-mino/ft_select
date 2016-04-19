/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:19:25 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/19 00:50:21 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_env(void)
{
	struct termios	term;
	struct termios	reset;
	char			buffer[3];

	if (tcgetattr(0, &term))
	return (sel_error(ENV_ERROR));
	reset = term;
	term.c_lflag = (ECHO | ECHONL | ICANON | IEXTEN | ISIG);
	tcsetattr(1, TCSANOW, &term);
	while (read(0, buffer, 3))
	if (buffer[0] == 27)
	break ;
	tcsetattr(1, TCSANOW, &reset);
	return (0);
}
