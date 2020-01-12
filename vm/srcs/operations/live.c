/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:02:53 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/12 22:49:52 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	live(t_vm *vm, t_process *process)
{
	int	n;

	++vm->live_count;
	process->last_live = vm->current_cycle;
	n = -process->op.param[0];
	if (n >= 1 && n <= vm->champ_amount)
	{
		vm->champ[n - 1].last_live_cycle = vm->current_cycle;
		vm->winner_index = n - 1;
		if (vm->verbose & F_VERBOSE_LIVE)
			ft_printf("Player %d (%s) is said to be alive\n", n,
					vm->champ[n - 1].name);
	}
	if (vm->verbose)
		show_op(process);
}
