/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/11/22 14:48:03 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	init_process(int32_t reg_1, int32_t pc)
{
	t_process	new_process;

	new_process.next = NULL;
	new_process.prev = NULL;
	// new_process.op = NULL;
	ft_bzero((void *)new_process.reg, sizeof(int32_t) * REG_NUMBER);
	new_process.reg[0] = reg_1;
	new_process.pc = pc;
	new_process.cycles_left = 0;
	new_process.carry = 0;
	new_process.last_live = 0;
	return (new_process);
}
