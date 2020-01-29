/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/29 14:17:10 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Check if the value match the type.
*/
static void		check_value(t_cmd *cmd, int type, char *str, t_asm *asmr)
{
	if (type == REG_CODE || type == DIR_CODE)
		str++;
	if (*(str + 1) != LABEL_CHAR && (*str == '+' || *str == '-'))
		str++;
	if (*str != LABEL_CHAR && !ft_str_is_numeric(str))
		exit_msg(ERROR_SYNTAX, NULL, &(cmd->nb_line), asmr);
}

/*
** If its a label stores it for further computing, else simple atoi.
*/
static int		get_value(t_param *param, int type, char *str)
{
	if (type == REG_CODE || type == DIR_CODE)
		str++;
	if (*str == LABEL_CHAR)
	{
		param->temp = str + 1;
		return (0);
	}
	return (ft_atoi(str));
}

/*
** We have all the data to compute the size now.
** Start at 1 for the op code.
** If instruction got a param byte, add 1.
** Add the size of each param depending of their type.
*/
static size_t	compute_size(t_cmd *cmd, t_asm *asmr)
{
	size_t	res;
	int		i;

	res = 1;
	if (asmr->op_tab[cmd->op_code - 1].have_param_byte)
		res++;
	i = 0;
	while (i < cmd->nb_param)
	{
		if (cmd->params[i].type == REG_CODE)
			res += SIZE_REG;
		else if (cmd->params[i].type == IND_CODE
				|| asmr->op_tab[cmd->op_code - 1].is_half_int)
			res += IND_SIZE;
		else
			res += DIR_SIZE;
		i++;
	}
	return (res);
}

/*
** Check the number of parameters.
** For each parameter:
** 	Get the type from the string.
**	Check and get the value from the string.
** 	Compute the size of hex code.
*/
static void		check_param(t_cmd *cmd, t_asm *asmr)
{
	int i;

	if (cmd->op_code < 1 || cmd->op_code > 16)
		return ;
	if (cmd->nb_param != asmr->op_tab[cmd->op_code - 1].nb_param)
		exit_msg(ERROR_ARGS_NUMBER, NULL, &(cmd->nb_line), asmr);
	i = 0;
	while (i < cmd->nb_param)
	{
		cmd->params[i].type = get_type(cmd->params[i].str);
		check_value(cmd, cmd->params[i].type, cmd->params[i].str, asmr);
		cmd->params[i].value = get_value(&(cmd->params[i]),
			cmd->params[i].type, cmd->params[i].str);
		i++;
	}
	cmd->size = compute_size(cmd, asmr);
}

/*
** Check params instruction by instruction.
*/
void			check_params(t_asm *asmr)
{
	t_cmd	*list;

	list = asmr->list;
	while (list)
	{
		check_param(list, asmr);
		list = list->next;
	}
}
