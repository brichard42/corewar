/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:20:45 by plaurent          #+#    #+#             */
/*   Updated: 2019/11/22 18:48:37 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <unistd.h>
# include "op.h"
# include "typedef.h"
# include "core_define.h"
# include "visualisator.h"

/*
**	-------PROCESS STRUCT FUNCTIONS-------
*/
t_process			init_process(int32_t reg_1, int32_t pc);
t_process			*create_process(int32_t reg_1, int32_t pc);
void				delete_process(t_process *to_delete);
void				free_process(t_process **to_delete);

/*
**	-------COREWAR STRUCT FUNCTIONS---------------------------------------------
*/
t_vm    			*create_vm(void);
t_vm    			init_vm(void);
void    			delete_vm(t_vm *to_delete);
void				free_vm(t_vm **to_free);

/*
**	-------TYPEDEF ARG_PARSER FUNCTIONS-----------------------------------------
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
**	-------TYPEDEF READ_CHAMP.C FUNCTIONS---------------------------------------
*/

typedef int8_t		(*t_read_func)(t_parser *, int32_t);

/*
**	-------PARSING	FUNCTIONS-------
*/
int8_t				vm_arg_parser(t_parser *parser, char **av);

void				get_opt(t_parser *parser, char **av);
void				get_chpnum(t_parser *parser, char **av);
void				get_dump(t_parser *parser, char **av);
void				get_champ(t_parser *parser, char **av);

int8_t				read_magic(t_parser *parser, int32_t fd);
int8_t				read_name(t_parser *parser, int32_t fd);
int8_t				read_size(t_parser *parser, int32_t fd);
int8_t				read_comment(t_parser *parser, int32_t fd);
int8_t				read_code(t_parser *parser, int32_t fd);

int8_t				fill_arena(t_vm *env, uint8_t	champ_amount);

// /*
// **	-------OPERATION FUNCTIONS--------------------------------------------------
// */
// void				op_live(t_vm *v, t_list *process);
// void				op_ld(t_vm *v, t_list *process);
// void				op_st(t_vm *v, t_list *process);
// void				op_add(t_vm *v, t_list *process);
// void				op_sub(t_vm *v, t_list *process);
// void				op_and(t_vm *v, t_list *process);
// void				op_or(t_vm *v, t_list *process);
// void				op_xor(t_vm *v, t_list *process);
// void				op_zjmp(t_vm *v, t_list *process);
// void				op_ldi(t_vm *v, t_list *process);
// void				op_sti(t_vm *v, t_list *process);
// void				op_fork(t_vm *v, t_list *process);
// void				op_lld(t_vm *v, t_list *process);
// void				op_lldi(t_vm *v, t_list *process);
// void				op_lfork(t_vm *v, t_list *process);
// void				op_aff(t_vm *v, t_list *process);

/*
 **	-------COREWAR OP FUNCTIONS------------
 */
void				op_live(t_vm *vm, t_process *process);
void				op_ld(t_vm *vm, t_process *process);
void				op_st(t_vm *vm, t_process *process);
void				op_add(t_vm *vm, t_process *process);
void				op_sub(t_vm *vm, t_process *process);
void				op_and(t_vm *vm, t_process *process);
void				op_or(t_vm *vm, t_process *process);
void				op_xor(t_vm *vm, t_process *process);
void				op_zjump(t_vm *vm, t_process *process);
void				op_ldi(t_vm *vm, t_process *process);
void				op_sti(t_vm *vm, t_process *process);
void				op_fork(t_vm *vm, t_process *process);
void				op_lld(t_vm *vm, t_process *process);
void				op_lldi(t_vm *vm, t_process *process);
void				op_lfork(t_vm *vm, t_process *process);
void				op_aff(t_vm *vm, t_process *process);

#endif
