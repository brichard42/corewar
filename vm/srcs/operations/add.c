/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:38:08 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 01:31:33 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Adds the value of the first and the second parameter (T_REG), and stock the
**	result in the third parameter (T_REG). If the result = 0 then 
**	carry = 1 else carry = 0.
**	if the result of the operation = 0 then carry = 0 else carry = 1.
*/

void	add(t_vm *vm, t_process *process)
{
	int		add;

	if (process->op.param[0] >= 1 && process->op.param[0] <= REG_NUMBER
		&& process->op.param[1] >= 1 && process->op.param[1] <= REG_NUMBER
		&& process->op.param[2] >= 1 && process->op.param[2] <= REG_NUMBER)
	{
		add = process->reg[process->op.param[0] - 1]
				+ process->reg[process->op.param[1] - 1];
		process->reg[process->op.param[2] - 1] = add;
		process->carry = ((add == 0) ? 1 : 0);
		if (vm->verbose)
			show_op(process);
	}
}
