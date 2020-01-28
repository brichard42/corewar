/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:59:19 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/28 16:51:52 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm_error.h"
#include <stdlib.h>

/*
** Free label if any and all the linked list.
*/
void	free_asm(t_asm *asmr)
{
	ft_strdel(&asmr->label);
	ft_strdel(&asmr->line);
	ft_strdel(&asmr->garbage.params);
	ft_freetabsplit(&asmr->garbage.tab);
	clear_list(asmr->list);
}

/*
** Display error message and exit cleanly.
** Several configurations of parameter depending on the error message.
**	(error_msg & asmr are mendatory)
*/
void	exit_msg(char *error_msg, char *str, size_t *nb, t_asm *asmr)
{
	if (str && nb)
		ft_printf(error_msg, str, *nb);
	else if (str)
		ft_printf(error_msg, str);
	else if (nb)
		ft_printf(error_msg, *nb);
	else
		ft_printf(error_msg);
	if (asmr)
		free_asm(asmr);
	ft_gnl(-42, NULL);
	exit(EXIT_FAILURE);
}
