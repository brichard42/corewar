/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/28 16:52:43 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Check if the instruction name exist and transform it in op_code.
*/
static int	get_op_code(char *str, t_asm *asmr)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(str, asmr->op_tab[i].name) == 0)
			return (asmr->op_tab[i].op_code);
		i++;
	}
	exit_msg(ERROR_OP_NAME, NULL, &(asmr->nb_line), asmr);
	return (-1);
}

/*
** Transform the remaining array cells (only the parameters at this point)
** in one unique string.
*/
static char	*one_str(char **tab, int i, t_asm *asmr)
{
	size_t	size;
	int		j;
	char	*res;

	size = 0;
	j = i;
	while (tab[j])
		size += ft_strlen(tab[j++]);
	if (!(res = ft_strnew(size)))
		exit_msg(ERROR_MALLOC, NULL, NULL, asmr);
	while (tab[i])
		ft_strcat(res, tab[i++]);
	return (res);
}

/*
** Create a new instruction, get and stores: label, line, op_code, parameters.
** Add the new instruction in asmr list.
*/
static void	get_all_op(char **tab, int i, t_asm *asmr)
{
	t_cmd	*new;
	char	**params;

	new = new_elem(asmr);
	if (asmr->label)
	{
		new->label = asmr->label;
		if (ft_strchr(new->label, SEPARATOR_CHAR))
			new->multi_label = TRUE;
		asmr->label = NULL;
		asmr->label_size = 0;
	}
	asmr->list = add_elem(asmr->list, new);
	new->nb_line = asmr->nb_line;
	new->op_code = get_op_code(tab[i++], asmr);
	params = &asmr->garbage.params;
	*params = one_str(tab, i, asmr);
	get_params(*params, new, asmr);
	ft_strdel(params);
}

/*
** Split the string at whitespaces, check if there is a label and get it,
** get the instruction.
*/
void		get_op(char *line, t_asm *asmr)
{
	char	***tab;
	int		i;

	i = 0;
	if (!(asmr->garbage.tab  = ft_splitwhite(line)))
		exit_msg(ERROR_MALLOC, NULL, NULL, asmr);
	tab = &asmr->garbage.tab;
	if (check_label((*tab)[i], asmr))
		get_label((*tab)[i++], asmr);
	if ((*tab)[i] && (*tab)[i][0] != COMMENT_CHAR)
		get_all_op((*tab), i++, asmr);
	ft_freetabsplit(tab);
}
