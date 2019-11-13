/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_process_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:51:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/13 15:57:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw_process_header(t_window *win, t_vm *env, int champ_num)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			tmp;
	int			text[3];
	char		*str;

	point = create_point(1925, 665);
	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	pos = create_rect(1810, 650, 490, 50);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	if ((tmp = draw_text(win, "Process List of champ Num ", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if ((str = ft_lltoa(env->champs_data[champ_num].chp_num)) == NULL)
		return (FAILURE);
	if ((draw_text(win, str, point, text)) == FAILURE)
		return (FAILURE);
	ft_strdel(&str);
}

int8_t	draw_process_list(t_window *win, t_vm *env, int champ_num)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			text[3];

	if (draw_process_header(win, env, champ_num) == FAILURE)
		return (FAILURE);
	pos = create_rect(1810, 705, 490, 585);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
