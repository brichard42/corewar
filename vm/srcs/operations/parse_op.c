#include "corewar.h"

int	    	get_indirecte(t_vm *vm, t_op *op, int nb_arg)
{
	int		value;
	int		pos;

	value = 0;
	pos = op->pos_op_code + (op->param[nb_arg] % IDX_MOD);
	value = value | (unsigned char)vm->mem[modulo(pos, MEM_SIZE)];
	value = value << 8;
	value = value | (unsigned char)vm->mem[modulo(pos + 1, MEM_SIZE)];
	value = value << 8;
	value = value | (unsigned char)vm->mem[modulo(pos + 2, MEM_SIZE)];
	value = value << 8;
	value = value | (unsigned char)vm->mem[modulo(pos + 3, MEM_SIZE)];
	return (value);
}

static void	get_ind(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned int    value;

	value = 0;
	value = value | (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	proc->op.param[num] = value;
}

static void	get_dir(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned int    value;

	value = 0;
	value = value | (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 2) % MEM_SIZE];
	if (op_tab[proc->op.op_code - 1].direct_size == 1)
	{
		value = value << 8;
		value = value | (unsigned char)vm->mem[(pos + 3) % MEM_SIZE];
		value = value << 8;
		value = value | (unsigned char)vm->mem[(pos + 4) % MEM_SIZE];
	}
	proc->op.param[num] = value;
}

static void	get_reg(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned char   value;

	value = (unsigned char)vm->mem[(pos + 1)];
	proc->op.param[num] = value;
}

static int	find_param(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned char   type;
	unsigned char   mask;

	type = proc->op.ocp;
	mask = 0xC0; //1100 0000
	mask >>= (2 * num); // on decale pour que ce soit en face les deux bits que l'on veut regarder
	type &=  mask; // on mets tout les bits qui nous interresse pas a 0
	type >>= (6 - 2 * num); // on de decales deux bits au debut
	proc->op.type_param[num] = type;
	if (type == REG_CODE)
	{
		get_reg(vm, proc, num, pos);
		return (1); // REG_SIZE
	}
	if (type == DIR_CODE)
	{
		get_dir(vm, proc, num, pos);
		return ((op_tab[proc->op.op_code - 1].direct_size ? 2 : 4));
	}
	if (type == IND_CODE)
	{
		get_ind(vm, proc, num, pos);
		return (IND_SIZE);
	}
	return (0);
}

int     take_param_op(t_vm *vm, t_process *process)
{
	unsigned int     i;
	int     pos;

	i = 0;
	pos = process->pc;
	if (op_tab[process->op.op_code - 1].jsp_encore)
	{
		pos++;
		process->op.ocp = (unsigned char)vm->mem[pos % MEM_SIZE];
		if (check_ocp(process->op.ocp, process->op.op_code) == 1)
		{
			while (i < op_tab[process->op.op_code - 1].nb_param)
			{
				pos += find_param(vm, process, i, pos);
				i++;
			}
		}
		else
			return (0);
	}
	else
		get_dir(vm, process, 0, pos);
	return (1);
}
