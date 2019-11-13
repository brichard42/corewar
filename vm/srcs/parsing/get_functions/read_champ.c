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
	int32_t			ret;
	uint8_t			chp_index;

	chp_index = 0;
	while (parser->env.champs_data[chp_index].chp_num != 0)
		++chp_index;
	if (parser->chp_num == 0)
		parser->chp_num = chp_index + 1;
	if (chp_index < 4)
	{
		ret = read(fd, parser->env.champs_data[chp_index].champ_name, PROG_NAME_LENGTH);
		if (ret > 0 && ret == PROG_NAME_LENGTH)
		{
			parser->env.champs_data[chp_index].chp_num = parser->chp_num;
			parser->chp_num = 0;
		}
	}
	return (parser->chp_num == 0 ? SUCCESS : FAILURE);
}

int8_t	read_size(t_parser *parser, int32_t fd)
{
	unsigned char	buff[SIZEOF_INT32];
	int32_t			ret;

	ret = read(fd, buff, SIZEOF_INT32);
	if (ret > 0 && ret == SIZEOF_INT32)
		parser->prog_size = (buff[0] << 24 | buff[1] << 16
							| buff[2] << 8 | buff[3]);
	ft_printf("prog_size = [ %d ]\n", parser->prog_size);
	return (SUCCESS);
}

int8_t	read_comment(t_parser *parser, int32_t fd)
{
	char		buff[COMMENT_LENGTH + 1];
	int32_t		ret;

	if ((ret = read(fd, buff, COMMENT_LENGTH)) == COMMENT_LENGTH)
	{
		buff[ret] = '\0';
		ft_printf("comment = [%s ]\n", buff);
		parser->state = S_OPTION;
	}
	return (SUCCESS);
}

int8_t	read_code(t_parser *parser, int32_t fd)
{
	(void)parser;
	fd = 0;
	(void)fd;
	return (SUCCESS);
}
