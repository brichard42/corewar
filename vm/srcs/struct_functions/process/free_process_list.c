/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_process_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:54:14 by brichard          #+#    #+#             */
/*   Updated: 2019/12/12 15:01:42 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_process_list(t_process **to_free)
{
	if (to_free == NULL || *to_free == NULL)
		return ;
	free_process_list(&(*to_free)->next);
	free_process(to_free);
}
