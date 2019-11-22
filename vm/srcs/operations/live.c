#include "corewar.h"

void    live(t_vm *vm, t_process *process)
{
	int     n;

	vm->lives_in_cycle++;
	process->last_live = vm->current_cycle;
	n = process->reg[0];//numero du joueur
	if (n >= 0 && n <= 4)
	{
		vm->champ[n].life_signal++;
		vm->champ[n].last_live_cycle = vm->current_cycle;
	}
}
