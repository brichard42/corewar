/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/10/23 17:35:35 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_vm(t_vm *to_delete)
{
	int		i;

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
