#include "corewar.h"

/*
 ** Transfert indirect RAM > Registre. Charge la valeur a l'adresse
 ** resultante de l'addition des deux premiers paramametres, dans le
 ** registre passé en troisieme parametre. Si cette valeur est nulle, alors le
 ** carry passe a l'etat un, sinon a l'ettat zero.
 */

int					check_params_ldi_lldi(t_process *process)
{
	if (process->op.type_param[0] == REG_CODE && (process->op.param[0] < 1
		|| process->op.param[0] > REG_NUMBER))
		return (0);
	else if (process->op.type_param[1] == REG_CODE && (process->op.param[1] < 1
		|| process->op.param[1] > REG_NUMBER))
		return (0);
	else if (process->op.type_param[2] == REG_CODE && (process->op.param[2] < 1
		|| process->op.param[2] > REG_NUMBER))
		return (0);
	else
		return (1);
}

static unsigned int	get_value(t_vm *vm, unsigned int addr)
{
	unsigned int	value;

	value = 0;
	value |= (unsigned char)vm->mem[modulo(addr, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 1, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 2, MEM_SIZE)];
	value = value << 8;
	value |= (unsigned char)vm->mem[modulo(addr + 3, MEM_SIZE)];
	return (value);
}

void    			ldi(t_vm *vm, t_process *process)
{
	unsigned int	addr;

	if (!check_params_ldi_lldi(process))
		return ;
	if (process->op.type_param[0] == REG_CODE)
		process->op.param[0] = process->reg[process->op.param[0]];
	else if (process->op.type_param[0] == IND_CODE)
		process->op.param[0] = get_indirecte(vm, &process->op, 0);
	if (process->op.type_param[1] == REG_CODE)
		process->op.param[1] = process->reg[process->op.param[1]];
	addr = ((process->op.param[0] + process->op.param[1]) % IDX_MOD)
		+ process->op.pos_op_code;
	process->reg[process->op.param[2]] = get_value(vm, addr);
	if (vm->verbose)
		show_op(process);
}
