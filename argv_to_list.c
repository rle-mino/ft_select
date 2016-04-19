/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:01:39 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/19 17:59:54 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				argv_to_list(char **argv, t_select *sel)
{
	int		i;
	t_arg	*av;
	t_arg	*start;

	i = 0;
	if (!(start = ft_memalloc(sizeof(t_arg))))
		sel_error(MALLER);
	start->next = NULL;
	start->prev = NULL;
	start->name = ft_strdup(argv[i]);
	av = start;
	sel->first = start;
	while (argv[++i])
	{
		if (!(av->next = ft_memalloc(sizeof(t_arg))))
			sel_error(MALLER);
		av->next->prev = av;
		av = av->next;
		av->name = ft_strdup(argv[i]);
		if (ft_strlen(argv[i]) > sel->max_len)
			sel->max_len = ft_strlen(argv[i]);
	}
	av->next = start;
	sel->first->prev = av;
}
