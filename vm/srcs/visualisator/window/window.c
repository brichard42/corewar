/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:44:45 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/09 11:53:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_window		*open_window(char *name)
{
	t_window		*win;
	SDL_DisplayMode	current;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	if (!(win = malloc(sizeof(t_window))))
		return (NULL);
	if (SDL_GetDesktopDisplayMode(0, &current) < 0)
		return (NULL);
	win->x = current.w * 0.9;
	win->y = current.h * 0.9;
	if (!(win->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, win->x, win->y, 0)))
		return (NULL);
	if (!(win->renderer = SDL_CreateRenderer(win->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		return (NULL);
	if (SDL_SetRenderDrawBlendMode(win->renderer, SDL_BLENDMODE_BLEND) < 0)
		return (NULL);
	return (win);
}

void			clear(t_window *win)
{
	SDL_SetRenderDrawColor(win->renderer, 76, 96, 133, 0);
	SDL_RenderClear(win->renderer);
}

static int8_t	draw_corewar(t_window *win)
{
	SDL_Rect	pos;
	SDL_Rect	pos2;
	int			*cor_text;
	int			*name_text;

	cor_text = create_tab_int3(64, TEXT2, BOLD);
	name_text = create_tab_int3(16, TEXT2, BOLD);
	pos = create_rect(5, 5, 500, 100);
	pos2 = create_rect(5, 110, 500, 40);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE
		|| draw_rectangle(win, pos2, create_color(50, 50, 44, 255)) == FAILURE
			|| draw_text(win, "COREWAR", create_point(pos.x + 70, pos.y + 18),
			cor_text) == FAILURE
			|| draw_text(win, "By: Armoulin, Brichard, Plaurent, Tlandema",
			create_point(pos.x + 70, pos2.y + 11), name_text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int8_t			drawer(t_window *win, t_vm *env)
{
	int		ret;
	int		tet;
	bool	play;
	int		truc;

	play = true;
	tet = 0;
	while (play == true)
	{
		clear(win);
		draw_corewar(win);
		draw_arena(win, env);
		if (draw_command_panel(win, tet) == FAILURE)
			return (FAILURE);
		truc = 0;
		while (truc < 4)
			draw_champions(win, env, truc++);
		ret = SDL_PollEvent(&(win->event));
		if (ret != 0)
		{
			if (win->event.type == SDL_QUIT)
				play = false;
			if ((win->event.type == SDL_KEYUP
					&& win->event.key.keysym.sym == SDLK_ESCAPE))
				play = false;
			if ((win->event.type == SDL_KEYUP
					&& win->event.key.keysym.sym == SDLK_SPACE))
					tet++;
		}
		SDL_RenderPresent(win->renderer);
	}
	return (SUCCESS);
}
