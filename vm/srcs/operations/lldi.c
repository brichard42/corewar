/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:58:12 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 01:55:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Works exactly as the ldi operation appart from the fact that the IDX_MOD
**	is not applied.
*/

static unsigned int	get_value(t_vm *vm, unsigned int addr)
{
	unsigned int	value;

	value = 0;
	value |= (unsigned char)vm->mem[modulo(addr, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 1, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 2, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 3, MEM_SIZE)];
	return (value);
}

void				lldi(t_vm *vm, t_process *process)
{
	unsigned int	addr;

	if (!check_params_ldi_lldi(process))
		return ;
	if (process->op.type_param[0] == REG_CODE)
		process->op.param[0] = process->reg[process->op.param[0] - 1];
	else if (process->op.type_param[0] == IND_CODE)
		process->op.param[0] = get_indirecte(vm, &process->op, 0);
	if (process->op.type_param[1] == REG_CODE)
		process->op.param[1] = process->reg[process->op.param[1] - 1];
	addr = (process->op.param[0] + process->op.param[1])
		+ process->op.pos_op_code;
	process->reg[process->op.param[2] - 1] = get_value(vm, addr);
	if (vm->verbose)
		show_op(process);
}
