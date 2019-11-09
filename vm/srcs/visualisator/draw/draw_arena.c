/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:59:58 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/08 08:57:21 by tlandema         ###   ########.fr       */
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

int8_t	draw_arena(t_window *win, t_vm *env)
{
	SDL_Rect	pos;
	SDL_Point	point;
	SDL_Point	point2;
	SDL_Rect	pos2;
	int			count;
	int			*text;
	int			*text2;
	char		*str;

	count = 0;
	text = create_tab_int3(17, TEXT2, BOLD);
	text2 = create_tab_int3(30, TEXT2, BOLD);
	pos = create_rect(5, 190, 1800, 1100);
	pos2 = create_rect(5, 155, 1800, 30);
	point.x = 15;
	point2.x = 800;
	point.y = 195;
	point2.y = 152;
	draw_rectangle(win, pos, create_color(50, 50, 44, 255));
	draw_rectangle(win, pos2, create_color(50, 50, 44, 255));
	draw_text(win, "ARENA", point2, text2);
	while (count < MEM_SIZE)
	{
		str = change_char_to_hexa(env->mem[count]);
		if (env->mem[count] < 16)
		{
			draw_text(win, "0", point, text);
			point.x += 7;
		}
		draw_text(win, str, point, text);
		if (env->mem[count] < 16)
			point.x += 21;
		else
			point.x += 28;
		count++;
		if (count % 64 == 0)
		{
			point.y += 17;
			point.x = 15;
		}
		ft_memdel((void * )&str);
	}
	return (SUCCESS);
}
