/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 16:43:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H

# include <inttypes.h>
# include <fcntl.h>
# include "typedef.h"
# include "error.h"

/*
** ===========
**  FUNCTIONS
** ===========
*/

/*
** READ_FILE.C
*/
void				read_file(char *file, t_asm *asmr);

/*
** GET_HEADER.C
*/
void				get_header(char *line, t_asm *asmr);

/*
** GET_OP.C
*/
void				get_op(char *line, t_asm *asmr);

/*
** GET_LABEL.C
*/
t_bool				check_label(char *str, t_asm *asmr);
void				get_label(char *label, t_asm *asmr);

/*
** GET_PARAMS.C
*/
void				get_params(char *params, t_cmd *new, t_asm *asmr);

/*
** CHECK_PARAMS.C
*/
void				check_params(t_asm *asmr);

/*
** CHECK_TYPES.C
*/
void				check_types(t_asm *asmr);

/*
** CHECK_LABELS.C
*/
void				check_labels(t_asm *asmr);

/*
** WRITE_FILE.c
*/
void				write_file(t_asm *asmr, char *title);

/*
** WRITE_TOOLS.c
*/
void				write_nb_1(t_asm *asmr, int32_t fd, int nb);
void				write_nb_4(t_asm *asmr, int32_t fd, int32_t nb);
void				write_param_byte(t_asm *asmr, int32_t fd, t_cmd *cmd);
void				write_param(t_asm *asmr, int32_t fd, t_param *param, int opcode);

#endif