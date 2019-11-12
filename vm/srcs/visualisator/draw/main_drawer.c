/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:12:46 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/12 18:02:17 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw(t_window *win, t_vm *env, int space_counter)
{
	int	count;

	count = 0;
	clear(win);
	if (draw_corewar(win) == FAILURE)
		return (FAILURE);
	if (draw_command_panel(win, space_counter))
		return (FAILURE);
	if (draw_infos(win, env, space_counter) == FAILURE)
		return (FAILURE);
	if (draw_arena(win, env, 0) == FAILURE)
		return (FAILURE);
	if (draw_process_list(win, env) == FAILURE)
		return (FAILURE);
	while (count < 4)
		if (draw_champions(win, env, count++) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

void	event_catcher(t_window *win, int *space_counter, uint8_t *play)
{
	if (win->event.type == SDL_QUIT)
		*play = 0;
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_ESCAPE))
		*play = 0;
	if ((win->event.type == SDL_KEYUP
			&& win->event.key.keysym.sym == SDLK_SPACE))
		*space_counter = (*space_counter == 0 || *space_counter == 2) ? 1 : 2;
}

int8_t	drawer(t_window *win, t_vm *env)
{
	int		ret;
	int		space_counter;
	uint8_t	play;

	play = 1;
	space_counter = 0;
	while (play)
	{
		if (draw(win, env, space_counter) == FAILURE)
			return (FAILURE);
		ret = SDL_PollEvent(&(win->event));
		if (ret != 0)
			event_catcher(win, &space_counter, &play);
		SDL_RenderPresent(win->renderer);
	}
	return (SUCCESS);
}
