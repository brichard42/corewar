/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paullaurent <paullaurent@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:20:45 by plaurent          #+#    #+#             */
/*   Updated: 2019/11/07 11:24:12 by tlandema         ###   ########.fr       */
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
t_vm    			*create_vm(size_t mem_size);
t_vm    			init_vm(size_t mem_size);
void    			delete_vm(t_vm *to_delete);
void				free_vm(t_vm **to_free);

/*
**	-------OPTIONS FUNCTIONS----------------------------------------------------
*/
void				option_parser(int ac, char **av, t_vm *env);

#endif
