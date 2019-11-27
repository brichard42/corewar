/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:00:51 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/27 16:33:45 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	charge_champ(t_vm *env, int charge_here, t_champ champ, int value)
{
	ft_memcpy(&env->mem[charge_here], champ.code, champ.size);
	ft_memset((void *)&env->mem_owner[charge_here], value + 1, champ.size);
}

static int8_t charge_process(t_vm *env, int pc_address, t_champ champ, t_process **process)
{
	t_process	*new;

	if (!(new = create_process(champ.num, pc_address)))
		return (FAILURE);
	new->next = *process;
	*process = new;
	return (SUCCESS);
}

int8_t		fill_arena(t_vm *env, uint8_t champ_amount)
{
	int	i;

	i = -1;
	while (++i < champ_amount)
		charge_champ(env, ((MEM_SIZE / champ_amount) * i), env->champ[i], i);
	i = -1;
	while (++i < champ_amount)
		if (charge_process(env, ((MEM_SIZE / champ_amount) * i),
			env->champ[i], &env->process_list) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}
