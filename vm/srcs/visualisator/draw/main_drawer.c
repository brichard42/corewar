/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:12:46 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/16 13:51:10 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw(t_window *win, t_vm *env, t_draw infos)
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
	if (draw_arena(win, env, infos.state) == FAILURE)
		return (FAILURE);
	if (draw_process_pannel(win, env, infos.champ_ind) == FAILURE)
		return (FAILURE);
	while (count < 4)
		if (draw_champions(win, env, count++) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

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
		infos->champ_ind = (infos->champ_ind < infos->champ_number)
				? infos->champ_ind + 1 : 0;
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_LEFT))
		infos->champ_ind = (infos->champ_ind > 0)
				? infos->champ_ind - 1 : infos->champ_number - 1;
}

int8_t	drawer(t_window *win, t_vm *env)
{
	int		ret;
	t_draw	infos;

	ft_bzero((void *)&infos, sizeof(t_draw));
	infos.play = 1;
	infos.cycles_per_sec = 32;
	while (infos.play)
	{
		if (draw(win, env, infos) == FAILURE)
			return (FAILURE);
		ret = SDL_PollEvent(&(win->event));
		if (ret != 0)
			event_catcher(win, &infos);
		SDL_RenderPresent(win->renderer);
	}
	return (SUCCESS);
}
