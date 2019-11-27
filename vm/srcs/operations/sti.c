#include "corewar.h"

/*
 ** Transfert indirect Registre > RAM. Charge la valeur contenu dans le
 ** registre passé en premier parametre a l'adresse resultante de
 ** l'addition des deux derniers paramametres. Si cette valeur est nulle,
 ** alors le carry passe a l'etat un, sinon a l'etat zero.
 */

void    sti(t_vm *vm, t_process *process)
{
	int i;
	int reg_nb;
	int	value;
	int	address;

	reg_nb = process->op.param[0]; // first param
	address = ((process->op.param[1] + process->op.param[2]) % IDX_MOD) + 3;
	if (address = 3)
		process->carry = 1
	else
		process->carry = 0;
	i = 4;
	if (reg_nb > 1 && reg_nb < REG_NUMBER)
	{
		value = process->reg[reg_nb];
		while (i > 0)
		{
			vm->mem_owner[address % MEM_SIZE] = vm->mem_owner[process->pc]; //on set le proprietaire de la memoire
			vm->mem[address] = value & 0xFF; //on donne a l'adress la valeur
			value >>= 8; // on decale 
			address--;
			i--;
		}
	}
}
