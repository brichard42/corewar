#include "corewar.h"

/*
 ** Transfert direct Registre > RAM / Registre. Charge le contenu du
 ** registre passé en premier parametre dans le second parametre. Si la
 ** valeur du premier parametre est egale a zero, alors le carry passe a
 ** l'etat un, sinon a l'etat zero.
 */

void	func(t_vm *vm, t_process *process) // j'ai des doutes, a teste précisement
{
	unsigned int	addr;

	addr = process->op.pos_op_code + (process->op.param[1] % IDX_MOD);
	vm->mem[modulo(addr, MEM_SIZE)] |= (process->reg[process->op.param[0]] >> 24);
	vm->mem[modulo(addr + 1, MEM_SIZE)] |= (process->reg[process->op.param[0]] >> 16);
	vm->mem[modulo(addr + 2, MEM_SIZE)] |= (process->reg[process->op.param[0]] >> 8);
	vm->mem[modulo(addr + 3, MEM_SIZE)] |= process->reg[process->op.param[0]];
}

void    st(t_vm *vm, t_process *process)
{
	if (process->op.type_param[0] == REG_CODE && process->op.param[0] > 1
		&& process->op.param[0] < REG_NUMBER)
	{
		if (process->op.type_param[1] == REG_CODE)
		{
			if (process->op.param[1] > 1 && process->op.param[1] < REG_NUMBER)
				process->reg[process->op.param[1]] = process->reg[process->op.param[0]];
		}
		else
			func(vm, process);// le deuxieme param est un T_IND
		process->carry = ((process->reg[process->op.param[0]] == 0) ? 1 : 0); // gestion du carry
		if (vm->verbose)
			show_op(process);
	}
}