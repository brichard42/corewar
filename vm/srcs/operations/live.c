#include "corewar.h"

void    live(t_vm *vm, t_process *process)
{
	int     n;

	// ft_printf("live\n");
	++vm->live_count;
	process->last_live = vm->current_cycle;
	n = process->op.param[0] * -1;//numero du joueur
	// si le numero est negatif il faut le mettre en positif d'apres le pdf russe
	if (n >= 1 && n <= vm->champ_amount)
	{
		vm->champ[n - 1].last_live_cycle = vm->current_cycle;
		vm->winner_index = n - 1;
		// ft_printf("Player nb %d is said to be alive\n", n);
	}
	if (vm->verbose)
			show_op(process);
}
