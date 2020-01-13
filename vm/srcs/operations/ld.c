/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 22:43:21 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/13 18:41:02 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Transfert direct RAM > Registre. Charge le premier parametre dans le
** registre passé en second parametre. Si la valeur du premier
** registery est egale a zero, alors le carry passe a l'etat un, sinon a
** l'etat zero.
*/

static void	put_ind_in_reg(t_vm *vm, t_process *process, int reg_n)
{
	int		addr;

	addr = process->op.param[0] % IDX_MOD;
	process->reg[reg_n] = 0;
	process->reg[reg_n] |= (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr, MEM_SIZE)];
	process->reg[reg_n] <<= 8;
	process->reg[reg_n] |= (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 1, MEM_SIZE)];
	process->reg[reg_n] <<= 8;
	process->reg[reg_n] |= (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 2, MEM_SIZE)];
	process->reg[reg_n] <<= 8;
	process->reg[reg_n] |= (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 3, MEM_SIZE)];
}

/*
**	L52 : cas ou type_param[0] = T_IND
**	L54 : cas ou type_param[0] = T_DIR
*/

void		ld(t_vm *vm, t_process *process)
{
	int	reg_nb;

	reg_nb = process->op.param[1] - 1;
	if (process->op.type_param[0] == IND_CODE)
		put_ind_in_reg(vm, process, reg_nb);
	else
		process->reg[reg_nb] = process->op.param[0];
	process->carry = (process->reg[0] == 0 ? 1 : 0);
	if (vm->verbose)
		show_op(process);
}
