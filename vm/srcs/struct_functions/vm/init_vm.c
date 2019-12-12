/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/12/12 12:04:27 by brichard         ###   ########.fr       */
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
	new_vm.current_cycle = 1;
	new_vm.cycle_to_die = CYCLE_TO_DIE;
	new_vm.cycle_to_dump = -1;
	new_vm.champ_amount = 0;
	new_vm.lives_in_cycle = 0;
	new_vm.last_live_champ_ind = -1;
	new_vm.ctod_nb = 0;
	new_vm.visu = OFF;
	new_vm.verbose = OFF;
	return (new_vm);
}
