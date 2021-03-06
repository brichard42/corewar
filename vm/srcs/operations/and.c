/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:39:25 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 15:44:47 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Performs a bitwise AND operation for the values of the first two
**	arguments (T_DIR/T_REG/T_IND) and writes the result to the third
**	argument. (T_REG)
*/

void	and(t_vm *vm, t_process *process)
{
	int32_t	param1;
	int32_t	param2;

	if ((process->op.type_param[0] == REG_CODE && (process->op.param[0] < 1
		|| process->op.param[0] > REG_NUMBER))
		|| (process->op.type_param[1] == REG_CODE
		&& (process->op.param[1] < 1 || process->op.param[1] > REG_NUMBER))
		|| (process->op.param[2] < 1 || process->op.param[2] > REG_NUMBER))
		return ;
	if (process->op.type_param[0] == REG_CODE)
		param1 = process->reg[process->op.param[0] - 1];
	else if (process->op.type_param[0] == IND_CODE)
		param1 = get_indirecte(vm, &process->op, 0);
	else
		param1 = process->op.param[0];
	if (process->op.type_param[1] == REG_CODE)
		param2 = process->reg[process->op.param[1] - 1];
	else if (process->op.type_param[1] == IND_CODE)
		param2 = get_indirecte(vm, &process->op, 1);
	else
		param2 = process->op.param[1];
	process->reg[process->op.param[2] - 1] = param1 & param2;
	process->carry = ((param1 & param2) == 0 ? 1 : 0);
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
