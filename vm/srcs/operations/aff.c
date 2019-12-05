/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:16:37 by brichard          #+#    #+#             */
/*   Updated: 2019/12/01 16:00:04 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_vm *vm, t_process *process)
{
	vm->current_cycle = vm->current_cycle;
	ft_putchar(process->op.param[0] % 256);
}
