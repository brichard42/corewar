/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:27:05 by brichard          #+#    #+#             */
/*   Updated: 2019/12/03 11:21:21 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		sort_champ_tab(t_champ *champ, int chp_amount)
{
	t_champ	tmp;
	uint8_t	i;

	i = 0;
	while (i < chp_amount)
	{
		if (champ[i].num > champ[i + 1].num)
		{
			tmp = champ[i];
			champ[i] = champ[i + 1];
			champ[i + 1] = tmp;
			i = 0;
		}
		++i;
	}
}

static void		check_chp_num_validity(t_parser *parser)
{
	uint8_t	i;
	uint8_t	highest_num;

	i = 0;
	highest_num = 0;
	while (i < 4)
	{
		if (highest_num < parser->env.champ[i].num)
			highest_num = parser->env.champ[i].num;
		++i;
	}
	if (highest_num > parser->cur_chp_index) 
		parser->state = S_ERR;
}

int8_t		vm_parser(t_parser *parser, char **av)
{
	t_parser			d_parser;
	static t_get_func	get_func[GET_F_NUM] = {get_opt, get_dump, get_chpnum
																, get_champ};

	parser->env = init_vm();
	d_parser = *parser;
	while (d_parser.state != S_ERR && *av != NULL)
	{
		get_func[d_parser.state](&d_parser, av);
		++av;
	}
	*parser = d_parser;
	check_chp_num_validity(parser);
	sort_champ_tab(parser->env.champ, parser->cur_chp_index - 1);
	return (parser->state != S_ERR ? SUCCESS : FAILURE);
}
