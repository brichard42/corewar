#include "corewar.h"

int			modulo(int a, int b)
{
	if (a % b >= 0)
		return (a % b);
	else
		return ((a % b) + b);
}

static int	size_param(int ocp_chunk, t_op_tab *ref)
{
	if (ocp_chunk == 1)
		return (1);
	else if (ocp_chunk == 2)
		return ((ref->direct_size) ? 2 : 4);
	else if (ocp_chunk == 3)
		return (IND_SIZE);
	return (0);
}

int			move_pc(t_process *process)
{
	int         move;
	t_op_tab    *ref;

	move = 1; // passer l'op_code
	ref = &op_tab[process->op.op_code - 1];
	if (!ref->jsp_encore) // on a forcement un T_DIR sans ocp
		return ((ref->direct_size) ? move + 2 : move + 4);
	else // sinon on passe l'ocp
		move++;
	if (ref->nb_param >= 1) // meme procédé que dans check ocp (et il y a explication)
		move += size_param((process->op.ocp & 0xC0) >> 6, ref);
	if (ref->nb_param >= 2)
		move += size_param((process->op.ocp & 0x30) >> 4, ref);
	if (ref->nb_param >= 3)
		move += size_param((process->op.ocp & 0xC) >> 2, ref);
	return (modulo(move, MEM_SIZE));
}
