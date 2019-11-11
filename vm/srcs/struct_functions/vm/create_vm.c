/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:20:49 by paullaurent       #+#    #+#             */
/*   Updated: 2019/11/11 19:10:28 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_vm	*create_vm(size_t mem_size)
{
	t_vm	*new_vm;

	new_vm = (t_vm *)ft_memalloc(sizeof(t_vm));
	if (new_vm != NULL)
		*new_vm = init_vm(mem_size);
	return (new_vm);
}
