/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle_to_die.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:08:53 by brichard          #+#    #+#             */
/*   Updated: 2020/01/16 08:58:29 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	is_cycle_to_die(t_vm *env)
{
	return (env->cycle_to_die <= 0
			|| (env->current_sub_cycle - env->cycle_to_die) == 0);
}

/*
**	if (env->verbose == ON)
**		ft_printf("Check for live_count and MAX_CHECKS\n");
**		if (env->verbose == ON)
**			ft_printf("Applying CYCLE_DELTA\n");
*/

static void		set_new_cycle_to_die(t_vm *env)
{
	++env->live_check_count;
	if (env->cycle_to_die > 0
			&& (env->live_count >= NBR_LIVE
				|| env->live_check_count >= MAX_CHECKS))
	{
		env->cycle_to_die -= CYCLE_DELTA;
		if (env->verbose & F_VERBOSE_CYCLE)
			ft_printf("Cycle to die is now %d\n", env->cycle_to_die);
		env->live_count = 0;
		env->live_check_count = 0;
	}
}

void			check_cycle_to_die(t_vm *env)
{
	if (is_cycle_to_die(env) == TRUE)
	{
		kill_processes(env);
		set_new_cycle_to_die(env);
		env->current_sub_cycle = 0;
	}
}
