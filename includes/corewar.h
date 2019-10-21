/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:20:45 by plaurent          #+#    #+#             */
/*   Updated: 2019/10/21 16:16:07 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

/*
**	-------TYPEDEF PROCESS STRUCTURE-------
*/
typedef struct		s_process
{
	struct s_process	*next;
	struct s_process	*prev;
	int32_t				reg[REG_NUMBER];
	int32_t				pc;
	int32_t				cycles_left;
}					t_process;

/*
**	-------TYPEDEF COREWAR STRUCTURE-------
*/
typedef struct		s_vm
{
	t_process			*process_list;
	char				*champ_names[4];
	uint32_t			cycles_to_die;
	char				mem[MEM_SIZE];
}					t_vm;



#endif
