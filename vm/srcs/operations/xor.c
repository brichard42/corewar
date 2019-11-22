#include "corewar.h"

/*
 ** Effectue un XOR logique entre les deux premiers paramametres et
 ** stock le resultat dans le troisieme paramametre. Si la valeur resultante
 ** est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.
 */

void    xor(t_vm *vm, t_process *process)
{
	int		param1;
	int		param2;

	if ((process->op.type_param[0] = T_REG && (process->op.param[0] < 1
		|| process->op.param[0] > REG_NUMBER)) || (process->op.type_param[1] = T_REG
		&& (process->op.param[1] < 1 || process->op.param[1] > REG_NUMBER))
		|| (process->op.param[2] < 1 || process->op.param[2] > REG_NUMBER))
		return ;
	if (process->op.type_param[0] == REG_CODE)
		param1 = process->reg[process->op.param[0]];
	else if (process->op.type_param[0] == IND_CODE)
		param1 = get_ind(); // recup un T_IND
	else
		param1 = process->op.param[0];
	if (process->op.type_param[1] == REG_CODE)
		param1 = process->reg[process->op.param[1]];
	else if (process->op.type_param[1] == IND_CODE)
		param1 = get_ind(); // recup un T_IND
	else
		param1 = process->op.param[1];
	process->reg[process->op.param[2]] = param1 ^ param2;
	process->carry = ((param1 ^ param2) ? 1 : 0);
	if (vm->verbose)
		show_op(process);
}
