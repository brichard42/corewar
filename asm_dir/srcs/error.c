/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:59:19 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 15:20:03 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "error.h"

/*
** Free label if any and all the linked list.
*/
void	free_asm(t_asm *asmr)
{
	if (asmr->label)
		free(asmr->label);
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
	else if (str) {
		ft_printf(error_msg, str);
	}
	else if (nb)
		ft_printf(error_msg, *nb);
	else
		ft_printf(error_msg);
	if (asmr)
		free_asm(asmr);
	exit(1);
}
