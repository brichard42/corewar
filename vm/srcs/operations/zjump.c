#include "corewar.h"

/*
 ** Saute a l'adresse passé en parametre si le carry est a l'etat un.
 ** L'adresse devient alors celle de la prochaine instruction. Si le carry est
 ** a l'etat zero, rien ne se passe et le flot continue normalement jusqu'a
 ** l'instruction suivante. Rien ne precise si l'instruction consomme la
 ** totalité de ces cycles dans ce cas, a vous d'en decider.
 */

void    zjump(t_vm *vm, t_process *process)
{
	if (process->carry == 1)
	{
		process->pc = modulo(process->op.pos_op_code
			+ (process->op.param[0] % IDX_MOD), MEM_SIZE);
	}
	if (vm->verbose)
	{
		show_op(process);
		if (process->carry == 1)
			ft_printf("OK\n");
		else
			ft_printf("FAILED\n");
	}
}