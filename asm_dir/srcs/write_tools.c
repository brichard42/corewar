/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/29 14:55:04 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Directly write the number as it was on 1 byte.
*/
void		write_nb_1(t_asm *asmr, int32_t fd, int nb)
{
	if (write(fd, &nb, 1) != 1)
		exit_msg(ERROR_FILE_WRITE, NULL, NULL, asmr);
}

/*
** Same as write_nb_4 but only with 2 bytes.
*/
static void	write_nb_2(t_asm *asmr, int32_t fd, int32_t nb)
{
	int16_t	nb_endian;
	int8_t	i;

	nb_endian = 0;
	i = 0;
	while (i != sizeof(int16_t))
	{
		nb_endian <<= 8;
		nb_endian |= ((nb >> 8 * i) & 0xFF);
		i++;
	}
	if (write(fd, &nb_endian, 2) != 2)
		exit_msg(ERROR_FILE_WRITE, NULL, NULL, asmr);
}

/*
** VM is working on big-endian when the computers are on lille-endian,
** so we 'revert' the 4 bytes number then write it.
** To do that, we read byte by byte and put them at the opposit place.
** (First one <--> Last one -- Second one <--> Third one)
*/
void		write_nb_4(t_asm *asmr, int32_t fd, int32_t nb)
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

/*
** Create the one byte parameter by adding the 2 bits of each param type.
** Add many nul-bit as needed to fill the byte.
** Finnaly, write it.
*/
void		write_param_byte(t_asm *asmr, int32_t fd, t_cmd *cmd)
{
	int		i;
	int8_t	val_byte;

	i = 0;
	val_byte = 0;
	while (i < cmd->nb_param)
	{
		val_byte <<= 2;
		val_byte |= (int8_t)cmd->params[i++].type;
	}
	val_byte <<= 2 * (MAX_ARGS_NUMBER - i);
	if (write(fd, &val_byte, 1) != 1)
		exit_msg(ERROR_FILE_WRITE, NULL, NULL, asmr);
}

/*
** Call the right depending on param's size.
*/
void		write_param(t_asm *asmr, int32_t fd, t_param *param, int opcode)
{
	if (param->type == REG_CODE)
		write_nb_1(asmr, fd, param->value);
	else if (param->type == IND_CODE
			|| asmr->op_tab[opcode - 1].is_half_int)
		write_nb_2(asmr, fd, (int16_t)param->value);
	else
		write_nb_4(asmr, fd, (int32_t)param->value);
}
