/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

static char	*get_param(char *str, int *i, t_asm *asmr)
{
	size_t 	size;
	char 	*param;

	size = 0;
	while (*str && *str != SEPARATOR_CHAR && *str != COMMENT_CHAR)
	{
		size++;
		str++;
		(*i)++;
	}
	if (!(param = ft_strnew(size)))
		exit_msg(ERROR_MALLOC, NULL, NULL, asmr);
	ft_strncpy(param, str - size, size);
	return (param);
}

void		get_params(char *params, t_cmd *new, t_asm *asmr)
{
	int i_params;
	int i;

	i_params = 0;
	i = 0;
	while (params[i])
	{
		if (params[i] == COMMENT_CHAR)
			return ;
		if (i_params == MAX_ARGS_NUMBER)
			exit_msg(ERROR_ARGS_NUMBER, NULL, &(asmr->nb_line), asmr);
		new->params[i_params++].str = get_param(&params[i], &i, asmr);
		new->nb_param++;
		if (params[i] == SEPARATOR_CHAR) {
			i++;
			if (!params[i] || params[i] == COMMENT_CHAR)
				exit_msg(ERROR_SYNTAX, NULL, &(asmr->nb_line), asmr);
		}
	}
}