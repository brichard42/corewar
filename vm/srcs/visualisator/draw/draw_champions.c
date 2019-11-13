/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:38:03 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/13 16:13:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static SDL_Point	create_name_point(int champ_n)
{
	int	x;
	int	y;

	x = 1840 + ((champ_n == 1 || champ_n == 3) ? 248 : 0);
	y = 170 + ((champ_n == 2 || champ_n == 3) ? 248 : 0);
	return (create_point(x, y));
}

static SDL_Point	create_alive_point(int champ_n)
{
	int	x;
	int	y;

	x = 1840 + ((champ_n == 1 || champ_n == 3) ? 248 : 0);
	y = 350 + ((champ_n == 2 || champ_n == 3) ? 248 : 0);
	return (create_point(x, y));
}

static SDL_Rect		create_champ_rect(int champ_n)
{
	int	x;
	int	y;

	x = 1810 + ((champ_n == 1 || champ_n == 3) ? 248 : 0);
	y = 155 + ((champ_n == 2 || champ_n == 3) ? 248 : 0);
	return (create_rect(x, y, 242, 242));
}

int8_t				draw_champions(t_window *win, t_vm *env, int champ_n)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			text[3];
	int			tmp;

	tmp = 19 + champ_n;
	if (create_tab_int3(text, 13, tmp, BOLD) == FAILURE)
		return (FAILURE);
	point = create_name_point(champ_n);
	pos = create_champ_rect(champ_n);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	if (draw_text(win, env->champs_data[champ_n].champ_name, point, text) == FAILURE)
		return (FAILURE);
	point = create_alive_point(champ_n);
	if ((tmp = draw_text(win, "Last time alive : ", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if (draw_text(win, "0", point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
