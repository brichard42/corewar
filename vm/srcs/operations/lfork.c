/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/12/01 16:04:33 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    lfork(t_vm *vm, t_process *process)
{
    vm->current_cycle = vm->current_cycle;
    if (copy_process(process->pc + (process->op.param[0]), &process) == FAILURE)
        return ; //remplacer par un exit propre avec free des valurs interessees
    process->pc = (process->pc + 3) % MEM_SIZE;
}
