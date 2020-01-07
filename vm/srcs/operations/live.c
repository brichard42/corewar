/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:02:53 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/07 15:02:56 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    live(t_vm *vm, t_process *process)
{
	int     n;

	// ft_printf("live\n");
	++vm->live_count;
	process->last_live = vm->current_cycle;
	n = -process->reg[0];//numero du joueur
		//ft_printf("a baise %d   %d \n",vm->champ[n - 1].last_live_cycle, n);
	// si le numero est negatif il faut le mettre en positif d'apres le pdf russe
	if (n >= 1 && n <= vm->champ_amount)
	{
		vm->champ[n - 1].last_live_cycle = vm->current_cycle;

		vm->winner_index = n - 1;
		// ft_printf("Player nb %d is said to be alive\n", n);
	}
	if (vm->verbose)
			show_op(process);
}
