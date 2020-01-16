/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 14:58:38 by plaurent          #+#    #+#             */
/*   Updated: 2020/01/16 04:17:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	usage(void)
{
	ft_putendl(USG_MSG1);
	ft_putendl(USG_MSG2);
	ft_putendl(USG_MSG3);
	ft_putendl(USG_MSG4);
	return (EXIT_FAILURE);
}

/*
**static void	print_champ(t_champ champ[4])
**{
**	uint8_t	i;
**
**	i = 0;
**	while (i < 4)
**	{
**		ft_printf("chp_name = [%15s] |\tchp_num = {%8d} |\tchp_size = {%6d} \
**		|\tchp_comment = [%40s]\n", champ[i].name, champ[i].num, champ[i].size,
**		champ[i].comment);
**		++i;
**	}
**}
** print_champ(parser.env.champ); TO TEJ
*/

int			main(int ac, char **av)
{
	t_parser	parser;

	if (ac < 2)
		return (usage());
	ft_bzero((void *)&parser, sizeof(t_parser));
	if (vm_parser(&parser, ++av) == FAILURE)
		return (usage());
	if (load_memory(&parser) == FAILURE)
		return (usage());
	player_caller(parser.env.champ_amount, parser.env.champ);
	if (parser.visu == ON)
	{
		if (main_visu(&parser.env) == FAILURE)
			return (1);
	}
	else
		cycle(&parser.env);
	delete_vm(&parser.env);
	return (EXIT_SUCCESS);
}
