/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:47:14 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/26 15:55:47 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisator.h"

SDL_Color color_tab[NB_COLOR] = {
	{0, 0, 0, 255},
	{240, 240, 240, 255},
	{135, 206, 250, 255},
	{30, 144, 255, 255},
	{0, 0, 139, 255},
	{221, 110, 110, 255},
	{165, 89, 89, 255},
	{110, 70, 70, 255},
	{170, 220, 115, 255},
	{89, 165, 89, 255},
	{30, 100, 60, 255},
	{127, 255, 212, 255},
	{64, 224, 208, 255},
	{0, 139, 139, 255},
	{175, 175, 175, 255},
	{86, 86, 86, 255},
	{56, 56, 56, 255},
	{255, 195, 0, 255},
	{255, 165, 0, 255},
	{255, 130, 0, 255},
	{255, 250, 205, 255},
	{255, 228, 181, 255},
	{255, 255, 0, 255},
	{186, 85, 211, 255},
	{76, 96, 133, 255},
	{57, 160, 237, 255}
};

SDL_Color			get_color(int i)
{
	if (i < 0 || i >= NB_COLOR)
		return (color_tab[0]);
	return (color_tab[i]);
}

TTF_Font *get_font(int size)
{
	static TTF_Font *font_tab[NB_SIZE];

	if (font_tab[size] == NULL)
		font_tab[size] = TTF_OpenFont(FONT_PATH, size);
	return (font_tab[size]);
}

t_image *get_char(t_window *win, char c, int size, int color_index, int style_index)
{
	static	t_image *text_tab[NB_SIZE][NB_COLOR][NB_STYLE][255];
	char 	src[2];

	src[0] = c;
	src[1] = '\0';
	if (text_tab[size][color_index][style_index][c] == NULL)
	{
		TTF_Font *tmp_font = get_font(size);
		if (tmp_font == NULL)
			return (NULL);
		TTF_SetFontStyle(tmp_font, style_index);
		text_tab[size][color_index][style_index][c] = malloc_t_image(win, TTF_RenderText_Blended(tmp_font, src, get_color(color_index)));
	}
	return (text_tab[size][color_index][style_index][c]);
}

int				calc_text_len(t_window *win, char *str, int size, int color_index, int style_index)
{
	t_image			*image;
	int				i;
	int				delta;


	i = 0;
	delta = 0;
	while (i < str[i])
	{
		image = get_char(win, str[i], size, color_index, style_index);
		delta += image->surface->w;
		i++;
	}
	return (delta);
}

int draw_text(t_window *win, char *str, SDL_Point pos, int size, int color_index, int style_index)
{
	t_image *tmp_img;
	SDL_Rect coord;
	int delta;
	int len;
	int i;

	len = strlen(str);
	i = 0;
	delta = 0;
	while (i < len)
	{
		tmp_img = get_char(win, str[i], size, color_index, style_index);
		if (tmp_img == NULL)
			return (-1);

		coord = create_rect(pos.x + delta, pos.y, tmp_img->surface->w, tmp_img->surface->h);
		draw_image(win, tmp_img, coord);
		delta += coord.w;
		i++;
	}
	return (delta);
}

int				draw_centred_text(t_window *win, char *str, SDL_Point pos, int size, int color_index, int style_index)
{
	int x = calc_text_len(win, str, size, color_index, style_index);
	int y = get_char(win, 'M', size, color_index, style_index)->surface->h;

	return (draw_text(win, str, create_point(pos.x - x / 2, pos.y - y / 2), size, color_index, style_index));
}
