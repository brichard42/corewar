/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:59:58 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/07 14:53:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw_arena(t_window *win, t_vm *env)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			count;
	int			*text;

	count = 0;
	text = create_tab_int3(17, TEXT2, BOLD);
	pos = create_rect(5, 155, 1800, 1136);
	point.x = 5;
	point.y = 160;
	draw_rectangle(win, pos, create_color(50, 50, 44, 255));
	env->mem[10] = 1;
	while (count < MEM_SIZE && count < 64)
	{
		draw_text(win, ft_ulltoa_ubase(env->mem[count], "0123456789abcdef"), point, text);
		point.x += 7;
		if (env->mem[count] == 0)
			draw_text(win, "0", point, text);
		point.x += 14;
		draw_text(win, " ", point, text);
		count++;
	}
	return (SUCCESS);
}
