/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chpnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:34:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/19 16:34:26 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
