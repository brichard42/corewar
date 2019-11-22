#include "corewar.h"

int	is_opcode(char data)
{
	if (data > 0 && data < 17)
		return (1);
	return (0);
}

int     dump(t_vm *vm)
{
	if (vm->current_cycle == vm->cycles_to_dump)
	{
		// afficher la memoire et quitter proprement
		ft_printf("dump\n");
		return (0);
	}
	return (1);
}

void    exec_process(t_vm *vm, t_process *process)
{
	if (process->op.active == 0)
	{
		if (is_opcode(vm->mem[process->pc % MEM_SIZE]))
			create_op(process, vm->mem[process->pc % MEM_SIZE]);
		else
			process->pc = (process->pc + 1) % MEM_SIZE;
	}
	else
	{
		if (--process->op.nb_cycle <= 0)
		{
			if (take_param_op(vm, process))// remplir l'op avec les params et les checks en meme temps
				op_tab[process->op.op_code].func(vm, process);
			if (process->op.op_code != 9 || (process->op.op_code == 9 && !process->carry)) // pour le cas zjump ou le pc est deja déplacersauf quand carry
				process->pc += move_pc(process); // deplacer le pc en fonction du nombre de param etc
			process->pc = modulo(process->pc, MEM_SIZE);
			delete_op(&process->op);
		}
	}

}

void    exec_proc_list(t_vm *vm, t_process *process)
{
	while (process != NULL)
	{
		exec_proc(vm, process);
		process = process->next;
	}
}

void    cycle(t_vm *vm)
{
	t_process   *tmp_proc;

	while (proc_lives(vm) && dump(vm)) // qd on dump on doit prendre celui qui a fait le dernier live comme winner ?
	{
		if (!(vm->current_cycle % vm->cycles_to_die))
			reset_life_signal(vm);
		if (vm->verbose)
			ft_printf("It is now cycle: %d\n", vm->current_cycle);
		tmp_proc = vm->process_list;
		exec_proc_list(vm, tmp_proc);
		vm->current_cycle++;
	}
}
