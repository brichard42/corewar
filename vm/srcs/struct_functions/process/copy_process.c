/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:37:42 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/27 18:03:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	copy_process(int pc_address, t_process **process)
{
	t_process	*son;
	int			i;

	i = -1;
	if (!(son = (t_process *)ft_memalloc(sizeof(t_process))))
		return (FAILURE);
	son->carry = (*process)->carry;
	son->pc = pc_address;
	son->cycles_left = 0;
	son->last_live = (*process)->last_live;
	while (++i < REG_NUMBER)
		son->reg[i] = (*process)->reg[i];
	son->next = *process;
	*process = son;
	return (SUCCESS);
}
