/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:58:38 by plaurent          #+#    #+#             */
/*   Updated: 2019/12/12 17:18:09 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	usage(void)
{
	ft_putendl(USG_MSG);
	return (EXIT_FAILURE);
}

static void	print_champ(t_champ champ[4])
{
	uint8_t	i;

	i = 0;
	while (i < 4)
	{
		ft_printf("chp_name = [%15s] |\tchp_num = {%8d} |\tchp_size = {%6d} |\tchp_comment = [%40s]\n", champ[i].name, champ[i].num, champ[i].size, champ[i].comment);
		++i;
	}
}
#include <stdio.h>
int			main(int ac, char **av)
{
	t_parser		parser;
	t_window		*win;

	if (ac < 2)
		return (usage());
	ft_bzero((void *)&parser, sizeof(t_parser));
	if (vm_parser(&parser, ++av) == FAILURE)
		return (usage());
	print_champ(parser.env.champ);// TO TEJ
	(void)print_champ;
	if (load_memory(&parser) == FAILURE)
		return (usage());
	if (parser.env.visu == ON)
	{
		 win = open_window("Test");
		 if (win == NULL)
		 	return (EXIT_FAILURE);
		 if (drawer(win, &parser.env) == FAILURE)
		 	return (EXIT_FAILURE);
	}
	else
		cycle(&parser.env);
	free_process_list(&parser.env.process_list);//NEED FAIRE CA PROPREMENT--Idee: Free toute la struct parser et son contenu step by step et ce pour CHAQUE RETURN DU MAIN.
	return (EXIT_SUCCESS);
}
