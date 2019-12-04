/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:27:22 by brichard          #+#    #+#             */
/*   Updated: 2019/12/04 15:48:00 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static uint8_t	is_dot_cor(char *av)
{
	size_t	size;

	size = ft_strlen(av);
	return (size >= 5 && ft_strequ(DOT_COR, &av[size - 4]) == TRUE
			? TRUE : FALSE);
}

void			get_champ(t_parser *parser, char **av)
{
	static t_read_func	read_func_tab[RD_F_NUM] = {read_magic, read_name,
										read_size, read_comment, read_code};
	int32_t		fd;
	int8_t		i;

	i = 0;
	parser->state = S_OPTION;
	if (av[0][0] != '-' && is_dot_cor(*av) == TRUE)
	{
		fd = open(*av, O_RDONLY); 
		if (fd > 0)
			while (i < RD_F_NUM && parser->state != S_ERR)
				read_func_tab[i++](parser, fd);
		++parser->env.champ_amount;
	}
	else
		parsing_error(parser, ERR_FILE_NOT_COR);
}
