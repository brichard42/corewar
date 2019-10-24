/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:46:53 by tlandema          #+#    #+#             */
/*   Updated: 2019/10/24 14:01:11 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	draw_corewar(WINDOW *core)
{
	ft_putstr("\e[34m");
	mvwprintw(core , 1, 1, "%ls", LOGO0);
	mvwprintw(core , 2, 1, "%ls", LOGO1);
	mvwprintw(core , 3, 1, "%ls", LOGO2);
	mvwprintw(core , 4, 1, "%ls", LOGO3);
	mvwprintw(core , 5, 1, "%ls", LOGO4);
	mvwprintw(core , 6, 1, "%ls", LOGO5);
	mvwprintw(core , 7, 1, "%ls", LOGO6);
	mvwprintw(core , 8, 1, "%ls", LOGO7);
	wrefresh(core);
	ft_putstr("\e[30m");
}
