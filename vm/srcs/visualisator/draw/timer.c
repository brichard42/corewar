/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:57:18 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/08 16:19:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	time_dealer(t_draw *infos, uint8_t plus_minus)
{
	if (plus_minus)
	{
		if (infos->cycles_per_sec == 128)
			infos->time = 15624;
		if (infos->cycles_per_sec != 1)
		{
			infos->time *= 2;
			infos->cycles_per_sec /= 2;
		}
	}
	else
	{
		if (infos->cycles_per_sec == 64)
		{
			infos->time = 1;
			infos->cycles_per_sec = 128;
		}
		else if (infos->cycles_per_sec != 128)
		{
			infos->time /= 2;
			infos->cycles_per_sec *= 2;
		}
	}
}
