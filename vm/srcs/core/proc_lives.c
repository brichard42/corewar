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
		// ft_printf("set at cycle: %d and cycles to dir == %d\n", vm->current_cycle, vm->cycles_to_die);
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->ctod_nb = 0;
	}
	vm->lives_in_cycle = 0;
	vm->next_ctod = vm->current_cycle + vm->cycles_to_die; // utile en fonction de la solution qu'on utilise pour cycle max
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
	int         i;
	t_process   *tmp_process;

	i = 0;
	tmp_process = vm->process_list;
	if (vm->current_cycle >= vm->next_ctod)
	{
		if (vm->cycles_to_die <= 0)
			return (0);
		check_process(vm);
		set_ctod(vm);
		while (tmp_process != NULL)
		{
			if (tmp_process->active == 1)
				return (1);
			tmp_process = tmp_process->next;
		}
	}
	else
		return (1);
	return (0);
}
