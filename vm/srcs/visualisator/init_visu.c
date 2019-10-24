/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 06:17:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/24 13:58:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int8_t	window_initialiser(t_win *win)
{
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	curs_set(0);
	refresh();
	if (windows_manager(win) == FAILURE)
		return (FAILURE);
	draw_corewar(win->corewar);
    return (SUCCESS);
}

int8_t			init_visu(t_vis *v_data, char *mem)
{
	setlocale(LC_ALL, "");
	if (!(v_data = (t_vis *)ft_memalloc(sizeof(t_vis))))
		return (FAILURE);
	v_data->fps = 32768;
	ft_strcpy(v_data->arena, mem);
	window_initialiser(&v_data->windows);
	while (1)
	{};
	return (SUCCESS);
}
