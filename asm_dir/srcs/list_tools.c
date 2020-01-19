/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:30:42 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/07 09:43:50 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Create and initialize a new instruction.
*/
t_cmd	*new_elem(t_asm *asmr)
{
	t_cmd	*elem;
	int 	i;

	i = 0;
	if (!(elem = (t_cmd *)ft_memalloc(sizeof(t_cmd))))
		exit_msg(ERROR_MALLOC, NULL, NULL, asmr);
	elem->op_code = 0;
	elem->label = NULL;
	elem->size = 0;
	elem->nb_line = 0;
	elem->nb_param = 0;
	while (i < MAX_ARGS_NUMBER)
	{
		elem->params[i].str = NULL;
		elem->params[i].type = 0;
		elem->params[i].value = 0;
		elem->params[i++].temp = NULL;
	}
	elem->next = NULL;
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
	t_cmd 	*cur;
	int		i;

	i = 0;
	while (list)
	{
		cur = list;
		if (cur->label)
			free(cur->label);
		while (i < MAX_ARGS_NUMBER)
			free(cur->params[i++].str);
		list = cur->next;
		free(cur);
	}
}
