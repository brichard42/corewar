#include "corewar.h"

void    live(t_vm *vm, t_process *process)
{
	int     n;

	// ft_printf("live\n");
	vm->lives_in_cycle += 1;
	process->last_live = vm->current_cycle;
	n = process->op.param[0] * -1;//numero du joueur
	// si le numero est negatif il faut le mettre en positif d'apres le pdf russe
	if (n >= 1 && n <= vm->champ_amount)
	{
		vm->champ[n].life_signal++;
		vm->champ[n].last_live_cycle = vm->current_cycle;
		// ft_printf("Player nb %d is said to be alive\n", n);
	}
	if (vm->verbose)
			show_op(process);
}
