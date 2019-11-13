/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:14:51 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/13 16:40:34 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	is_dot_cor(char *av)
{
	size_t	size;

	size = ft_strlen(av);
	return (size >= 5 && ft_strequ(DOT_COR, &av[size - 4]) == TRUE ? SUCCESS : FAILURE);
}

void			get_champ(t_parser *parser, char **av)
{
	static int	i = 0;
	int32_t		fd;
	int32_t		len;
	char		buff[100000];

	if (av[0][0] != '-' && is_dot_cor(*av) == SUCCESS)
	{
		fd = open(*av, O_RDONLY); 
		if (fd > 0)
		{
        	if (parser->chp_num != 0)
        		parser->env.champs_data[i].chp_num = parser->chp_num;
        	else
        		parser->env.champs_data[i].chp_num = i + 1;
			read(fd, buff, sizeof(int));
        	read(fd, parser->env.champs_data[i].champ_name, PROG_NAME_LENGTH);
        	lseek(fd, 8, SEEK_CUR);
        	read(fd, buff, COMMENT_LENGTH);
        	lseek(fd, 4, SEEK_CUR);
        	len = read(fd, &parser->env.mem[(MEM_SIZE / 4) * i++], CHAMP_MAX_SIZE);
        	ft_memset((void *)&parser->env.mem_owner[(MEM_SIZE / 4) * i], 0, len);
		}
	}
}
