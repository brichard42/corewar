#include "corewar.h"

/*
 ** Transfert direct RAM > Registre. Charge le premier parametre dans le
 ** registre passé en second parametre. Si la valeur du premier
 ** parametre est egale a zero, alors le carry passe a l'etat un, sinon a
 ** l'etat zero.
 */

void	ld_T_IND(t_vm *vm, t_process *process, int reg_nb)
{
	// recupération d'un indirecte
}

void    ld(t_vm *vm, t_process *process)
{
	int     reg_nb;

	reg_nb = process->op.param[1];// second parametre
	if (reg_nb > 1 && reg_nb < REG_NUMBER)
	{
		if (process->op.type_param[0] == IND_CODE)
			ld_T_IND(vm, process, reg_nb); // cas ou le premier param est un T_IND
		else
			process->reg[reg_nb] = process->op.param[0]; // cas où T_REG
		process->carry = ((process->reg[reg_nb] == 0) ? 1 : 0);
		if (vm->verbose)
		show_op(process); // fonction d'affichage generique pour les 16 op
	}
}
