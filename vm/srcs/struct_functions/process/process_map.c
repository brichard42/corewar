/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:31:04 by brichard          #+#    #+#             */
/*   Updated: 2019/12/16 16:09:39 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			process_map(t_vm *env, t_process **process_list, t_proc_apply apply)
{

	if (process_list == NULL || *process_list == NULL)
		return ;
	if (apply != NULL)
		apply(env, process_list);
	process_map(env, &(*process_list)->next, apply);
}
