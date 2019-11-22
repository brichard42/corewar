#include "corewar.h"

/*
 ** Transfert direct Registre > RAM / Registre. Charge le contenu du
 ** registre passé en premier parametre dans le second parametre. Si la
 ** valeur du premier parametre est egale a zero, alors le carry passe a
 ** l'etat un, sinon a l'etat zero.
 */

void    st(t_vm *vm, t_process *process)
{
	if (process->op.param[0] > 1 && process->op.param[0] < REG_NUMBER)
	{
		if (process->op.type_param[1] == REG_CODE)
		{
			if (process->op.param[1] > 1 && process->op.param[1] < REG_NUMBER)
				process->reg[process->op.param[1]] = process->reg[process->op.param[0]];
		}
		else
			;// stockage dans le deuxieme param qui est un T_IND
		process->carry = ((process->reg[process->op.param[0]] == 0) ? 1 : 0); // gestion du carry
		if (vm->verbose)
			show_op(process);
	}
}
