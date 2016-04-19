/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:57:59 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/18 23:02:06 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		sel_error(int info)
{
	if (info == NO_ARG)
		ft_putendl_fd("NO ARGUMENT", 2);
	if (info == MALLER)
	{
		ft_putendl_fd("MALLOC ERROR, BREAK", 2);
		exit(EXIT_FAILURE);
	}
	if (info == ENV_ERROR)
	{
		ft_putendl_fd("ENVIRONMENT NOT AVAILABLE", 2);
	}
	return (0);
}
