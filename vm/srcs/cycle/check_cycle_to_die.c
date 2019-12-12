/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle_to_die.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:08:53 by brichard          #+#    #+#             */
/*   Updated: 2019/12/12 12:39:13 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	is_cycle_to_die(t_vm *env)
{
	return ((env->cycle_to_die > 0 && env->current_cycle % env->cycle_to_die == 0) || env->cycle_to_die <= 0);
			}
void			test(t_process **croc)
{
	ft_printf("reg1 = %d\n", (*croc)->reg[0]);
}
void			check_cycle_to_die(t_vm *env)
{
	if (is_cycle_to_die(env) == TRUE)
	{
		env->cycle_to_die -= CYCLE_DELTA;//GAFFE OVERFLOW NEGATIF
		ft_printf("DIE DIE DIE!\n");
		process_map(&env->process_list, test);
	}
}
