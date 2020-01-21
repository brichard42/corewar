/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/01/21 16:06:03 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "libft.h"

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

# define IND_SIZE				2
# define REG_SIZE				1  // Changed from original value (4) to fit with supposed real value.
# define DIR_SIZE				4


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4 * 1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 4)


# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
**
*/

typedef char		t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		128
# define COMMENT_LENGTH			2048
# define COREWAR_EXEC_MAGIC		0xea83f3
# define MAGIC_SIZE				sizeof(COREWAR_EXEC_MAGIC)

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
** ===========
**  FUNCTIONS
** ===========
*/

/*
** OP.C
*/
void				print_tab(void);
void				get_op_tab(t_op *tab);

#endif
