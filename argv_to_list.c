/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:01:39 by rle-mino          #+#    #+#             */
/*   Updated: 2016/04/23 20:42:12 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg				*get_first(t_arg *arg, int nb_arg)
{
	t_arg	*tmp;

	tmp = arg;
	while (arg->is_first == 0 && --nb_arg)
		arg = arg->next;
	if (nb_arg == 0)
	{
		tmp->is_first = 1;
		arg = tmp;
	}
	return (arg);
}

void				argv_to_list(char **argv, t_select *sel)
{
	int		i;
	t_arg	*av;
	t_arg	*start;

	i = 0;
	if (!(start = ft_memalloc(sizeof(t_arg))))
		sel_error(MALLER);
	start->is_first = 1;
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
		av->is_first = 0;
		if (ft_strlen(argv[i]) > sel->max_len)
			sel->max_len = ft_strlen(argv[i]);
	}
	av->next = start;
	sel->first->prev = av;
}
