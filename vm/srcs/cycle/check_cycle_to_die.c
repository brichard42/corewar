/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle_to_die.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:08:53 by brichard          #+#    #+#             */
/*   Updated: 2019/12/16 16:25:44 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	is_cycle_to_die(t_vm *env)
{
	return (env->cycle_to_die <= 0
			|| (env->current_sub_cycle - env->cycle_to_die) == 0);
}

void			check_last_live(t_vm *env, t_process **process_list)
{
	if ((*process_list == NULL))
		return ;
	if ((*process_list)->last_live <= env->current_cycle - env->cycle_to_die
			|| env->cycle_to_die <= 0)
		
	{
		if (env->verbose == ON)
			ft_printf("process with reg1 = %d is dead\n", (*process_list)->reg[0]);
		free_process(process_list);
		check_last_live(env, process_list);
	}
	else
		check_last_live(env, &(*process_list)->next);
}

static void		set_new_cycle_to_die(t_vm *env)
{
	if (env->verbose == ON)
		ft_printf("Check for live_count and MAX_CHECKS\n");
	++env->live_check_count;
	if (env->cycle_to_die > 0
			&& (env->live_count >= NBR_LIVE
				|| env->live_check_count >= MAX_CHECKS))
	{
		if (env->verbose == ON)
			ft_printf("Applying CYCLE_DELTA\n");
		env->cycle_to_die -= CYCLE_DELTA;
		env->live_count = 0;
		env->live_check_count = 0;
	}
}

void			check_cycle_to_die(t_vm *env)
{
	env->process_list->last_live = env->current_cycle;
	if (is_cycle_to_die(env) == TRUE)
	{
		set_new_cycle_to_die(env);
		check_last_live(env, &env->process_list);
		env->current_sub_cycle = 0;
	}
}
