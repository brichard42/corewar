/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2020/01/12 18:25:35 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*create_process(int32_t reg_1, int32_t pc, uint8_t num)
{
	static int	num_proc = 1;
	t_process	*new_process;

	new_process = (t_process *)ft_memalloc(sizeof(t_process));
	if (new_process != NULL)
		*new_process = init_process(reg_1, pc, num);
	return (new_process);
}
