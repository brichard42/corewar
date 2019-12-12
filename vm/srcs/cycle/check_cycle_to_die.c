/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle_to_die.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:08:53 by brichard          #+#    #+#             */
/*   Updated: 2019/12/12 18:15:55 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	is_cycle_to_die(t_vm *env)
{
	return ((env->cycle_to_die > 0 && env->current_cycle % env->cycle_to_die == 0) || env->cycle_to_die <= 0);
}

void			check_last_live(t_process **process_list)
{
	free_process_list(process_list);
}

static void		set_new_cycle_to_die(t_vm *env)
{
	if (env->verbose == ON)
		ft_printf("Executing check for live count and MAX_CHECKS\n");
	if (env->cycle_to_die > 0
			&& (env->live_count >= NBR_LIVE
				|| ++env->live_check_count >= MAX_CHECKS))
	{
		env->cycle_to_die -= CYCLE_DELTA;
		env->live_count = 0;
		env->live_check_count = 0;
	}
}

void			check_cycle_to_die(t_vm *env)
{
	if (is_cycle_to_die(env) == TRUE)
	{
		set_new_cycle_to_die(env);
		ft_printf("DIE DIE DIE!\n");
		process_map(&env->process_list, check_last_live);
	}
}
