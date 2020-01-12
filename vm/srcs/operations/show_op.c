/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:12:40 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/12 23:17:38 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** VA FALLOIR DEAL WITH THAT SHIT
*/

void	show_op(t_process *process)
{
	(void)process;
}

/*
**void	show_op(t_process *process)
**{
**	unsigned int	 i;
**
**	i = 0;
**	// ft_printf("player %d process nb %d do op nb: %d and name : %s\n"
**	//	 , process->reg[0], process->num, process->op.op_code,
**			op_tab[process->op.op_code - 1].name);
**	// ft_printf("nb param: %d", op_tab[process->op.op_code - 1].nb_param);
**	// while (i < op_tab[process->op.op_code - 1].nb_param)
**	// {
**	//	 ft_printf("type param: %d, param: %d\n\n"
**	//		 , process->op.type_param[i], process->op.param[i]);
**	//	 i++;
**	// }
**	ft_printf("P	%d | %s", process->num,
**	op_tab[process->op.op_code - 1].name);
**	if (process->op.op_code == 11)
**	{
**  //	  ft_printf(" %d + %d\n", process->op.param[1] % IDX_MOD,
**			process->op.param[2] % IDX_MOD);
**	}
**	else
**	{
**	while (i < g_op_tab[process->op.op_code - 1].nb_param)
**	{
** //		ft_printf(" %d"
**	//		, process->op.param[i]);
**		i++;
**	}
**	}
**	//ft_printf("\n");
**}
*/

void	show_mem(t_vm *vm)
{
	int	i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (!(i % 64) && i)
			ft_printf("%#.4x : ", i);
		ft_printf("%02x ", (unsigned char)vm->mem[i]);
		if (i / 64 != (i + 1) / 64)
			ft_printf("\n");
		i++;
	}
}
