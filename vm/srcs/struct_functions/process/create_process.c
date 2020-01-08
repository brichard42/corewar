/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2020/01/08 17:33:13 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*create_process(int32_t reg_1, int32_t pc)
{
	static int	num_proc = 1;
	t_process	*new_process;

	new_process = (t_process *)ft_memalloc(sizeof(t_process));
	if (new_process != NULL)
		*new_process = init_process(reg_1, pc);
	new_process->num = num_proc++;
	return (new_process);
}
