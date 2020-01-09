/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:53:59 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/09 13:02:48 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	main_visu(t_vm *env)
{
	t_window	*win;
	t_draw		infos;

	ft_bzero((void *)&infos, sizeof(t_draw));
	infos.play = 1;
	infos.cycles_per_sec = 32;
	infos.champ_number = env->champ_amount;
	if (!(win = open_window("Test")))
		return (FAILURE);
	if (drawer(win, env) == FAILURE)
		return (FAILURE);
	SDL_DestroyWindow(win->window);
	SDL_DestroyRenderer(win->renderer);
	winner(env);
	return (SUCCESS);
}

void	cycle_actualisator(t_vm *env, t_process *process)
{
	check_cycle_to_die(env);
	exec_proc_list(env, process);
	++env->current_cycle;
	++env->current_sub_cycle;
}
