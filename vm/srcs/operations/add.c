#include "corewar.h"

/*
 ** Ajoute le second parametre au premier parametre, et stock le
 ** resultat dans le troisieme parametre. Si la valeur resultante est egale a
 ** zero, alors le carry passe a l'etat un, sinon a l'etat zero.
 */

void	add(t_vm *vm, t_process *process)
{
	int		add;

	if (process->op.param[0] >= 1 && process->op.param[0] <= REG_NUMBER
		&& process->op.param[1] >= 1 && process->op.param[1] <= REG_NUMBER
		&& process->op.param[2] >= 1 && process->op.param[2] <= REG_NUMBER)
	{
		add = process->reg[process->op.param[0] - 1] + process->reg[process->op.param[1] - 1];
		process->reg[process->op.param[2] - 1] = add;
		process->carry = ((add == 0) ? 1 : 0);
		if (vm->verbose)
			show_op(process);
	}
}
