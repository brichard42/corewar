/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:21:10 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/11 15:21:24 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw_corewar(t_window *win)
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
