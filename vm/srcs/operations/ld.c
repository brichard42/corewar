#include "corewar.h"

/*
 ** Transfert direct RAM > Registre. Charge le premier parametre dans le
 ** registre passé en second parametre. Si la valeur du premier
 ** parametre est egale a zero, alors le carry passe a l'etat un, sinon a
 ** l'etat zero.
 */

void	put_ind_in_reg(t_vm *vm, t_process *process, int reg_nb)
{
	int		addr;

	addr = process->op.param[0] % IDX_MOD;
	process->reg[reg_nb] = 0;
	process->reg[reg_nb] = (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr, MEM_SIZE)];
	process->reg[reg_nb] <<= 8;
	process->reg[reg_nb] = (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 1, MEM_SIZE)];
	process->reg[reg_nb] <<= 8;
	process->reg[reg_nb] = (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 2, MEM_SIZE)];
	process->reg[reg_nb] <<= 8;
	process->reg[reg_nb] = (unsigned char)vm->mem[modulo(process->op.pos_op_code
		+ addr + 3, MEM_SIZE)];
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