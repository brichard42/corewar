/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:34:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/19 16:34:52 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		get_opt(t_parser *parser, char **av)
{
	if (av[0][0] == '-')
	{
		if (ft_strequ(*av, O_DUMP) == TRUE)
			parser->state = S_DUMP;
		else if (ft_strequ(*av, O_CHP_NUM) == TRUE)
			parser->state = S_CHP_NUM;
		else if (ft_strequ(*av, O_VISU) == TRUE)
			parser->env.visu = ON;
		else if (ft_strequ(*av, O_VERBOSE) == TRUE)
			parser->env.verbose = ON;
		else
			parser->state = S_ERR;
	}
	else
		get_champ(parser, av);
}
