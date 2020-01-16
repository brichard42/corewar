/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:49 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 15:43:23 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Same as fork but the IDX-MOD is not applied on the new pc.
*/

//	REMPLACER LE RETURN PAR UN EXIT AVEC FREE DES VALEURS A FREE

void	lfork(t_vm *vm, t_process *process)
{
	int32_t	param1;

	param1 = process->op.param[0];
	if (copy_process(vm, modulo(process->pc + param1, MEM_SIZE),
			process) == FAILURE)
		return ;
	if (vm->verbose & F_VERBOSE_OP)
		show_op(process);
}
