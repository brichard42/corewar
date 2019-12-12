/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/12/12 11:24:14 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_process(t_process *to_delete)
{
	if (to_delete != NULL)
	{
		to_delete->next = NULL;
		to_delete->prev = NULL;
		ft_bzero((void *)to_delete->reg, sizeof(int32_t) * REG_NUMBER);
		to_delete->pc = 0;
		to_delete->cycles_left = 0;
		to_delete->carry = 0;
	}
}
