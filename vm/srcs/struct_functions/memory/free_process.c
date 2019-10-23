/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:04:19 by brichard          #+#    #+#             */
/*   Updated: 2019/10/23 12:10:13 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_process(t_process **to_free)
{
	if (to_free != NULL && *to_free != NULL)
	{
		delete_process(*to_free);
		free(*to_free);
		*to_free = NULL;
	}

}
