/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:02:25 by brichard          #+#    #+#             */
/*   Updated: 2019/11/29 12:25:27 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int8_t	read_magic(t_parser *parser, int32_t fd)
{
	unsigned char		buff[MAGIC_SIZE];
	int32_t				ret;
	int32_t				nb;

	(void)parser;
	nb = 0;
	ret = read(fd, buff, MAGIC_SIZE);
	if (ret > 0 && ret == (int32_t)MAGIC_SIZE)
		nb = (buff[0] << 24 | buff[1] << 16 | buff[2] << 8 | buff[3]);
	return (COREWAR_EXEC_MAGIC == nb ? SUCCESS : FAILURE);
}

int8_t	read_name(t_parser *parser, int32_t fd)
{
	int32_t		ret;
	uint8_t		i;

	if (parser->chp_num == 0)
		attribute_next_chp_num(parser);
	i = parser->cur_chp_index;
	if (i < 4)
	{
		ret = read(fd, parser->env.champ[i].name, PROG_NAME_LENGTH);
		if (ret > 0 && ret == PROG_NAME_LENGTH)
		{
			parser->env.champ[i].num = parser->chp_num;
			parser->chp_num = 0;
		}
	}
	return (parser->chp_num == 0 ? SUCCESS : FAILURE);
}

int8_t	read_size(t_parser *parser, int32_t fd)
{
	unsigned char	buff[SIZEOF_INT32];
	int32_t			ret;

	lseek(fd, 4, SEEK_CUR);
	ret = read(fd, buff, SIZEOF_INT32);
	if (ret > 0 && ret == SIZEOF_INT32)
		parser->env.champ[parser->cur_chp_index].size = (buff[0] << 24
							| buff[1] << 16
							| buff[2] << 8 | buff[3]);
	return (SUCCESS);
}

int8_t	read_comment(t_parser *parser, int32_t fd)
{
	int32_t		ret;
	uint8_t		i;

	i = parser->cur_chp_index;
	ret = read(fd, parser->env.champ[i].comment, COMMENT_LENGTH);
		parser->env.champ[i].comment[ret] = '\0';
	lseek(fd, 4, SEEK_CUR);
	return (ret == COMMENT_LENGTH ? SUCCESS : FAILURE);
}

int8_t	read_code(t_parser *parser, int32_t fd)
{
	int32_t			ret;
	uint8_t			i;
	uint8_t			error;
	char			buf;

	error = 0;
	i = parser->cur_chp_index;
	ret = read(fd, parser->env.champ[i].code, parser->env.champ[i].size);
	if (ret < 0)
		error = 1;
	else if (ret > CHAMP_MAX_SIZE)
		error = 2;
	else if (ret != (int32_t)parser->env.champ[i].size)
		error = 3;//EN PREPA POUR LA _DEBUG, CEST DEGUEU CEST NORMAL
	if (read(fd, &buf, 1) > 0)
		error = 4;
	++parser->cur_chp_index;
	return (error == 0 ? SUCCESS : FAILURE);
}
