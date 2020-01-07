/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_process_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:51:01 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/07 14:52:42 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int8_t	draw_procs_header(t_window *win, t_vm *env, int champ_num)
{
	SDL_Rect	pos;
	SDL_Point	point;
	int			tmp;
	int			text[3];
	char		*str;

	point = create_point(1905, 665);
	if (create_tab_int3(text, 20, TEXT2, BOLD) == FAILURE)
		return (FAILURE);
	pos = create_rect(1810, 650, 490, 50);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	if ((tmp = draw_text(win, "Process List of champ Num ", point, text))
			&& tmp == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if ((str = ft_lltoa(env->champ[champ_num].num)) == NULL)
		return (FAILURE);
	if ((draw_text(win, str, point, text)) == FAILURE)
		return (FAILURE);
	ft_strdel(&str);
	return (SUCCESS);
}
static int8_t	draw_one_process2(t_window *win, t_process *proc, int text[3], SDL_Point point)
{
	char	*str;
	int		tmp;

	tmp = 0; // pu ca mere enleve
	//if ((tmp = draw_text(win, proc->op.name, point, text)) == FAILURE)
	//	return (FAILURE);
	point.x += tmp;
	if ((tmp = draw_text(win, "in : ", point, text)) == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if ((str = ft_lltoa(proc->cycles_left)) == NULL)
		return (FAILURE);
	if ((tmp = draw_text(win, str, point, text)) == FAILURE)
		return (FAILURE);
	ft_strdel(&str);
	point.x += tmp + 60;
	if ((tmp = draw_text(win, "cycles ", point, text)) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	draw_one_process(t_window *win, t_process *proc, int text[3], SDL_Point point)
{
	char		*str;
	int			tmp;

	if ((str = ft_lltoa(proc->pc / 64 + 1)) == NULL)
		return (FAILURE);
	if ((tmp = draw_text(win, str, point, text)) == FAILURE)
		return (FAILURE);
	ft_strdel(&str);
	point.x += tmp;
	if ((str = ft_lltoa(proc->pc % 64 + 1)) == NULL)
		return (FAILURE);
	if ((tmp = draw_text(win, "X", point, text)) == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if ((tmp = draw_text(win, str, point, text)) == FAILURE)
		return (FAILURE);
	point.x += tmp + 35;
	if ((tmp = draw_text(win, "Action : ", point, text)) == FAILURE)
		return (FAILURE);
	point.x += tmp;
	if (draw_one_process2(win, proc, text, point) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int8_t	draw_procs_list(t_window *win, t_vm	*env, t_draw infos,
				t_process *process_list)
{
	t_process	*proc_tmp;
	SDL_Point	point;
	int			list_size;
	int			champ_num;
	int			text[3];

	point = create_point(1825, 710);
	list_size = 0;
	proc_tmp = process_list;
	champ_num = env->champ[infos.champ_ind].num;
	create_tab_int3(text, 20, 19 + infos.champ_ind, BOLD);
	while (proc_tmp && list_size < 20)
	{
		if (proc_tmp->reg[0] == -champ_num)
		{
			if (draw_one_process(win, proc_tmp, text, point) == FAILURE)
				return (FAILURE);
			point.y += 29;
			list_size++;
		}
		proc_tmp = proc_tmp->next;
	}
	return (SUCCESS);
}

/*
**	Draws the process list with the action the process will launch and how many
**	cycle it will take them to execute the action. It also prints the placement
**	of the processus, coupled with the underlining (not done yet)
**	in the arena we are able to see properly where every process is and acts.
*/

int8_t			draw_procs_pannel(t_window *win, t_vm *env, t_draw infos,
				t_process *process_list)
{
	SDL_Rect	pos;

	if (draw_procs_header(win, env, infos.champ_ind) == FAILURE)
		return (FAILURE);
	pos = create_rect(1810, 705, 490, 585);
	if (draw_rectangle(win, pos, create_color(50, 50, 44, 255)) == FAILURE)
		return (FAILURE);
	if (draw_procs_list(win, env, infos, process_list) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
