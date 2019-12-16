/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/12/16 16:35:35 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	num_proc = 1;

t_process	*create_process(int32_t reg_1, int32_t pc)
{
	t_process	*new_process;

	new_process = (t_process *)ft_memalloc(sizeof(t_process));
	if (new_process != NULL)
		*new_process = init_process(reg_1, pc);
	new_process->num = num_proc++;
	return (new_process);
}
