/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:30:42 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/30 14:41:38 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Create and initialize a new instruction.
*/

t_cmd	*new_elem(t_asm *asmr)
{
	t_cmd	*elem;

	if (!(elem = (t_cmd *)ft_memalloc(sizeof(t_cmd))))
		exit_msg(ERROR_MALLOC, NULL, NULL, asmr);
	ft_bzero((void *)elem, sizeof(t_cmd));
	elem->multi_label = FALSE;
	return (elem);
}

/*
** Add an instruction at the end of the linked lise.
*/

t_cmd	*add_elem(t_cmd *list, t_cmd *elem)
{
	t_cmd	*cur;

	if (!list)
		return (elem);
	cur = list;
	while (cur->next)
		cur = cur->next;
	cur->next = elem;
	return (list);
}

/*
** Free all malloced memory in the linked list.
*/

void	clear_list(t_cmd *list)
{
	t_cmd	*cur;
	int		i;

	while (list)
	{
		cur = list;
		ft_strdel(&cur->label);
		i = 0;
		while (i < MAX_ARGS_NUMBER)
			ft_strdel(&cur->params[i++].str);
		list = cur->next;
		ft_memdel((void **)&cur);
	}
}
