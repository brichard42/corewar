#include "corewar.h"

void		reset_life_signal(t_vm *vm)
{
	int     i;

	i = 0;
	while (i < 4)
		vm->champ[i++].life_signal = 0;
}

// int     player_life(t_vm *vm)
// {
// 	int     i;
// 	int     j;

// 	i = 0;
// 	j = 0;
// 	while (i < 4)
// 	{
// 		if (vm->champ[i++].life_signal > 0)
// 			j++;
// 	}
// 	if (j <= 1)
// 		return (0);
// 	return (1);
// }

static void	set_ctod(t_vm *vm)
{
	vm->ctod_nb++;
	// ft_printf("set_ctod at cycle : %d and ctd = %d\n", vm->current_cycle, vm->cycles_to_die);
	// ft_printf("nbr_live: %d, ctod nbr: %d", vm->lives_in_cycle, vm->ctod_nb);
	if (vm->lives_in_cycle >= NBR_LIVE || vm->ctod_nb >= MAX_CHECKS)
	{
<<<<<<< HEAD:vm/srcs/core/proc_lives.c
		// ft_printf("set at cycle: %d and cycles to dir == %d\n", vm->current_cycle, vm->cycles_to_die);
		vm->cycles_to_die -= CYCLE_DELTA;
=======
		vm->cycle_to_die -= CYCLE_DELTA;
>>>>>>> brichard_refonte:vm/srcs/cycle/proc_lives.c
		vm->ctod_nb = 0;
	}
	vm->lives_in_cycle = 0;
	vm->cycle_to_die = vm->current_cycle + vm->cycle_to_die; // utile en fonction de la solution qu'on utilise pour cycle max
}

static void	check_process(t_vm *vm)
{
	t_process	*tmp_process;
	t_process	*tmp_next_process;

	tmp_process = vm->process_list;
	while (tmp_process != NULL)
	{
		if ((vm->current_cycle - tmp_process->last_live) >= vm->cycles_to_die) // proc mort
			tmp_process->active = 0;
		if (tmp_process->next && tmp_process->next->active == 0)
		{
			// ft_printf("kill proc num: %d\n", tmp_process->num);
			tmp_next_process = tmp_process->next;
			tmp_process->next = tmp_process->next->next;
			free(tmp_next_process);
		}
		tmp_process = tmp_process->next;
	}
}

int			proc_lives(t_vm *vm)
{
<<<<<<< HEAD:vm/srcs/core/proc_lives.c
	t_process   *tmp_process;

	tmp_process = vm->process_list;
	if (vm->current_cycle >= vm->next_ctod)
=======
	t_process	*tmp_proc;
	t_process	*tmp_next_proc;
	int32_t		i;

	i = 0;
	tmp_proc = vm->process_list;
	if (vm->current_cycle >= vm->cycle_to_die)
>>>>>>> brichard_refonte:vm/srcs/cycle/proc_lives.c
	{
		if (vm->cycles_to_die <= 0)
			return (0);
		check_process(vm);
		set_ctod(vm);
		while (tmp_process != NULL)
		{
<<<<<<< HEAD:vm/srcs/core/proc_lives.c
			if (tmp_process->active == 1)
				return (1);
			tmp_process = tmp_process->next;
		}
=======
			tmp_next_proc = tmp_proc->next;
			if ((vm->current_cycle - tmp_proc->last_live) >= vm->cycle_to_die) // proc mort
				delete_process(tmp_proc);// kill process
			tmp_proc = tmp_next_proc;
		}
		if (vm->process_list == NULL)
			return (0);
>>>>>>> brichard_refonte:vm/srcs/cycle/proc_lives.c
	}
	else
		return (1);
	return (0);
}
