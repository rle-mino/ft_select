/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:42:06 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/24 18:23:41 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_tolower(int c)
{
	return (c >= 65 && c <= 90 ? c + 32 : c);
}
