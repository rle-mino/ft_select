/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 14:45:33 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/21 19:39:45 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			delete_useless_time(char **split)
{
	int		i;

	i = ft_strlen(split[3]);
	while (--i)
	{
		if (split[3][i] == ':')
		{
			split[3][i] = '\0';
			break ;
		}
	}
}

void			adjust_t(time_t ti)
{
	char	**split;
	char	*tmp;

	tmp = ctime(&ti);
	ft_putchar_fd(' ', get_fd(-1));
	split = ft_strsplit(tmp, ' ');
	ft_putstr_fd(split[1], get_fd(-1));
	ft_putchar_fd(' ', get_fd(-1));
	if (ft_strlen(split[2]) == 1)
		ft_putchar_fd('0', get_fd(-1));
	ft_putstr_fd(split[2], get_fd(-1));
	delete_useless_time(split);
	split[4][ft_strlen(split[4]) - 1] = '\0';
	ft_putchar_fd(' ', get_fd(-1));
	ft_putstr_fd(split[4], get_fd(-1));
	ft_putchar_fd(' ', get_fd(-1));
	split = ft_free_tab(split);
}

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

void			display_type(t_select *sel)
{
	mode_t	st_mode;

	st_mode = sel->first->stat_file.st_mode;
	if (S_ISDIR(st_mode))
	{
		ft_putstr_fd(CU_YELLOW, get_fd(-1));
		ft_putstr_fd(" DIRECTORY ", get_fd(-1));
	}
	else if (S_ISLNK(st_mode))
	{
		ft_putstr_fd(CU_MAGENTA, get_fd(-1));
		ft_putstr_fd(" SYMB LINK ", get_fd(-1));
	}
	else if (S_ISREG(st_mode))
	{
		ft_putstr_fd(CU_RED, get_fd(-1));
		ft_putstr_fd(" FILE      ", get_fd(-1));
	}
	else
	{
		ft_putstr_fd(CU_WHITE, get_fd(-1));
		ft_putstr_fd(" ????????? ", get_fd(-1));
	}
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
