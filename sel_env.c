/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:19:25 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/22 21:12:15 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void				cursor_sw(void)
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

static int				init_term(struct termios **term, struct termios **reset)
{
	if (!(*term = ft_memalloc(sizeof(struct termios))))
		sel_error(MALLER);
	if (!(*reset = ft_memalloc(sizeof(struct termios))))
		sel_error(MALLER);
	if (tcgetattr(0, *term) == -1)
		return (0);
	if (tcgetattr(0, *reset) == -1)
		return (0);
	return (1);
}

static int				set_env(struct termios *term,
						struct termios *reset,
						char *term_name,
						int i)
{
	if (i % 2 == 0)
	{
		if (tgetent(NULL, term_name) == ERR)
			return (0);
		term->c_lflag &= ~(ICANON);
		term->c_lflag &= ~(ECHO);
		tcsetattr(0, TCSADRAIN, term);
		ft_putstr("\033[?1049h\033[H");
		cursor_sw();
		return (1);
	}
	else
	{
		ft_putstr("\033[?1049l");
		tcsetattr(1, TCSANOW, reset);
		cursor_sw();
		return (1);
	}
}

int						env_sw(void)
{
	static int				i = 0;
	static struct termios	*term;
	static struct termios	*reset;
	char					*term_name;

	term_name = getenv("TERM");
	if (!term)
		if (!(init_term(&term, &reset)))
			return (0);
	if (!(set_env(term, reset, term_name, i)))
		return (0);
	i = i ^ 1;
	return (0);
}

int						init_env(t_select *sel)
{
	int		*pos;

	if (!(pos = ft_memalloc(sizeof(int) * 2)))
		sel_error(MALLER);
	if (!(sel->io = ft_memalloc(sizeof(struct winsize))))
		sel_error(MALLER);
	env_sw();
	ft_select(sel, pos);
	return (env_sw());
}
