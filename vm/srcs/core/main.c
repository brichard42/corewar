/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:35:29 by brichard          #+#    #+#             */
/*   Updated: 2019/11/07 16:13:38 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	usage(void)
{
	ft_putendl("./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
	return (EXIT_FAILURE);
}

int			main(int ac, char **av)
{
	t_parser	parser;

	if (ac < 2)
		return (usage());
	ft_bzero((void *)&parser, sizeof(t_parser));
	if (vm_arg_parser(&parser, ++av) == FAILURE)
		return (usage());
	return (EXIT_SUCCESS);
}
