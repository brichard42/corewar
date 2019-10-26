#include "visualisator.h"

t_image load_t_image(t_window *win, SDL_Surface *p_surface)
{
	t_image result;

	result.surface = p_surface;

	result.texture = SDL_CreateTextureFromSurface(win->renderer, result.surface);

	return (result);
}

t_image *malloc_t_image(t_window *win, SDL_Surface *p_surface)
{
	t_image *result;

	result = malloc(sizeof(t_image));

	result->surface = p_surface;

	result->texture = SDL_CreateTextureFromSurface(win->renderer, result->surface);

	return (result);
}

t_image load_t_image_from_file(t_window *win, char *path)
{
	t_image result;

	result.surface = IMG_Load(path);

	result.texture = SDL_CreateTextureFromSurface(win->renderer, result.surface);

	return (result);
}

void draw_image(t_window *win, t_image *image, SDL_Rect dest)
{
	SDL_RenderCopy(win->renderer, image->texture, NULL, &dest);
}
