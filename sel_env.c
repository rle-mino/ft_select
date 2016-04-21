/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:19:25 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/21 21:57:28 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		cursor_sw(void)
{
	static	int	i = 1;
	char		buffer1[1024];
	char		*buffer2;

	buffer2 = buffer1;
	if (i == 1)
		tputs(tgetstr("vi", &buffer2), 1, putint);
	else
		tputs(tgetstr("ve", &buffer2), 1, putint);
	i = i ^ 1;
}

static int		reset_env(struct termios reset)
{
	ft_putstr("\033[?1049l");
	tcsetattr(1, TCSANOW, &reset);
	cursor_sw();
	return (1);
}

static void		cursor_move(int *pos, t_select *sel)
{
	char	buffer1[1024];
	char	*buffer2;

	buffer2 = buffer1;
	tputs(tgoto(tgetstr("cm", &buffer2), pos[0], pos[1]), 1, putint);
	tputs(tgetstr("us", &buffer2), 1, putint);
	ft_putstr(sel->first->name);
	tputs(tgetstr("ue", &buffer2), 1, putint);
	tputs(tgoto(tgetstr("cm", &buffer2), pos[0], pos[1]), 1, putint);
}

static void		ft_select(t_select *sel)
{
	char	buffer[6];
	int		*pos;

	if (!(pos = ft_memalloc(sizeof(int) * 2)))
		sel_error(MALLER);
	display_arg(sel->first, sel->max_len, sel->io);
	while (42)
	{
		cursor_move(pos, sel);
		buffer[1] = 0;
		read(0, buffer, 5);
		if (buffer[0] == 033 && buffer[1] == 0)
			return ;
		else if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'C')
			move_right(pos, sel);
		else if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'D')
			move_left(pos, sel);
		else if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'A')
			move_up(pos, sel);
		else if (buffer[0] == 033 && buffer[1] == '[' && buffer[2] == 'B')
			move_down(pos, sel);
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
	if (!(sel->io = ft_memalloc(sizeof(struct winsize))))
		sel_error(MALLER);
	ft_putstr("\033[?1049h\033[H");
	tcsetattr(0, TCSADRAIN, &term);
	cursor_sw();
	ft_select(sel);
	return (reset_env(reset));
}
