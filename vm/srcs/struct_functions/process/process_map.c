/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:31:04 by brichard          #+#    #+#             */
/*   Updated: 2020/01/08 17:33:41 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	process_map(t_vm *env, t_process **process_list,
		t_proc_apply apply)
{
	if (process_list == NULL || *process_list == NULL)
		return ;
	if (apply != NULL)
		apply(env, process_list);
	process_map(env, &(*process_list)->next, apply);
}
