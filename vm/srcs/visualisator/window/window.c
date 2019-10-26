/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:44:45 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/26 17:32:45 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisator.h"

t_window	*open_window(char *name)
{
	t_window		*win;
	SDL_DisplayMode	current;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	if (!(win = malloc(sizeof(t_window))))
		return (NULL);
	if (SDL_GetDesktopDisplayMode(0, &current) < 0)
		return (NULL);
	win->x = current.w;
	win->y = current.h;
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

void		clear(t_window *win)
{
	SDL_SetRenderDrawColor(win->renderer, 76, 96, 133, 0);
	SDL_RenderClear(win->renderer);
}

void		draw_corewar(t_window *win)
{
	SDL_Rect	pos;
	SDL_Rect	pos2;

	clear(win);
	pos = create_rect(5, 5, 500, 100);
	pos2 = create_rect(5, 110, 500, 40);
	draw_rectangle(win, pos, create_color(50, 50, 44, 255));
	draw_rectangle(win, pos2, create_color(50, 50, 44, 255));
	draw_text(win, "COREWAR", create_point(pos.x + 70, pos.y + 18), 64, TEXT, BOLD);
	draw_text(win, "By: Armoulin, Brichard, Plaurent, Tlandema", create_point(pos.x + 70, pos2.y + 11), 16, TEXT, BOLD);
	SDL_RenderPresent(win->renderer);
}

void		handle_event(t_window *win)
{
	int		ret;
	bool	play;

	play = true;
	while (play == true)
	{
		draw_corewar(win);
		ret = SDL_PollEvent(&(win->event));
		if (ret != 0)
		{
			if (win->event.type == SDL_QUIT)
				play = false;
			if ((win->event.type == SDL_KEYUP
					&& win->event.key.keysym.sym == SDLK_ESCAPE))
				play = false;
		}
	}
}
