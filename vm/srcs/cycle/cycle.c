#include "corewar.h"

int				is_opcode(char data)
{
	// ft_printf("teste op_code: %d\n", data);
	if (data > 0 && data < 17)
		return (1);
	return (0);
}

void		winner(t_vm	*vm)
{
	uint8_t	i;

	i = vm->winner_index;
	ft_printf("contestant nb %d, %s , has won !\n", i + 1, vm->champ[i].name);
}

uint8_t		must_dump(t_vm *vm)
{
	if ((int32_t)vm->current_cycle == vm->cycle_to_dump)
	{
		// afficher la memoire, le winner et quitter proprement
		show_mem(vm);
		return (TRUE);
	}
	return (FALSE);
}

void		exec_process(t_vm *vm, t_process *process)
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
				op_tab[process->op.op_code - 1].func(vm, process);
			if (process->op.op_code != 9 || (process->op.op_code == 9 && !process->carry)) // pour le cas zjump ou le pc est deja déplacersauf quand carry
				process->pc += move_pc(process); // deplacer le pc en fonction du nombre de param etc
			// process->pc = modulo(process->pc, MEM_SIZE);
			delete_op(process);
		}
	}

}

void		exec_proc_list(t_vm *vm, t_process *process)
{
	while (process != NULL)
	{
		if (process->active == 1)
			exec_process(vm, process);
		process = process->next;
	}
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
		exec_proc_list(env, (*d_process));
		++env->current_cycle;
		++env->current_sub_cycle;
	}
	winner(env);
}
