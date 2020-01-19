/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/12 16:43:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Check all characters of the label's string.
*/
static t_bool	is_label_char(char c)
{
	int i;

	i = 0;
	while (LABEL_CHARS[i] && LABEL_CHARS[i] != c)
		i++;
	if (LABEL_CHARS[i])
		return (TRUE);
	return (FALSE);
}

/*
** Check if it's a label (LABEL_CHAR present).
** Check it contains only valid characters.
** Stores its size.
** Check if it doesn't appear earlier.
*/
t_bool			check_label(char *str, t_asm *asmr)
{
	size_t	i;
	size_t	size;
	t_cmd	*list;

	size = ft_strlen(str) - 1;
	if (str[size] != LABEL_CHAR)
		return (FALSE);
	i = 0;
	while (i < size && is_label_char(str[i]))
		i++;
	if (i != size)
		exit_msg(ERROR_LABEL_CHAR, NULL, &(asmr->nb_line), asmr);
	asmr->label_size = size;
	list = asmr->list;
	while (list)
	{
		if (list->label && size == ft_strlen(list->label)
			&& !ft_strncmp(str, list->label, size))
			exit_msg(ERROR_LABEL_DUPLICATE, list->label, &(asmr->nb_line), asmr);
		list = list->next;
	}
	return (TRUE);
}

/*
** Stores the label using the size computed earlier.
*/
void			get_label(char *label, t_asm *asmr)
{
	if (!(asmr->label = ft_strnew(asmr->label_size)))
		exit_msg(ERROR_MALLOC, NULL, NULL, NULL);
	ft_strncpy(asmr->label, label, asmr->label_size);
}