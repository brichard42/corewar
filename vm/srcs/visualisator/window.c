#include "visualisator.h"

t_window *open_window(char *name)
{
	t_window *win;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	win = malloc(sizeof(t_window));
	SDL_DisplayMode current;
	SDL_GetDesktopDisplayMode(0, &current);
	win->x = current.w;
	win->y = current.h;
	win->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, win->x, win->y, 0);
	win->renderer = SDL_CreateRenderer(win->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawBlendMode(win->renderer, SDL_BLENDMODE_BLEND);
	return (win);
}

void clear(t_window *win)
{
	SDL_SetRenderDrawColor(win->renderer, 0, 0, 0, 0);
	SDL_RenderClear(win->renderer);
}

SDL_Rect create_rect(int x, int y, int w, int h)
{
	SDL_Rect	result;

	result.x = x;
	result.y = y;
	result.w = w;
	result.h = h;
	return (result);
}

SDL_Point create_point(int x, int y)
{
	SDL_Point	result;

	result.x = x;
	result.y = y;
	return (result);
}

SDL_Color create_color(int r, int g, int b, int a)
{
	SDL_Color	result;

	result.r = r;
	result.g = g;
	result.b = b;
	result.a = a;
	return (result);
}

void render(t_window *win)
{
	SDL_RenderPresent(win->renderer);
}

void draw_corewar(t_window *win)
{
	SDL_Rect	pos;

	pos = create_rect(150, 150, 300, 70);
	clear(win);
	draw_centred_border_rectangle(win, pos, create_color(0, 0, 255, 255), create_color(0, 123, 255, 255), 5);
	draw_centred_text(win, "mieux ", create_point(pos.x, pos.y), 32, LIGHT_BLUE, BOLD);
	render(win);
}

void handle_event(t_window *win)
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
			if ((win->event.type == SDL_KEYUP && win->event.key.keysym.sym == SDLK_ESCAPE))
				play = false;
		}
	}
}
