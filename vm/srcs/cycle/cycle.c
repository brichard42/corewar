#include "corewar.h"

/*
int				is_opcode(char data)
{
	if (data > 0 && data < 17)
		return (1);
	return (0);
}
*/

/*
static void		exec_process(t_vm *vm, t_process *process)
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
			delete_op(process);
		}
	}

}

static void		exec_proc_list(t_vm *vm, t_process *process)
{
	while (process != NULL)
	{
		exec_process(vm, process);
		process = process->next;
	}
}
*/

static uint8_t	must_dump(t_vm *vm)
{
	if ((int32_t)vm->current_cycle == vm->cycle_to_dump)
	{
		// afficher la memoire, le winner et quitter proprement
		ft_printf("Dump_time!!\n");
		return (TRUE);
	}
	return (FALSE);
}

void			cycle(t_vm *env)
{
	t_process   **d_process;

	d_process = &env->process_list;
	while (*d_process != NULL && must_dump(env) == FALSE)
	{
		if (env->verbose == ON)
			ft_printf("It is now cycle: %d\n", env->current_cycle);
		check_cycle_to_die(env);
		++env->current_cycle;
		++env->current_sub_cycle;
		/*
		proc_lives(vm);
		if (!(vm->current_cycle % vm->cycle_to_die))
			reset_life_signal(vm);
		exec_proc_list(vm, d_process);
		*/
	}
}
