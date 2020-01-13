/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:13:27 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/13 11:54:52 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Transfert direct Registre > RAM / Registre. Charge le contenu du
** registre passé en premier parametre dans le second parametre.
*/

void	func(t_vm *vm, t_process *process)
{
	unsigned int	addr;
	int32_t			first_param;

	first_param = process->op.param[0];
	addr = process->op.pos_op_code + (process->op.param[1] % IDX_MOD);
	vm->mem[modulo(addr, MEM_SIZE)] =
									(char)(process->reg[first_param - 1] >> 24);
	vm->mem_owner[modulo(addr, MEM_SIZE)] = process->num;
	vm->mem[modulo(addr + 1, MEM_SIZE)] =
									(char)(process->reg[first_param - 1] >> 16);
	vm->mem_owner[modulo(addr + 1, MEM_SIZE)] = process->num;
	vm->mem[modulo(addr + 2, MEM_SIZE)] =
									(char)(process->reg[first_param - 1] >> 8);
	vm->mem_owner[modulo(addr + 2, MEM_SIZE)] = process->num;
	vm->mem[modulo(addr + 3, MEM_SIZE)] = (char)process->reg[first_param - 1];
	vm->mem_owner[modulo(addr + 3, MEM_SIZE)] = process->num;
}

void	st(t_vm *vm, t_process *process)
{
	if ((process->op.type_param[0] == REG_CODE && (process->op.param[0] < 1
					|| process->op.param[0] > REG_NUMBER))
					|| (process->op.type_param[1] == REG_CODE
					&& (process->op.param[1] < 1
					|| process->op.param[1] > REG_NUMBER)))
		return ;
	if (process->op.type_param[1] == REG_CODE)
		process->reg[process->op.param[1] - 1] =
										process->reg[process->op.param[0] - 1];
	else
		func(vm, process);
	if (vm->verbose)
		show_op(process);
}
