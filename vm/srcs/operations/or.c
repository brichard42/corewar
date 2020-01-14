/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:02:58 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/14 12:44:57 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Effectue un OR logique entre les deux premiers paramametres et
** stock le resultat dans le troisieme paramametre. Si la valeur resultante
** est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.
*/

void	or(t_vm *vm, t_process *process)
{
	int	param1;
	int	param2;

	if ((process->op.type_param[0] = T_REG && (process->op.param[0] < 1
		|| process->op.param[0] > REG_NUMBER)) || (process->op.type_param[1] =
		T_REG && (process->op.param[1] < 1
		|| process->op.param[1] > REG_NUMBER)) || (process->op.param[2] < 1
		|| process->op.param[2] > REG_NUMBER))
		return ;
	if (process->op.type_param[0] == REG_CODE)
		param1 = process->reg[process->op.param[0] - 1];
	else if (process->op.type_param[0] == IND_CODE)
		param1 = get_indirecte(vm, &process->op, 0);
	else
		param1 = process->op.param[0];
	if (process->op.type_param[1] == REG_CODE)
		param2 = process->reg[process->op.param[1] - 1];
	else if (process->op.type_param[1] == IND_CODE)
		param2 = get_indirecte(vm, &process->op, 1);
	else
		param2 = process->op.param[1];
	process->reg[process->op.param[2] - 1] = param1 | param2;
	process->carry = ((param1 | param2) == 0 ? 1 : 0);
	if (vm->verbose)
		show_op(process);
}
