/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_process_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:51:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/11 18:09:04 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw_process_list(t_window *win, t_vm *env)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			*text;

	point = create_point(1955, 660);
	text = create_tab_int3(30, TEXT2, BOLD);
	pos = create_rect(1810, 650, 490, 50);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "Process List :", point, text) == FAILURE)
		return (FAILURE);
	pos = create_rect(1810, 705, 490, 585);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
