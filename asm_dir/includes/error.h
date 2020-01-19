/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:42:00 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 16:59:52 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stddef.h>

# include "typedef.h"

/*
** All error's message used.
*/

# define ERROR_MALLOC			"Could not perform malloc.\n"
# define USAGE_ASM 				"Usage ./asm <sourcefile.s>\n"
# define ERROR_FILE				"Can't read source file %s.\n"
# define ERROR_SYNTAX			"Syntax error at line %lu.\n"
# define ERROR_UNEXPECTED		"Unexpected symbol at line %lu.\n"
# define ERROR_LABEL_CHAR		"Wrong label's char at line %lu.\n"
# define ERROR_OP_NAME			"Instruction name unknown at line %lu.\n"
# define ERROR_ARGS_NUMBER		"Too many arguments at line %lu.\n"
# define ERROR_NAME_LENGTH		"Champion's name is too long.\n"
# define ERROR_COMMENT_LENGTH	"Comment is too long.\n"
# define ERROR_CHAMP_SIZE		"Champion's size is too big.\n"
# define ERROR_PARAM_VAL		"Wrong argument's value at line %lu.\n"
# define ERROR_PARAM_TYPE		"Wrong argument's type at line %lu.\n"
# define ERROR_LABEL_DUPLICATE	"The following label already exist: \
%s (line %lu).\n"
# define ERROR_LABEL_ALONE		"The following label doesn't have an associate \
cmd: %s (line %lu).\n"
# define ERROR_LABEL_UNKNOW		"The following label doesn't exist: \
%s (line %lu).\n"
# define ERROR_LABEL_CMD		"The following label refer to his own command: \
%s (line %lu).\n"
# define ERROR_FILE_NAME		"The input file must end with '.s'.\n"
# define ERROR_FILE_OPEN		"Error creating the binary file : %s.\n"
# define ERROR_FILE_WRITE		"Error writing in the binary file.\n"

/*
** ===========
**  FUNCTIONS
** ===========
*/

/*
** LIST_TOOLS.C
*/
t_cmd	*new_elem(t_asm *asmr);
t_cmd	*add_elem(t_cmd *list, t_cmd *elem);
void	clear_list(t_cmd *list);

/*
** ERROR.C
*/
void	free_asm(t_asm *asmr);
void	exit_msg(char *error_msg, char *str, size_t *nb, t_asm *asmr);

#endif