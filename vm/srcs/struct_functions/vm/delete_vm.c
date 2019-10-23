/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:42:31 by paullaurent       #+#    #+#             */
/*   Updated: 2019/10/23 13:46:32 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    delete_vm(t_vm *to_delete)
{
    if (to_delete != NULL)
    {
        free_process(&to_delete->process_list);
        ft_bzero((void *)to_delete->champ_names, sizeof(int32_t) * MAX_PLAYERS);
        to_delete->cycles_to_die = 0;
        if (to_delete->mem)
            free(to_delete->mem);
    }
}