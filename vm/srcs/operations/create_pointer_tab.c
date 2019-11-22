#include "corewar.h"

// void    create_pointeur_tab(void)
// {
//     void    (**op_pointeur)(t_vm, t_process);

//     op_pointeur = malloc(sizeof(*op_pointeur) * 16);
//     if (op_pointeur != NULL)
//     {
//         op_pointeur[0] = &live;
//         op_pointeur[1] = &ld;
//         op_pointeur[2] = &st;
//         op_pointeur[3] = &add;
//         op_pointeur[4] = &sub;
//         op_pointeur[5] = &and;
//         op_pointeur[6] = &or;
//         op_pointeur[7] = &xor;
//         op_pointeur[8] = &zjump;
//         op_pointeur[9] = &ldi;
//         op_pointeur[10] = &sti;
//         op_pointeur[11] = &fork;
//         op_pointeur[12] = &lld;
//         op_pointeur[13] = &lldi;
//         op_pointeur[14] = &lldi;
//         op_pointeur[15] = &lfork;
//         op_pointeur[16] = &aff;
//     }
// }