/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:42:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/27 18:42:58 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
 ** Genere un nouveau processus a l'adresse passée en parametre par
 ** copie du processus appelant. Le nouveau processus garde donc
 ** l'etat de tout les registres et du carry, seul le PC differe ( sauf dans le
 ** cas d'un fork %0 ).
 */

void    fork(t_vm *vm, t_process *process)
{
	if (copy_process(process->pc + (process->op.param[0] % IDX_MOD), &process) == FAILURE)
		return ; //remplacer par un exit propre avec free des valurs interessees
	process->pc = (process->pc + 3) % MEM_SIZE;
}
