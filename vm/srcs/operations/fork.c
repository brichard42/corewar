/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:54 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/12 22:43:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Genere un nouveau processus a l'adresse passée en parametre par
** copie du processus appelant. Le nouveau processus garde donc
** l'etat de tout les registres et du carry, seul le PC differe ( sauf dans le
** cas d'un fork %0 ).
*/

/*
** REMPLACER LE RETURN DEGEU PAR UN EXIT ET UN FREE DES VALEURS A FREE
*/

void	op_fork(t_vm *vm, t_process *process)
{
	if (copy_process(vm, modulo(process->pc + (process->op.param[0] % IDX_MOD)
			, MEM_SIZE), process) == FAILURE)
		return ;
	if (vm->verbose)
		show_op(process);
}
