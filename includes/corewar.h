/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:20:45 by plaurent          #+#    #+#             */
/*   Updated: 2019/11/13 14:25:35 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
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
# include "typedef.h"
# include "core_define.h"
# include "visualisator.h"

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
t_vm    			*create_vm(void);
t_vm    			init_vm(void);
void    			delete_vm(t_vm *to_delete);
void				free_vm(t_vm **to_free);

/*
**	-------TYPEDEF ARG_PARSER FUNCTIONS-------
*/
typedef void		(*t_get_func)(t_parser *, char **);

/*
**	-------PARSING FUNCTIONS----------------------------------------------------
*/
int8_t				vm_arg_parser(t_parser *parser, char **av);
void				get_opt(t_parser *parser, char **av);
void				get_chpnum(t_parser *parser, char **av);
void				get_dump(t_parser *parser, char **av);
void				get_champ(t_parser *parser, char **av);

#endif
