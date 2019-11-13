/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:58:38 by plaurent          #+#    #+#             */
/*   Updated: 2019/11/13 14:46:58 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	usage(void)
{
	ft_putendl("Usage: ./corewar [-dump n_cycles] [(-n num) champ1.cor] ...");
	ft_putendl("   -v: Visualisator");
	return (1);
}

int		main(int ac, char **av)
{

	t_parser		parser;
	t_window		*win;

	if (ac < 2)
		return (usage());
	ft_bzero((void *)&parser, sizeof(t_parser));
	if (vm_arg_parser(&parser, ++av) == FAILURE)
		return (usage());
	if (parser.env.visu == ON)
	{
		if (!(win = open_window("Test")))
			return (0);
		if (drawer(win, &parser.env) == FAILURE)
			return (1);
	}
	return (0);
}
