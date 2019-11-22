#include "corewar.h"

void    show_op(t_process *process)
{
    int     i;

    i = 0;
    ft_printf("player %d do op: %s"
        , process->reg[0], op_tab[process->op.op_code - 1].name);
    while (i < op_tab[process->op.op_code - 1].nb_param)
    {
        ft_printf("type param: %d, param: %d"
            , process->op.type_param[i], process->op.param[i]);
    }
}