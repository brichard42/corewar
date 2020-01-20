/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infos2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:20:08 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/19 16:35:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw_infos_cycle(t_window *win, t_vm *env, SDL_Point point, int text[3])
{
	char *str;

	if (env->cycle_to_die <= 0)
	{
		if (draw_text(win, "0", point, text) == FAILURE)
			return (FAILURE);
	}
	else
	{
		if ((str = ft_lltoa(env->cycle_to_die)) && str == NULL)
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (FAILURE);
		ft_strdel(&str);
	}
	return (SUCCESS);
}

int8_t	draw_speed_cursor(t_window *win, int speed_cursor)
{
	SDL_Rect	pos;
	int			x;

	x = 3;
	pos = create_rect(1900, 118, (x * speed_cursor), 20);
	if (draw_rectangle(win, pos, create_color(250, 169, 22, 180)))
		return (FAILURE);
	return (SUCCESS);
}
