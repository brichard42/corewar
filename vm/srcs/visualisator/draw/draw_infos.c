/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:08:22 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/16 16:32:04 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int8_t	draw_infos_text(t_window *win, t_vm *env, int space_counter)
{
	SDL_Point	point;
	int			text[3];
	int			tmp;
	char		*str_tmp;

	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	point = create_point(1815, 10);
	if (draw_text(win, "Infos : ", point, text) == FAILURE)
		return (FAILURE);
	point.x += 45;
	point.y += 25;
	if ((tmp = draw_text(win, "- Cycles : ", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if ((str_tmp = ft_lltoa(env->current_cycle)) == NULL)
		return (FAILURE);
	if (space_counter == ACTIVE)
		env->current_cycle++;
	if (draw_text(win, str_tmp, point, text) == FAILURE)
		return (FAILURE);
	ft_strdel(&str_tmp);
	return (SUCCESS);
}

/*
** rajouter dans le deuxieme if la fonction qui regarde si tout les process ont
** dit je suis alive si oui remettre check_amount a 0 of course et cycles_to_die
** -CYCLE_DELTA.
*/

static int8_t	check_infos_text(t_window *win, t_vm *env, int space_counter)
{
	static uint8_t	check_amount = 0;
	static uint32_t	cycle_since_last_death = 0;

	if (env->cycles_to_die == 0)
		env->cycles_to_die = CYCLE_TO_DIE;
	if (space_counter == ACTIVE)
	{
		if (++cycle_since_last_death == env->cycles_to_die)
		{
			cycle_since_last_death = 0;
			check_amount++;
			//ici la func
		}
		if (check_amount == MAX_CHECKS)
		{
			if (env->cycles_to_die <= 50)
				return (THE_END);
			check_amount = 0;
			env->cycles_to_die -= 50;
		}
	}
	return (CONTINUE);
}

static int8_t	draw_infos_text2(t_window *win, t_vm *env)
{
	int				text[3];
	char			*str;
	SDL_Point		point;
	int				tmp;

	point = create_point(1860, 70);
	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	if ((str = ft_lltoa(env->cycles_to_die)) == NULL)
		return (FAILURE);
	if ((tmp = draw_text(win, "- Cycles to die : ", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if (draw_text(win, str, point, text) == FAILURE)
		return (FAILURE);
	ft_strdel(&str);
	return (SUCCESS);
}

static int8_t	draw_infos_text3(t_window *win, t_vm *env, int cycles_per_sec)
{
	int			text[3];
	char		*str;
	SDL_Point	point;
	int			tmp;

	point = create_point(1860, 105);
	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	if ((str = ft_lltoa(cycles_per_sec)) == NULL)
		return (FAILURE);
	if ((tmp = draw_text (win, "- Cycles per sec : ", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if (draw_text(win, str, point, text) == FAILURE)
		return (FAILURE);
	ft_strdel(&str);
	return (SUCCESS);
}
/*
** ici if ret == the_end on renvoie failure en realite c'est simplement la fin
** du programme il faut donc check qui est le dernier a avoir dit qu'il etait en
** vie.
*/

int8_t			draw_infos(t_window *win, t_vm *env, t_draw infos)
{
	SDL_Rect	pos;
	int8_t		ret;

	pos = create_rect(1810, 5, 490, 145);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)))
		return (FAILURE);
	if (draw_infos_text(win, env, infos.state) == FAILURE)
		return (FAILURE);
	if ((ret = check_infos_text(win, env, infos.state)) && ret == THE_END)
		return (FAILURE);
	if (draw_infos_text2(win, env) == FAILURE)
		return (FAILURE);
	if (draw_infos_text3(win, env, infos.cycles_per_sec) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
