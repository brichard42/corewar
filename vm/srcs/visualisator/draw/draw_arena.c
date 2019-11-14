/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:59:58 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/14 17:00:46 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*change_char_to_hexa(unsigned char c)
{
	char *str;

	if (!(str = ft_ulltoa_ubase(c, "0123456789abcedef")))
		return (NULL);
	return (str);
}

static int8_t	draw_arena_helper(t_window *win, t_vm *env)
{
	SDL_Rect	pos;
	SDL_Point	point;
	SDL_Rect	pos2;
	int			text[3];

	point = create_point(800, 152);
	if (create_tab_int3(text, 30, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	pos = create_rect(5, 190, 1800, 1100);
	pos2 = create_rect(5, 155, 1800, 30);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	if (draw_rectangle(win, pos2, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	if (draw_text(win, "ARENA", point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int8_t	draw_arena_helper_2(t_window *win, unsigned char c, int text[3], SDL_Point *pt)
{
	if ((create_tab_int3(text, 17, TEXT2, BOLD)) == FAILURE)
		return (FAILURE);
	if (c < 16)
	{
		if (draw_text(win, "0", *pt, text) == FAILURE)
			return (FAILURE);
		(*pt).x += 7;
	}
	return (SUCCESS);
}

int8_t	draw_arena(t_window *win, t_vm *env, int count)
{
	char		*str;
	SDL_Point	point;
	int			text[3];

	point = create_point(15, 195);
	if (draw_arena_helper(win, env) == FAILURE)
		return (FAILURE);
	while (count < MEM_SIZE)
	{
		if (!(str = change_char_to_hexa(env->mem[count])))
			return (FAILURE);
		if (draw_arena_helper_2(win, env->mem[count], text, &point) == FAILURE)
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (FAILURE);
		point.x = (env->mem[count] >= 16) ? point.x + 28 : point.x + 21;
		if ((count + 1) % 64 == 0 && count != 0)
		{
			point.y += 17;
			point.x = 15;
		}
		ft_strdel(&str);
		count++;
	}
	return (SUCCESS);
}
