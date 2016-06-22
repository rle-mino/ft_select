/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 19:03:25 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/22 19:03:46 by rle-mino         ###   ########.fr       */
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
