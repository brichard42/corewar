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
		//is_dot_cor
		//check_header
		//read_header
		//check_champ_length
		//memorize_champ
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

void		get_dump(t_parser *parser, char **av)
{
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		parser->env.cycles_to_dump = ft_atol(*av);
		if (parser->env.cycles_to_dump >= 0
				&& parser->env.cycles_to_dump <= INT_MAX)
			parser->state = S_OPTION;
	}
	else
		parser->state = S_ERR;
}

void		get_chpnum(t_parser *parser, char **av)
{
	parser->state = S_ERR;
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		parser->chp_num = ft_atol(*av);
		if (parser->chp_num >= 0 && parser->chp_num <= INT_MAX)
			parser->state = S_CHAMP;
	}
}

int8_t		vm_arg_parser(t_parser *parser, char **av)
{
	t_parser			d_parser;
	static t_get_func	get_func[4] = {get_opt, get_dump, get_chpnum, get_champ};

	d_parser = *parser;
	parser->env = init_vm();
	while (d_parser.state != S_ERR && *av != NULL)
	{
		get_func[d_parser.state](&d_parser, av);
		++av;
	}
	return (d_parser.state == S_OPTION ? SUCCESS : FAILURE);
}
