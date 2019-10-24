/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 06:55:23 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/24 13:53:58 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISATOR_H
# define VISUALISATOR_H

#include "corewar.h"
#include <locale.h>
#include <libc.h>
#include <ncurses.h>
#include <pthread.h>
#include "draw.h"

/*
** ------TYPEDEF VISUAL STRUCTURE---------
*/
typedef struct		s_win
{
	WINDOW *corewar;
	WINDOW *arena;
	WINDOW *infos;
	WINDOW *player[MAX_PLAYERS];
}					t_win;

/*
** ------TYPEDEF VISUAL STRUCTURE---------
*/
typedef struct      s_vis
{
	t_win	windows;
	char	arena[MEM_SIZE];
    int		fps;
}                   t_vis;

/*
**  -------VISUALISATOR FUNCTIONS-------
*/

int8_t	init_visu(t_vis *v_data, char *mem);
int8_t	windows_manager(t_win *win);
void	draw_corewar(WINDOW *core);

#endif
