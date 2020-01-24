/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Check if the label exist and doesn't reference its own instruction.
*/
static t_cmd	*label_exist(t_param *param, t_cmd *cmd, t_asm *asmr)
{
	t_cmd	*list;
	size_t	size;

	list = asmr->list;
	size = ft_strlen(param->temp);
	while (list)
	{
		if (list->label && size == ft_strlen(list->label) &&
			!ft_strncmp(param->temp, list->label, size))
		{
			if (list == cmd)
				exit_msg(ERROR_LABEL_CMD, list->label, &(cmd->nb_line), asmr);
			return (list);
		}
		list = list->next;
	}
	exit_msg(ERROR_LABEL_UNKNOW, param->temp, &(cmd->nb_line), asmr);
	return (NULL);
}

/*
** If the label if after, start counting distance and stop when found it.
*/
static int		get_label_value_for(t_cmd *cmd, t_cmd *cmd_label)
{
	int		res_forward;
	t_cmd	*forward;

	forward = cmd;
	res_forward = forward->size;
	forward = forward->next;
	while (forward)
	{
		if (forward == cmd_label)
			return (res_forward);
		res_forward += forward->size;
		forward = forward->next;
	}
	return (0);
}

/*
** If the label is before, start at beginning and start counting distance
** when found it and stop when found cmd.
*/
static int		get_label_value(t_cmd *cmd, t_cmd *cmd_label, t_asm *asmr)
{
	int		res_backward;
	t_bool	start;
	t_cmd	*backward;

	if ((res_backward = get_label_value_for(cmd, cmd_label)) != 0)
		return (res_backward);
	backward = asmr->list;
	start = FALSE;
	while (backward)
	{
		if (backward == cmd && start)
			return (res_backward);
		if (backward == cmd_label)
			start = TRUE;
		if (backward && start)
			res_backward -= (int)backward->size;
		backward = backward->next;
	}
	return (0);
}

/*
** Check if the type is REG and its value is between 1 and REG_NUMBER.
** If there if a label, check if it exist then get its value.
** If returned value is neativ, replace it.
** 	(0xFFFF: max of 2 bytes)
*/
static void		valid_param(t_param *param, t_cmd *cmd, t_asm *asmr)
{
	t_cmd *cmd_label;

	if (param->type == REG_CODE &&
		(param->temp || param->value < 1 || param->value > REG_NUMBER))
		exit_msg(ERROR_PARAM_VAL, NULL, &(cmd->nb_line), asmr);
	else if (param->temp)
	{
		cmd_label = label_exist(param, cmd, asmr);
		param->value = get_label_value(cmd, cmd_label, asmr);
		if (param->value < 0)
			param->value = 0xFFFF + 1 + param->value;
	}
}

/*
** Check each params value and get the value of each label referenced in params.
*/
void			check_labels(t_asm *asmr)
{
	t_cmd	*list;
	int		i;

	list = asmr->list;
	while (list)
	{
		i = 0;
		while (i < list->nb_param)
		{
			valid_param(&(list->params[i]), list, asmr);
			i++;
		}
		list = list->next;
	}
}
