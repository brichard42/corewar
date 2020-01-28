/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_typedef.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2020/01/28 16:51:52 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_TYPEDEF_H
# define ASM_TYPEDEF_H

# include "op.h"

/*
** ==================
**  HEADER STRUCTURE
** ==================
**
** - magic:		Magic number.
** - prog_name:	String of the champion's name.
** - prog_size:	Computed hex code size of all the instructions.
** - comment:	String of the comment.
*/
typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

/*
** ==============
**  OP STRUCTURE
** ==============
**
** Stores all the characteristics of an instruction.
** See 'op.c'.
*/
typedef struct		s_op
{
	char			*name;
	int				nb_param;
	int				type_param[3];
	int				op_code;
	int				nb_cycle;
	char			*comment;
	t_bool			have_param_byte;
	t_bool			is_half_int;
}					t_op;

/*
** =====================
**  PARAMETER STRUCTURE
** =====================
**
** - str:	Full string of the parameter.
** - type:	Type, stored with '***_CODE' defines.
** - value:	Computed value to be translated in hex code.
** - temp:	If it's a label, stores label's name.
*/
typedef struct		s_param
{
	char			*str;
	char			*temp;
	int				type;
	int				value;
}					t_param;

/*
** =======================
**  INSTRUCTION STRUCTURE
** =======================
**
** - op_code:	Op code of the instruction.
** - label:		If instructionis labeled, label's name.
** - params:	Array of parameters.
** - nb_param:	Number of parameters.
** - size:		Computed size of the hex code.
** - nb_line:	Line in the '.s' file.
** - next:		Linked-list --> link to the next element.
*/
typedef struct		s_cmd
{
	struct s_cmd	*next;
	char			*label;
	t_param			params[MAX_ARGS_NUMBER];
	t_bool			multi_label;
	int				op_code;
	int				nb_param;
	size_t			size;
	size_t			nb_line;
}					t_cmd;

/*
** =====================
**  ASSEMBLER STRUCTURE
** =====================
**
** - op_tab:	  Array of all the possible instructions defined in 'op.c'.
** - header:	  See 'op.h' structure.
** - is_name:	  If the name is written in several lines
**				  (to remember we are reading the name).
** - i_name:	  Keek track of the current index of the name.
** - got_name:	  Whether the name is fully acquired or not.
** - is_comment:  If the comment is written in several lines
**				  (to remember we are reading the comment).
** - i_comment:	  Keek track of the current index of the comment.
** - got_comment: Whether the comment is fully acquired or not.
** - label:		  Last label seen.
** - label_size:  Label's size.
** - nb_line:	  Number of line of the file.
** - list:		  Linked list of instructions.
*/

typedef struct		s_garbage
{
	char			**tab;
	char			*params;

}					t_garbage;

typedef struct		s_asm
{
	char			*label;
	char			*line;
	t_cmd			*list;
	t_op			op_tab[16];
	t_garbage		garbage;
	t_header		header;
	t_bool			is_name;
	t_bool			got_name;
	t_bool			is_comment;
	t_bool			got_comment;
	int				i_name;
	int				i_comment;
	size_t			label_size;
	size_t			nb_line;
}					t_asm;

#endif
