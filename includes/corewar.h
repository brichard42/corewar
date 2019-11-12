/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:13:47 by brichard          #+#    #+#             */
/*   Updated: 2019/11/07 14:59:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "core_define.h"

/*
**	-------PARSING	STATES ENUM-------
*/
enum				e_state
{
	S_OPTION,
	S_DUMP,
	S_CHP_NUM,
	S_CHAMP,
	S_ERR
};

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
	char				*champ_names[MAX_PLAYERS];
	char				mem[MEM_SIZE];
	uint32_t			cycles_to_die;
	int32_t				cycles_to_dump;
	uint8_t				visu;
	uint8_t				verbose;
}					t_vm;

/*
**	-------TYPEDEF PARSING STRUCTURE-------
*/
typedef struct		s_parser
{
	t_vm			env;
	enum e_state	state;
	int32_t			chp_num;
}					t_parser;

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
t_vm				*create_vm(void);
t_vm				init_vm(void);
void				delete_vm(t_vm *to_delete);
void				free_vm(t_vm **to_free);

/*
**	-------TYPEDEF ARG_PARSER FUNCTIONS-------
*/
typedef void		(*t_get_func)(t_parser *, char **);

/*
**	-------PARSING	FUNCTIONS-------
*/
int8_t				vm_arg_parser(t_parser *parser, char **av);

#endif
