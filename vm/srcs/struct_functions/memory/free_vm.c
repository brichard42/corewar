/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:46:48 by paullaurent       #+#    #+#             */
/*   Updated: 2019/10/23 13:47:19 by paullaurent      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_vm(t_vm **to_free)
{
	if (to_free != NULL && *to_free != NULL)
	{
		delete_process(*to_free);
		free(*to_free);
		*to_free = NULL;
	}
}