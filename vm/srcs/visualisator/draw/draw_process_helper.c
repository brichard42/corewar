/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_process_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:13:01 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 15:34:53 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*action_name(int32_t op_code)
{
	static char	*ret[17] = {"live", "ld", "st", "add", "sub", "and", "or", "xor"
						, "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork"
						, "aff"};

	return (ret[op_code - 1]);
}

int32_t	draw_process_pos(t_window *win, t_process *proc, int text[3],
				SDL_Point point)
{
	char *str;

	if ((str = ft_lltoa(proc->pc / 64 + 1)) == NULL)
		return (FAILURE);
	if ((draw_text(win, str, point, text)) == FAILURE)
		return (FAILURE);
	ft_strdel(&str);
	point.x += 20;
	if ((str = ft_lltoa(proc->pc % 64 + 1)) == NULL)
		return (FAILURE);
	if (draw_text(win, "X", point, text) == FAILURE)
		return (FAILURE);
	point.x += 12;
	if (draw_text(win, str, point, text) == FAILURE)
		return (FAILURE);
	ft_strdel(&str);
	point.x += 45;
	return (point.x);
}


int32_t	draw_process_num(t_window *win, t_process *proc, int text[3],
				SDL_Point point)
{
	char	*str;
	int32_t	tmp;

	if ((str = ft_lltoa(proc->num)) == NULL)
		return (FAILURE);
	if ((tmp = draw_text(win, str, point, text)) && tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if (draw_text(win, "] ", point, text) == FAILURE)
		return (FAILURE);
	return (point.x + 20);
}
