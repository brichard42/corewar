/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:11:32 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/24 13:56:38 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int8_t	window_creator(int dim[4], WINDOW **window)
{
	if (!(*window = newwin(dim[0], dim[1], dim[2], dim[3])))
		return (FAILURE);
	if ((box(*window, 0, 0) == ERR))
		return (FAILURE);
	if ((wrefresh(*window) == ERR))
		return (FAILURE);
	return (SUCCESS);
}

int8_t			windows_manager(t_win *win)
{
	if (window_creator((int[4]){10, 57, 0, 0}, &win->corewar) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
