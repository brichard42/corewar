/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/11/07 11:19:15 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_process(t_process **to_free)
{
	if (to_free != NULL && *to_free != NULL)
	{
		free_process(&(*to_free)->next);
		delete_process(*to_free);
		free(*to_free);
		*to_free = NULL;
	}
}
