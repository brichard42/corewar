/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:49 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/12 22:49:20 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	REMPLACER LE RETURN PAR UN EXIT AVEC FREE DES VALEURS A FREE
*/

void	lfork(t_vm *vm, t_process *process)
{
	vm->current_cycle = vm->current_cycle;
	if (copy_process(vm, modulo(process->pc + (process->op.param[0]), MEM_SIZE),
			process) == FAILURE)
		return ;
}
