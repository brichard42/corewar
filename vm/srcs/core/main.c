/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:58:38 by plaurent          #+#    #+#             */
/*   Updated: 2019/11/06 06:57:38 by tlandema         ###   ########.fr       */
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

	t_vm		env;
	t_window	*win;

	ft_bzero((void *)&env, sizeof(t_vm));
	if (ac < 2)
		return (usage());
	option_parser(ac, av, &env);
	if (env.visu_on == TRUE)
	{
		if (!(win = open_window("Test")))
			return (0);
		drawer(win);
	}
	return (0);
}
