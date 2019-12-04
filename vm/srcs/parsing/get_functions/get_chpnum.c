/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chpnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:34:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/12/04 15:41:06 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			get_chpnum(t_parser *parser, char **av)
{
	if (ft_strcheck(*av, ft_isdigit) == TRUE)
	{
		parser->chp_num = ft_atol(*av);
		if (parser->chp_num > 0 && parser->chp_num <= MAX_PLAYERS
				&& chp_num_is_attributed(parser) == FALSE)
			parser->state = S_CHAMP;
		else
			parsing_error(parser, ERR_WRONG_PLAYER_NUM);
	}
	else
		parsing_error(parser, ERR_INVALID_CHAMP_NUM);
}
