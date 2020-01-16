/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 11:45:29 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 01:13:48 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Substract the value of the second to the first parameter (T_REG), and stock
**	the result int he third parameter (T_REG). If the result = 0 then 
**	carry = 1 else carry = 0.
*/

void	sub(t_vm *vm, t_process *process)
{
	int		sub;

	if (process->op.param[0] >= 1 && process->op.param[0] <= REG_NUMBER
			&& process->op.param[1] >= 1 && process->op.param[1] <= REG_NUMBER
			&& process->op.param[2] >= 1 && process->op.param[2] <= REG_NUMBER)
	{
		sub = process->reg[process->op.param[0] - 1]
				- process->reg[process->op.param[1] - 1];
		process->reg[process->op.param[2] - 1] = sub;
		process->carry = (sub == 0 ? 1 : 0);
		if (vm->verbose)
			show_op(process);
	}
}
