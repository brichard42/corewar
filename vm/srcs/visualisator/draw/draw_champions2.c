/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_champions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 05:33:11 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/07 13:50:36 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	draw_champion_name(t_window *win, char *name, SDL_Point point,
		int text[3])
{
	int		i;
	int		j;
	char	tmp[27];

	j = 0;
	if ((i = ft_strlen(name)) > 26)
	{
		while (j < i)
		{
			ft_strncpy(tmp, &name[j], 26);
			if (draw_text(win, tmp, point, text) == FAILURE)
				return (FAILURE);
			point.y += 11;
			j += 26;
		}
	}
	else if (draw_text(win, name, point,
			text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int8_t	draw_last_live(t_window *win, int last_live, SDL_Point point,
		int text[3])
{
	char	*str;

	if (!(str = ft_lltoa(last_live)))
		return (FAILURE);
	if (draw_text(win, str, point, text) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
