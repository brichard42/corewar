/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:20:45 by plaurent          #+#    #+#             */
/*   Updated: 2019/10/23 14:08:12 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdlib.h>

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
	uint8_t				carry;
}					t_process;

/*
**	-------TYPEDEF COREWAR STRUCTURE-------
*/
typedef struct		s_vm
{
	t_process			*process_list;
	char				*champ_names[4];
	uint32_t			cycles_to_die;
	char				*mem;
}					t_vm;

/*
**	-------PROCESS STRUCT FUNCTIONS-------
*/
t_process			init_process(int32_t reg_1, int32_t pc);
t_process			*create_process(int32_t reg_1, int32_t pc);
void				delete_process(t_process *to_delete);
void				free_process(t_process **to_delete);

/*
**	-------COREWAR STRUCT FUNCTIONS-------
*/
t_vm    			*create_vm(void);
t_vm    			init_vm(void);
void    			delete_vm(t_vm *to_delete);
void				free_vm(t_vm **to_free);

#endif
