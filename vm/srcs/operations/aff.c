/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:16:37 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 10:13:56 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// void vm doit pas etre la ajouter option -a

void	aff(t_vm *vm, t_process *process)
{
	int32_t	param1;

	(void)vm;
	param1 = process->reg[process->op.param[0]] - 1;
	ft_putchar(param1 % 256);
}
