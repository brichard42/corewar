/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:12:46 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/08 17:04:21 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Draw verifies that every drawing functions works properly and returns
**	FAILURE if any of those fails. Each functions deals with a specific part
**	of the renderer.
*/

int8_t	draw(t_window *win, t_vm *env, t_draw infos, t_process *process_list)
{
	int	count;

	count = 0;
	clear(win);
	if (draw_corewar(win) == FAILURE)
		return (FAILURE);
	if (draw_command_panel(win, infos.state))
		return (FAILURE);
	if (draw_infos(win, env, infos) == FAILURE)
		return (FAILURE);
	if (draw_arena(win, env, infos) == FAILURE)
		return (FAILURE);
	if (draw_procs_pannel(win, env, infos, process_list) == FAILURE)
		return (FAILURE);
	while (count < env->champ_amount)
	{
		if (draw_champions(win, env, count++) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

/*
**	"ESC" -> closes the window
**	"Red cross top left of window" -> closes the window
**	"Space" -> Launch/stop/restart
**	"Left/Right arrows" -> Change the process list to the process list of
**	another champ
**	"+/-" -> accelerate/deccelerate the cycle speed //not done yet
*/

void	event_catcher(t_window *win, t_draw *infos)
{
	if (win->event.type == SDL_QUIT)
		infos->play = 0;
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_ESCAPE))
		infos->play = 0;
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_SPACE))
		infos->state = (infos->state == 0
				|| infos->state == 2) ? 1 : 2;
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_RIGHT))
		infos->champ_ind = (infos->champ_ind < infos->champ_number - 1)
				? infos->champ_ind + 1 : 0;
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_LEFT))
		infos->champ_ind = (infos->champ_ind > 0)
				? infos->champ_ind - 1 : infos->champ_number - 1;
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_KP_PLUS))
		time_dealer(infos, 0);
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_KP_MINUS))
		time_dealer(infos, 1);
}

/*
**	This is the function that calls the fucntions that draws and collects the
**	different event used by the visualisator. Draw takes the infos and draws
**	in the renderer while using those. PollEvent recuperates the different input
**	the user enters on the keyboard. And event_catcher change some variables if
**	the input recuperated is usefull to the visualisator.
*/

int8_t	drawer(t_window *win, t_vm *env)
{
	int			ret;
	t_draw		infos;
	t_process	**d_process;

	ft_bzero((void *)&infos, sizeof(t_draw));
	infos.play = 1;
	infos.cycles_per_sec = 64;
	infos.time = 15624;
	infos.champ_number = env->champ_amount;
	d_process = &env->process_list;
	while (infos.play && *d_process != NULL && must_dump(env) == FALSE)
	{
		if (draw(win, env, infos, (*d_process)) == FAILURE)
			return (FAILURE);
		ret = SDL_PollEvent(&(win->event));
		if (ret != 0)
			event_catcher(win, &infos);
		SDL_RenderPresent(win->renderer);
		if (infos.state == ACTIVE)
			cycle_actualisator(env, (*d_process));
		usleep(infos.time);
	}
	return (SUCCESS);
}
