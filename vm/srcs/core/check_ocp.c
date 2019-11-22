#include "corewar.h"

int     param_ok(int ocp_chunk, int op_code, int num_param)
{
	if (ocp_chunk < 1 || ocp_chunk > 3)
		return (0);
	if (ocp_chunk == 3)
		ocp_chunk += 1; // car t_reg = 1 et t_dir = 2 mais t_ind = 4 et non 3
	if (ocp_chunk & op_tab[op_code - 1].type_param[num_param])
		return (1);
	return (0);
}

int     check_ocp(int ocp, int op_code)
{
	int     nb_param;

	nb_param = op_tab[op_code - 1].nb_param;
	//  on regarde le premier param && on envoie a param_ok le deux bits que l'on veut regarder cad les deux dernier 1100 0000
	if (nb_param >= 1 && !param_ok((ocp & 0xC0) >> 6, op_code, 0))
		return (0);
	//  on regarde le deuxieme param si il existe && on envoie a param_ok le deux bits que l'on veut regarder cad les deux avant dernier 0011 0000
	if (nb_param >= 2 && !param_ok((ocp & 0x30) >> 4, op_code, 1))
		return (0);
	//  on regarde le troisieme param si il existe && on envoie a param_ok le deux bits que l'on veut regarder cad les deux avant dernier 0000 1100
	if (nb_param >= 3 && !param_ok((ocp & 0xC) >> 2, op_code, 2))
		return (0);
	return (1);
}
