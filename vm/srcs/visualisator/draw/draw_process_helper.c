/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_process_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:13:01 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/08 15:46:03 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*action_name(int32_t op_code)
{
	static char	*ret[17] = {"live", "ld", "st", "add", "sub", "and", "or", "xor"
						,"zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork"
						,"aff"};
	return (ret[op_code - 1]);
}
