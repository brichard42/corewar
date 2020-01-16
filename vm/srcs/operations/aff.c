/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:16:37 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 04:41:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// void vm doit pas etre la

void	aff(t_vm *vm, t_process *process)
{
	(void)vm;
	int32_t	param1;

	param1 = process->reg[process->op.param[0]] - 1;
	ft_putchar(param1 % 256);
}
