/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 18:57:59 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/23 14:59:50 by rle-mino         ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
	return (0);
}
