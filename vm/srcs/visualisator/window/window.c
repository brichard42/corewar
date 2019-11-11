/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:44:45 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/11 15:20:53 by tlandema         ###   ########.fr       */
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
