/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:34:37 by tlandema          #+#    #+#             */
/*   Updated: 2019/12/04 15:27:17 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		get_dump(t_parser *parser, char **av)
{
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		parser->env.cycles_to_dump = ft_atol(*av);
		if (parser->env.cycles_to_dump >= 0
				&& parser->env.cycles_to_dump <= INT_MAX)
			parser->state = S_OPTION;
		else
			parsing_error(parser, ERR_INVALID_DUMP_NUM);
	}
	else
		parsing_error(parser, ERR_INVALID_DUMP_NUM);
}
