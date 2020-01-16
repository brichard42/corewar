/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:49 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 01:57:19 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Same as fork but the IDX-MOD is not applied on the new pc.
*/

//	REMPLACER LE RETURN PAR UN EXIT AVEC FREE DES VALEURS A FREE

void	lfork(t_vm *vm, t_process *process)
{
	vm->current_cycle = vm->current_cycle;
	if (copy_process(vm, modulo(process->pc + (process->op.param[0]), MEM_SIZE),
			process) == FAILURE)
		return ;
}
