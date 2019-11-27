/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/27 18:42:52 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar"

void    lfork(t_vm *vm, t_process *process)
{
    if (copy_process(process->pc + (process->op.param[0]), &process) == FAILURE)
        return ; //remplacer par un exit propre avec free des valurs interessees
    process->pc = (process->pc + 3) % MEM_SIZE;
}
