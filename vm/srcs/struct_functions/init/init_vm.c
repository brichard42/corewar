/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:27:42 by paullaurent       #+#    #+#             */
/*   Updated: 2019/10/23 13:45:39 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm    init_vm(void)
{
    t_vm    new_vm;

    new_vm.process_list = NULL;
    ft_bzero((void *)new_vm.champ_names, sizeof(int32_t) * MAX_PLAYERS);
    new_vm.cycles_to_die = CYCLE_TO_DIE;
    new_vm.mem = ft_strnew(MEM_SIZE);
    if (new_vm.mem)
        ft_bzero((void *)new_vm.mem, sizeof(int32_t) * MEM_SIZE);
    return (new_vm);
}