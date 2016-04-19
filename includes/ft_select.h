/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:02:48 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/19 18:00:59 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include <curses.h>
# include <term.h>
# include <termios.h>

enum
{
	NO_ARG,
	MALLER,
	ENV_ERROR
};

typedef struct		s_args
{
	char			*name;
	struct s_args	*next;
	struct s_args	*prev;
	int				selected;
}					t_arg;

typedef struct		s_select
{
	struct s_args	*first;
	size_t			max_len;
}					t_select;

int					sel_error(int info);
int					init_env(t_select *sel);
void				argv_to_list(char **argv, t_select *sel);

#endif
