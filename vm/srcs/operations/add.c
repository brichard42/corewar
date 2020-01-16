/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:38:08 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 05:28:54 by tlandema         ###   ########.fr       */
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
	int32_t	param1;
	int32_t	param2;
	int32_t	param3;

	param1 = process->op.param[0] - 1;
	param2 = process->op.param[1] - 1;
	param3 = process->op.param[2] - 1;
	if (param1 >= 0 && param1 <= REG_NUMBER - 1
		&& param2 >= 0 && param2 <= REG_NUMBER - 1
		&& param3 >= 0 && param3 <= REG_NUMBER - 1)
	{
		add = process->reg[param1] + process->reg[param2];
		process->reg[param3] = add;
		process->carry = ((add == 0) ? 1 : 0);
		if (vm->verbose & F_VERBOSE_OP)
			show_op(process);
	}
}
