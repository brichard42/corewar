/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 17:08:31 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Get the type depending on the first character.
*/
int		get_type(char *str)
{
	if (str[0] == 'r')
		return (REG_CODE);
	else if (str[0] == DIRECT_CHAR)
		return (DIR_CODE);
	else
		return (IND_CODE);
}

/*
** Check if the label match.
*/
t_bool	compare_label(t_cmd *cmd, char *label)
{
	size_t	size;
	size_t	size_label;
	char	*temp;

	size_label = ft_strlen(label);
	if (!cmd->multi_label)
	{
		if (size_label == ft_strlen(cmd->label) &&
			!ft_strncmp(label, cmd->label, size_label))
			return (TRUE);
		return (FALSE);
	}
	temp = cmd->label;
	while (*temp)
	{
		size = 0;
		while (temp[size] && temp[size] != SEPARATOR_CHAR)
			size++;
		if (size_label == size && !ft_strncmp(label, temp, size))
			return (TRUE);
		temp += size;
		if (*temp == SEPARATOR_CHAR)
			temp++;
	}
	return (FALSE);
}
