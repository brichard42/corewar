/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/12/12 15:08:18 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    lfork(t_vm *vm, t_process *process)
{
    vm->current_cycle = vm->current_cycle;
    if (copy_process(vm, modulo(process->pc + (process->op.param[0]), MEM_SIZE), process) == FAILURE)
        return ; //remplacer par un exit propre avec free des valurs interessees
    // process->pc = (process->pc + 3) % MEM_SIZE;
}
