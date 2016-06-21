/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:01:39 by rle-mino          #+#    #+#             */
/*   Updated: 2016/06/21 19:52:50 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_arg				*creat_arg(char *name, t_arg *prev, t_arg *next)
{
	t_arg		*new;

	new = ft_memalloc(sizeof(t_arg));
	new->next = next;
	new->prev = prev;
	new->name = ft_strdup(name);
	lstat(name, &(new->stat_file));
	return (new);
}

t_arg						*get_first(t_arg *arg, int nb_arg)
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

void						argv_to_list(char **argv, t_select *sel)
{
	int		i;
	t_arg	*av;
	t_arg	*start;

	i = 0;
	start = creat_arg(argv[i], NULL, NULL);
	start->is_first = 1;
	av = start;
	sel->first = start;
	while (argv[++i])
	{
		av->next = creat_arg(argv[i], av, NULL);
		av = av->next;
		if (ft_strlen(argv[i]) > sel->max_len)
			sel->max_len = ft_strlen(argv[i]);
	}
	av->next = start;
	sel->first->prev = av;
}
