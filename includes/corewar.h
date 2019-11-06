/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:20:45 by plaurent          #+#    #+#             */
/*   Updated: 2019/11/06 09:54:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdlib.h>
# include <stdbool.h>
# include "core_define.h"
# include "visualisator.h"

/*
**	-------TYPEDEF PROCESS STRUCTURE--------------------------------------------
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
**	-------TYPEDEF COREWAR STRUCTURE--------------------------------------------
*/
typedef struct		s_vm
{
	t_window			*window;
	t_process			*process_list;
	char				*champ_names[MAX_PLAYERS];
	uint32_t			cycles_to_die;
	char				mem[MEM_SIZE];
	uint8_t				visu_on;
}					t_vm;

/*
**	-------PROCESS STRUCT FUNCTIONS---------------------------------------------
*/
t_process			init_process(int32_t reg_1, int32_t pc);
t_process			*create_process(int32_t reg_1, int32_t pc);
void				delete_process(t_process *to_delete);
void				free_process(t_process **to_delete);

/*
**	-------COREWAR STRUCT FUNCTIONS---------------------------------------------
*/
t_vm    			*create_vm(size_t mem_size);
t_vm    			init_vm(size_t mem_size);
void    			delete_vm(t_vm *to_delete);
void				free_vm(t_vm **to_free);

/*
**	-------OPTIONS FUNCTIONS----------------------------------------------------
*/
void				option_parser(int ac, char **av, t_vm *env);

#endif
