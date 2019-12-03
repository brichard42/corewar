/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:46:53 by brichard          #+#    #+#             */
/*   Updated: 2019/12/03 15:46:50 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parsing_error(t_parser *parser, int32_t error_code)
{
	static char	err_str[10][20] = {"file missing", "file not .cor", "3", "4", "5", "6", "7", "8", "9", "10"};
	ft_putendl(err_str[error_code]);
	parser->state = S_ERR;
}
