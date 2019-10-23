/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/10/23 17:35:34 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_process	*create_process(int32_t reg_1, int32_t pc)
{
	t_process	*new_process;

	new_process = (t_process *)ft_memalloc(sizeof(t_process));
	if (new_process != NULL)
		*new_process = init_process(reg_1, pc);
	return (new_process);
}
