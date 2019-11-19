/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:00:51 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/19 16:25:27 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	fill_arena(t_vm *env, uint8_t champ_amount)
{
	int	i;

	i = -1;
	
	while (++i < champ_amount)
	{
		ft_memcpy(&env->mem[(MEM_SIZE / champ_amount) * i], env->champ[i].code, env->champ[i].size);
		ft_memset((void *)&env->mem_owner[(MEM_SIZE / champ_amount) * i], i + 1, env->champ[i].size);
	}
	return (SUCCESS);
}
