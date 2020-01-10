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

static int8_t	get_ind(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned int    value;

	value = 0;
	value = value | (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 2) % MEM_SIZE];
	proc->op.param[num] = value;
	if ((value & 0x8000) == 0x8000)
		proc->op.param[num] = (value - USHRT_MAX) - 1;
	return (IND_SIZE);
}

static void	get_dir(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned int    value;

	value = 0;
	value = value | (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 2) % MEM_SIZE];
	if (g_op_tab[proc->op.op_code - 1].direct_size == 1)
	{
		if ((value & 0x8000) == 0x8000)
			value = (value - USHRT_MAX) - 1;
		proc->op.param[num] = value;
		return ;
	}
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 3) % MEM_SIZE];
	value = value << 8;
	value = value | (unsigned char)vm->mem[(pos + 4) % MEM_SIZE];
	proc->op.param[num] = value;
}

static int8_t	get_reg(t_vm *vm, t_process *proc, int num, int pos)
{
	unsigned char   value;

	value = (unsigned char)vm->mem[(pos + 1) % MEM_SIZE];
	//ft_printf("(%d) %d <- reg | %d \n", proc->reg[0], value, vm->current_cycle);
	proc->op.param[num] = value;
	if (value < 1 || value > 16)
		return (-1);
	return (1);
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
		return (get_reg(vm, proc, num, pos));
	else if (type == DIR_CODE)
	{
		get_dir(vm, proc, num, pos);
		return ((g_op_tab[proc->op.op_code - 1].direct_size ? 2 : 4));
	}
	else if (type == IND_CODE)
		return (get_ind(vm, proc, num, pos));
	return (0);
}

int     take_param_op(t_vm *vm, t_process *process)
{
	unsigned int     i;
	int     pos;
	int		tmp;

	i = 0;
	pos = process->pc;
	//ft_printf("%d\n", op_tab[process->op.op_code - 1].bytecode);
	if (g_op_tab[process->op.op_code - 1].bytecode)
	{
		pos++;
		process->op.ocp = (unsigned char)vm->mem[pos % MEM_SIZE];
		if (check_ocp(process->op.ocp, process->op.op_code) == 1)
		{
			while (i < g_op_tab[process->op.op_code - 1].nb_param)
			{
				tmp = find_param(vm, process, i, pos); 
				if (tmp == -1)
					return (0);
				pos += tmp;
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
