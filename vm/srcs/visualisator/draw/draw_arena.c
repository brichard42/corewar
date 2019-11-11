/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:59:58 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/11 19:50:39 by tlandema         ###   ########.fr       */
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

int8_t	draw_arena_helper(t_window *win, t_vm *env)
{
	SDL_Rect	pos;
	SDL_Point	point;
	SDL_Rect	pos2;
	int			*text;

	point = create_point(800, 152);
	text = create_tab_int3(30, TEXT2, BOLD);
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

int		*draw_arena_helper_2(t_window *win, t_vm *env, int count, SDL_Point *pt)
{
	int					*text;

	if ((text = create_tab_int3(17, TEXT2, BOLD)) == NULL)
		return (NULL);
	if (env->mem[count] < 16)
	{
		if (draw_text(win, "0", *pt, text) == FAILURE)
			return (NULL);
		(*pt).x += 7;
	}
	return (text);
}

int8_t	draw_arena(t_window *win, t_vm *env, int count)
{
	char		*str;
	SDL_Point	point;
	int			*text;

	point = create_point(15, 195);
	if (draw_arena_helper(win, env) == FAILURE)
		return (FAILURE);
	while (count < MEM_SIZE)
	{
		if (!(str = change_char_to_hexa(env->mem[count])))
			return (FAILURE);
		if (!(text = draw_arena_helper_2(win, env, count++, &point)))
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (FAILURE);
		point.x = (env->mem[count] >= 16) ? point.x + 28 : point.x + 21;
		if (count % 64 == 0)
		{
			point.y += 17;
			point.x = 15;
		}
		ft_strdel(&str);
	}
	return (SUCCESS);
}
