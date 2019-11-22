/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/11/22 14:35:36 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	init_vm(void)
{
	t_vm	new_vm;

	new_vm.process_list = NULL;
	ft_bzero((void *)new_vm.champ, sizeof(t_champ) * MAX_PLAYERS);
	ft_bzero((void *)new_vm.mem, sizeof(char) * MEM_SIZE);
	ft_bzero((void *)new_vm.mem_owner, sizeof(uint8_t) * MEM_SIZE);
	new_vm.current_cycle = 0;
	new_vm.cycles_to_die = CYCLE_TO_DIE;
	new_vm.cycles_to_dump = -1;
	new_vm.champ_amount = 0;
	new_vm.lives_in_cycle = 0;
	new_vm.next_ctod = CYCLE_TO_DIE;
	new_vm.ctod_nb = 0;
	new_vm.visu = OFF;
	new_vm.verbose = OFF;
	return (new_vm);
}
