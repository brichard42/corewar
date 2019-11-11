/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_command_panel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:35:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/11 14:48:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int8_t	command_more_info(t_window *win, int *text)
{
	SDL_Point	point;
	SDL_Point	point2;
	SDL_Point	point3;

	point = create_point(520, 120);
	point2 = create_point(1200, 50);
	point3 = create_point(1200, 120);
	if (draw_text(win, "\'+\'       : Speed Up", point, text) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "\'-\'                       : Speed Down", point2,
			text) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "\'Arrow Up/Down\' : Move in process list", point3,
			text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	command_info(t_window *win, int i)
{
	SDL_Point	point;
	int			*text;

	if (!(text = create_tab_int3(20, TEXT2, BOLD)))
		return (FAILURE);
	point = create_point(520, 50);
	if (i == 0)
	{
		if (draw_text(win, "\'space\' : Install champions", point,
				text) == FAILURE)
			return (FAILURE);
	}
	else if (i % 2 == 1)
	{
		if (draw_text(win, "\'space\' : Launch", point, text) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if (draw_text(win, "\'space\' : Pause", point, text) == FAILURE)
			return (FAILURE);
	}
	if (command_more_info(win, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int8_t			draw_command_panel(t_window *win, int i)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			*command_text;

	point = create_point(1300, 15);
	command_text = create_tab_int3(30, TEXT2, BOLD);
	pos = create_rect(510, 5, 1790, 145);
	draw_rectangle(win, pos, create_color(50, 50, 44, 255));
	draw_text(win, "COMMANDS :", point, command_text);
	if (command_info(win, i) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
