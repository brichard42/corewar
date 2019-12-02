/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:30:19 by brichard          #+#    #+#             */
/*   Updated: 2019/12/02 18:58:01 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	charge_champ(t_vm *env, int charge_here, t_champ champ, int value)
{
	ft_memcpy(&env->mem[charge_here], champ.code, champ.size);
	ft_memset((void *)&env->mem_owner[charge_here], value + 1, champ.size);
}

static int8_t charge_process(int pc_address, int champ_num, t_process **process)
{
	t_process	*new;

	if (!(new = create_process(champ_num, pc_address)))
		return (FAILURE);
	new->next = *process;
	*process = new;
	return (SUCCESS);
}

int8_t			load_memory(t_parser *parser)
{
	t_champ	*champ;
	uint8_t	champ_amount;
	uint8_t	i;

	champ = parser->env.champ;
	champ_amount = parser->cur_chp_index;
	i = 0;
	while (i < champ_amount)
	{
		charge_champ(&parser->env, ((MEM_SIZE / champ_amount) * i), champ[i], i);
		++i;
	}
	i = 0;
	while (i < champ_amount)
	{
		if (charge_process(((MEM_SIZE / champ_amount) * i), i + 1,
				&parser->env.process_list) == FAILURE)
			return (FAILURE);
		++i;
	}
	return (SUCCESS);
}