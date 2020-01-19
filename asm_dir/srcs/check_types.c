/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Required type(s) is known by adding T_***, max value: 7.
** 	7 --> All types accepted.
**	6 ==> T_IND | T_DIR
**	5 ==> T_IND | T_REG
**	4 ==> T_IND
**	3 ==> T_DIR | T_REG
**	2 ==> T_DIR
**	1 ==> T_REG
*/
static void	check_param_type(t_cmd *cmd, int param_i, t_asm *asmr)
{
	int	type;

	type = cmd->params[param_i].type;
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 7)
		return ;
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 6 &&
		(type == IND_CODE || type == DIR_CODE))
			return ;
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 5 &&
		(type == IND_CODE || type == REG_CODE))
			return ;
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 4 &&
		(type == IND_CODE))
			return ;
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 3 &&
		(type == DIR_CODE || type == REG_CODE))
			return ;
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 2 &&
		(type == DIR_CODE))
			return ;
	if (asmr->op_tab[cmd->op_code - 1].type_param[param_i] == 1 &&
		(type == REG_CODE))
			return ;
	exit_msg(ERROR_PARAM_TYPE, NULL, &(cmd->nb_line), asmr);
}

/*
** Check each param if param's type match the instruction requirement.
*/
void		check_types(t_asm *asmr)
{
	t_cmd 	*list;
	int		i;

	list = asmr->list;
	while (list)
	{
		i = 0;
		while (i < list->nb_param)
		{
			check_param_type(list, i, asmr);
			i++;
		}
		list = list->next;
	}
}