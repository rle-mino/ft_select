/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:45:33 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/22 19:07:33 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			display_arg_name(t_select *sel)
{
	size_t	len;
	size_t	marge;
	size_t	i;

	len = ft_strlen(sel->first->name);
	marge = (sel->max_len + 2);
	ft_putstr_fd(sel->first->name, get_fd(-1));
	i = ft_strlen(sel->first->name);
	while (i++ < marge)
		ft_putchar_fd(' ', get_fd(-1));
}

void			put_type(char *color, char *type)
{
	ft_putstr_fd(color, get_fd(-1));
	ft_putstr_fd(type, get_fd(-1));
}

void			display_type(t_select *sel)
{
	mode_t	st_mode;

	st_mode = sel->first->stat_file.st_mode;
	if (S_ISDIR(st_mode))
		put_type(CU_YELLOW, " DIRECTORY  ");
	else if (S_ISLNK(st_mode))
		put_type(CU_MAGENTA, " SYMB LINK  ");
	else if (S_ISREG(st_mode))
		put_type(CU_RED, " FILE       ");
	else if (S_ISCHR(st_mode) || S_ISBLK(st_mode))
		put_type(CU_BLUE, " PERIPHERAL ");
	else
		put_type(CU_WHITE, " ?????????  ");
}

void			update_status(t_select *sel)
{
	int			i;

	i = 0;
	if (sel->space)
	{
		ft_putstr_fd(C_RES, get_fd(-1));
		tputs(tgetstr("sc", NULL), 1, putint);
		tputs(tgoto(tgetstr("cm", NULL), 0, sel->io->ws_row - 1), 1, putint);
		tputs(tgetstr("cd", NULL), 1, putint);
		ft_putstr_fd(CU_WHITE, get_fd(-1));
		display_arg_name(sel);
		ft_putstr_fd(CU_CYAN, get_fd(-1));
		if (sel->first->stat_file.st_mtime)
			adjust_t(sel->first->stat_file.st_mtime);
		else
			ft_putstr_fd("???? ", get_fd(-1));
		display_type(sel);
		ft_putstr_fd(C_RES, get_fd(-1));
		tputs(tgetstr("rc", NULL), 1, putint);
	}
}
