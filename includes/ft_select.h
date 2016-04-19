/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 19:02:48 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/18 23:00:55 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

enum
{
	NO_ARG,
	MALLER,
	ENV_ERROR
};

# include "libft.h"
# include <curses.h>
# include <term.h>
# include <termios.h>

int		sel_error(int info);
int		init_env(void);

#endif
