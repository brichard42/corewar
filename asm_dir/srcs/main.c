/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:10:13 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/30 13:49:06 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

/*
** Initializes assembler structure's values.
*/
void				init_asm(t_asm *asmr)
{
	ft_bzero((void *)asmr, sizeof(t_asm));
	get_op_tab(asmr->op_tab);
	asmr->header.magic = COREWAR_EXEC_MAGIC;
	asmr->is_name = FALSE;
	asmr->got_name = FALSE;
	asmr->is_comment = FALSE;
	asmr->got_comment = FALSE;
}

/*
** Compute the chamion's size by adding all computed sizes of instructions list.
*/
static unsigned int	get_prog_size(t_cmd *list, t_asm *asmr)
{
	unsigned int	res;

	res = 0;
	while (list)
	{
		res += list->size;
		list = list->next;
	}
	if (res > CHAMP_MAX_SIZE)
		exit_msg(ERROR_CHAMP_SIZE, NULL, NULL, asmr);
	return (res);
}

/*
** Entry point. Steps:
** 	Read and store all data of the '.s' file with first verifications.
**		(init_asm & read_file)
**	End all verifications and compute size.
**		(check_params & check_types & check_labels & get_prog_size)
**	Write the binary result and free malloced memory.
**		(write_file & free_asm)
*/
int					main(int ac, char **av)
{
	t_asm	asmr;

	if (ac < 2)
		exit_msg(USAGE_ASM, NULL, NULL, NULL);
	init_asm(&asmr);
	read_file(av[ac - 1], &asmr);
	check_params(&asmr);
	check_types(&asmr);
	check_labels(&asmr);
	asmr.header.prog_size = get_prog_size(asmr.list, &asmr);
	write_file(&asmr, av[ac - 1]);
	free_asm(&asmr);
	av[1][ft_strlen(av[1]) - 1] = '\0';
	ft_printf("Writing in the program %scor\n", av[1]);
	return (0);
}
