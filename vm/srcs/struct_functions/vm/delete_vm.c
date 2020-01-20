/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2020/01/20 16:13:57 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visualisator.h"

void	delete_vm(t_vm *to_delete)
{
	if (to_delete != NULL)
	{
		free_process_list(&to_delete->process_list);
		if (to_delete->win != NULL)
		{
			SDL_DestroyWindow(((t_window *)to_delete->win)->window);
			SDL_DestroyRenderer(((t_window *)to_delete->win)->renderer);
		}
		ft_bzero((void *)to_delete->champ, sizeof(t_champ) * MAX_PLAYERS);
		ft_bzero((void *)to_delete->mem, sizeof(char) * MEM_SIZE);
		ft_bzero((void *)to_delete->mem_owner, sizeof(uint8_t) * MEM_SIZE);
	}
}
