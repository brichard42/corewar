/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:20:45 by plaurent          #+#    #+#             */
/*   Updated: 2020/01/14 17:15:53 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "core_error.h"
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
# include "core_typedef.h"
# include "core_define.h"
# include "visualisator.h"

/*
**	-------OPERATION STRUCT FUNCTIONS-------
*/
void	            create_op(t_process *process, int op_code);
void	            init_op(t_op *op);
void	            delete_op(t_process *process);

/*
**	-------PROCESS STRUCT FUNCTIONS-------
*/
t_process			init_process(int32_t reg_1, int32_t pc, uint8_t num);
t_process			*create_process(int32_t reg_1, int32_t pc, uint8_t num);
void				delete_process(t_process *to_delete);
void				free_process(t_process **to_delete);
void				free_process_list(t_process *to_delete);
void				process_map(t_vm *env, t_process **process_list, t_proc_apply apply);
int8_t				copy_process(t_vm *vm, int pc_address, t_process *process);

/*
**	-------COREWAR STRUCT FUNCTIONS---------------------------------------------
*/
t_vm    			*create_vm(void);
t_vm    			init_vm(void);
void    			delete_vm(t_vm *to_delete);
void				free_vm(t_vm **to_free);

/*
**	-------PARSING	FUNCTIONS-------
*/
int8_t				vm_parser(t_parser *parser, char **av);

void				get_opt(t_parser *parser, char **av);
void				get_chpnum(t_parser *parser, char **av);
void				get_dump(t_parser *parser, char **av);
void				get_champ(t_parser *parser, char **av);
void				get_verb(t_parser *parser, char **av);

uint8_t				padding_is_good(int32_t fd, int32_t sizeofpad);

void				read_magic(t_parser *parser, int32_t fd);
void				read_name(t_parser *parser, int32_t fd);
void				read_size(t_parser *parser, int32_t fd);
void				read_comment(t_parser *parser, int32_t fd);
void				read_code(t_parser *parser, int32_t fd);

uint8_t				chp_num_is_attributed(t_parser *parser);
void				attribute_next_chp_num(t_parser *parser);

int8_t				load_memory(t_parser *parser);
void				player_caller(uint8_t nb_champ, t_champ champ[MAX_PLAYERS]);

/*
**	-------PARSING_ERROR-------
*/
void				parsing_error(t_parser *parser, int32_t errer_code);

/*
**	-------CYCLES FUNCTIONS------------
*/
void                cycle(t_vm *vm);
void				check_cycle_to_die(t_vm *env);
void				kill_processes(t_vm *env);
void				exec_proc_list(t_vm *vm, t_process *process);
void				exec_process(t_vm *vm, t_process *process);
uint8_t				must_dump(t_vm *vm);
void				winner(t_vm *vm, uint8_t winner);
void				cycle_actualisator(t_vm *vm, t_process *process);
int			        check_ocp(int ocp, int op_code);
int                 modulo(int a, int b);
int	                move_pc(t_process *process);
void		        reset_life_signal(t_vm *vm);
int                 take_param_op(t_vm *vm, t_process *process);
int                 get_indirecte(t_vm *vm, t_op *op, int nb_arg);
void                show_op(t_process *process);
int				    is_opcode(char data);
int					check_params_ldi_lldi(t_process *process);
void                show_mem(t_vm *vm);

/*
 **	-------COREWAR OP FUNCTIONS------------
 */
void				live(t_vm *vm, t_process *process);
void				ld(t_vm *vm, t_process *process);
void				st(t_vm *vm, t_process *process);
void				add(t_vm *vm, t_process *process);
void				sub(t_vm *vm, t_process *process);
void				and(t_vm *vm, t_process *process);
void				or(t_vm *vm, t_process *process);
void				xor(t_vm *vm, t_process *process);
void				zjump(t_vm *vm, t_process *process);
void				ldi(t_vm *vm, t_process *process);
void				sti(t_vm *vm, t_process *process);
void				op_fork(t_vm *vm, t_process *process);
void				lld(t_vm *vm, t_process *process);
void				lldi(t_vm *vm, t_process *process);
void				lfork(t_vm *vm, t_process *process);
void				aff(t_vm *vm, t_process *process);

#endif
