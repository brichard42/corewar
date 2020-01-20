/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:49 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/20 13:01:08 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Same as fork but the IDX-MOD is not applied on the new pc.
*/

void	lfork(t_vm *vm, t_process *process)
{
	int32_t	param1;

	param1 = process->op.param[0];
	if (copy_process(vm, modulo(process->pc + param1, MEM_SIZE),
			process) == FAILURE)
	{
		delete_vm(vm);
		exit (EXIT_FAILURE);
	}
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
