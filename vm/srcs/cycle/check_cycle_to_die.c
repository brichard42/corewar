/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cycle_to_die.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:08:53 by brichard          #+#    #+#             */
/*   Updated: 2020/01/10 14:12:50 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	is_cycle_to_die(t_vm *env)
{
	return (env->cycle_to_die <= 0
			|| (env->current_sub_cycle - env->cycle_to_die) == 0);
}

static uint8_t	process_dies(t_vm *env, t_process *to_test)
{
	return (to_test->last_live <= (env->current_cycle - env->cycle_to_die)
				|| env->cycle_to_die <= 0);
}

static void		delete_dead_processes(t_vm *env, t_process **process_list)
{
	t_process	*tmp;

	tmp = NULL;
	if ((*process_list) == NULL)
		return ;
	delete_dead_processes(env, &(*process_list)->next);
	if (process_dies(env, *process_list) == TRUE)
	{
		if (env->verbose == ON)
			ft_printf("process with reg1 = %d is dead\n", (*process_list)->reg[0]);
		tmp = *process_list;
		if ((*process_list)->prev != NULL)
			(*process_list)->prev->next = (*process_list)->next;
		else
			(*process_list) = (*process_list)->next;
		free_process(&tmp);
	}
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
	if (is_cycle_to_die(env) == TRUE)
	{
		set_new_cycle_to_die(env);
		delete_dead_processes(env, &env->process_list);
		env->current_sub_cycle = 0;
	}
}
