/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:38:03 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/09 12:01:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

SDL_Rect	create_champ_rect(t_window *win, t_vm *env, int champ_n)
{
	int	x;
	int	y;

	x = 1810 + ((champ_n == 1 || champ_n == 3) ? 248 : 0);
	y = 155 + ((champ_n == 2 || champ_n == 3) ? 248 : 0);
	return (create_rect(x, y, 242, 242));
}

int8_t	draw_champions(t_window *win, t_vm *env, int champ_n)
{
	SDL_Rect	pos;

	pos = create_champ_rect(win, env, champ_n); // HE ATTACK BUT HE DONT PROTEK
	draw_rectangle(win, pos, create_color(50, 50, 44, 255));
}
