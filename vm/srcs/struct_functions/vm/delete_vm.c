/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:42:31 by paullaurent       #+#    #+#             */
/*   Updated: 2019/10/23 15:05:58 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    delete_vm(t_vm *to_delete)
{
    int     i;

    i = -1;
    if (to_delete != NULL)
    {
        free_process(&to_delete->process_list);
        while (++i < MAX_PLAYERS)
            if (to_delete->champ_names[i] != NULL)
            {
                free(to_delete->champ_names[i]);
                to_delete->champ_names[i] = NULL;
            }
        to_delete->cycles_to_die = 0;
        if (to_delete->mem != NULL)
            free(to_delete->mem);
    }
}