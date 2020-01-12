/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	write_nb_4(t_asm *asmr, int32_t fd, int32_t nb)
{
	int32_t	nb_endian;
	int8_t	i;

	nb_endian = 0;
	i = 0;
	while (i != sizeof(int32_t))
	{
		nb_endian <<= 8;
		nb_endian |= ((nb >> 8 * i) & 0xFF);
		i++;
	}

	if (write(fd, &nb_endian, 4) != 4)
		exit_msg(ERROR_FILE_WRITE, NULL, NULL, asmr);
}