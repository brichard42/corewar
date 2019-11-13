#include "corewar.h"

static uint8_t	is_dot_cor(char *av)
{
	size_t	size;

	size = ft_strlen(av);
	return (size >= 5 && ft_strequ(DOT_COR, &av[size - 4]) == TRUE ? SUCCESS : FAILURE);
}

void			get_champ(t_parser *parser, char **av)
{
	char		buff[MEM_SIZE + COMMENT_LENGTH + PROG_NAME_LENGTH];
	int32_t		fd;
	int32_t		ret;
	uint8_t		chp_index;

	parser->state = S_ERR;
	if (av[0][0] != '-' && is_dot_cor(*av) == SUCCESS)
	{
		fd = open(*av, O_RDONLY); 
		if (fd > 0)
		{
			if ((ret = read(fd, buff, MAGIC_SIZE)) == (int)MAGIC_SIZE)
			{
				buff[ret] = '\0';
				//CHECK MAGIC NUMBER
				if ((ret = read(fd, buff, PROG_NAME_LENGTH)) == PROG_NAME_LENGTH)
				{
					buff[ret] = '\0';
					chp_index = 0;
					while (parser->env.champs_data[chp_index].chp_num != 0)
						++chp_index;
					if (chp_index < 4)
					{
						parser->env.champs_data[chp_index].chp_num = (parser->chp_num == 0 ? chp_index + 1 : parser->chp_num);
						ft_strcat(parser->env.champs_data[chp_index].champ_name, buff);
						ft_printf("chp_name = [ %s ]\n", parser->env.champs_data[chp_index].champ_name);
						if ((ret = read(fd, buff, sizeof(uint32_t))) == sizeof(uint32_t))
						{
							buff[ret] = '\0';
							ft_printf("prog_size = [ %s ]\n", buff);
							if ((ret = read(fd, buff, COMMENT_LENGTH)) == COMMENT_LENGTH)
							{
								buff[ret] = '\0';
								ft_printf("comment = [%s ]\n", buff);
								parser->state = S_OPTION;
							}
						}
					}
				}
			}
		}
	}
}
