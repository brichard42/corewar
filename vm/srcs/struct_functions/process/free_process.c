/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/12/12 12:28:53 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_process(t_process **to_free)
{
	t_process	*begin;

	if (to_free != NULL && *to_free != NULL)
	{
		if ((*to_free)->prev != NULL)
			begin = (*to_free)->prev;
		else
			begin = (*to_free)->next;
		if ((*to_free)->next != NULL)
			(*to_free)->next->prev = (*to_free)->prev;
		if ((*to_free)->prev != NULL)
			(*to_free)->prev->next = (*to_free)->next;
		delete_process(*to_free);
		free(*to_free);
		*to_free = begin;
	}
}
