#include "corewar.h"

void    reset_life_signal(t_vm *vm)
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

void    set_ctod(t_vm *vm)
{
	vm->ctod_nb++;
	if (vm->lives_in_cycle >= NBR_LIVE || vm->ctod_nb >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->ctod_nb = 0;
	}
	vm->lives_in_cycle = 0;
	vm->next_ctod = vm->current_cycle + vm->cycles_to_die; // utile en fonction de la solution qu'on utilise pour cycle max
}

void    kill_proc(t_process *process)
{
	t_process   *tmp_process;

	// hesitation a soit avoir un marqueur pour savoir si il est actif ou pas our del apres
	// ou d'avoir de pointeur avec un qui remonte au proc avant celui a del pour pouvoir raccrocher celui d'après
}

int     proc_lives(t_vm *vm)
{
	int         i;
	t_process   *tmp_proc;

	i = 0;
	tmp_proc = vm->process_list;
	if (vm->current_cycle >= vm->next_ctod)
	{
		set_ctod(vm);
		while (tmp_proc != NULL)
		{
			if ((vm->current_cycle - tmp_proc->last_live) >= vm->cycles_to_die) // proc mort
				kill_proc(tmp_proc);// kill process
			tmp_proc = tmp_proc->next;
		}
		if (vm->process_list == NULL)// || !player_life(vm)) supprmier car les cycles ne doivent s'arreter que quand il n'y a plus de process en vie et non de joueur directement en vie
			return (0);
	}
	return (1);
}
