/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_arg_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:27:05 by brichard          #+#    #+#             */
/*   Updated: 2019/11/07 16:11:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		get_champ(t_parser *parser, char **av)
{
	if (av[0][0] != '-')
	{
		ft_printf("Got Champ's Binary\n");
		parser->state = S_OPTION;
		(void)av;
	}
	else
		parser->state = S_ERR;
}

void		get_opt(t_parser *parser, char **av)
{
	if (av[0][0] == '-')
	{
		if (ft_strequ(*av, O_DUMP) == TRUE)
			parser->state = S_DUMP;
		else if (ft_strequ(*av, O_CHP_NUM) == TRUE)
			parser->state = S_CHP_NUM;
		else
			parser->state = S_ERR;
	}
	else
		get_champ(parser, av);
}

void		get_dump(t_parser *parser, char **av)
{
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		ft_printf("Got Num of Cycles before DUMP\n");
		parser->state = S_OPTION;
	}
	else
		parser->state = S_ERR;
	(void)av;
}

void		get_chpnum(t_parser *parser, char **av)
{
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		ft_printf("Got Champ's Num\n");
		parser->state = S_CHAMP;
	}
	else
		parser->state = S_ERR;
	(void)av;
}

int8_t		vm_arg_parser(t_parser *parser, char **av)
{
	t_parser			d_parser;
	static t_get_func	get_func[4] = {get_opt, get_dump, get_chpnum, get_champ};

	d_parser = *parser;
	while (d_parser.state != S_ERR && *av != NULL)
	{
		ft_printf("av = [%s]\n", *av);
		get_func[d_parser.state](&d_parser, av);
		++av;
	}
	return (d_parser.state == S_OPTION ? SUCCESS : FAILURE);
}
