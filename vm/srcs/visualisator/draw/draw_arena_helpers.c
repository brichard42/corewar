/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_arena_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:42:06 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/23 16:22:44 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw_structure_sides(t_window *win)
{
	SDL_Point	point;
	int			text[3];
	char		*str;
	int			i;

	i = 0;
	point = create_point(48, 205);
	if (create_tab_int3(text, 14, BLUE, BOLD)
			== FAILURE)
		return (FAILURE);
	while (++i <= 64)
	{
		if (!(str = ft_lltoa(i)))
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (FAILURE);
		ft_strdel(&str);
		point.x = (i % 2) ? point.x + 27 : point.x + 28;
	}
	point.x = 15;
	point.y = 227;
	i = 0;
	while (++i <= 64)
	{
		if (!(str = ft_lltoa(i)))
			return (FAILURE);
		if (draw_text(win, str, point, text) == FAILURE)
			return (FAILURE);
		ft_strdel(&str);
		point.y = (i % 2) ? point.y + 16 : point.y + 17;
	}
	return (SUCCESS);
}

/*int8_t	underliner(t_window *win, t_vm *env)
{
	SDL_Point	point;
	int			text[3];

	point = create_point(15, 198);
	if (create_tab_int3(text, 17, TEXT2 + env->mem_owner[count], BOLD)
			== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}*/
