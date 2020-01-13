/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:39:25 by armoulin          #+#    #+#             */
/*   Updated: 2019/10/11 16:43:25 by armoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

#include "op.h"

/*
** =======================
**  INSTRUCTION STRUCTURE
** =======================
*/
typedef struct 		s_param
{
	char			*str;
	int 			type;
	int 			value;
	char 			*temp;
}					t_param;

/*
** =======================
**  INSTRUCTION STRUCTURE
** =======================
*/
typedef struct		s_cmd t_cmd;
typedef struct		s_cmd
{
	int				op_code;
	char			*label;
	t_param			params[MAX_ARGS_NUMBER];
	int 			nb_param;
	size_t			size;
	size_t			nb_line;
	t_cmd			*next;
}					t_cmd;

/*
** =====================
**  ASSEMBLER STRUCTURE
** =====================
*/
typedef struct		s_asm
{
	t_op			op_tab[16];
	t_header		header;
	t_bool			is_name;
	int 			i_name;
	t_bool			got_name;
	t_bool			is_comment;
	int 			i_comment;
	t_bool			got_comment;
	char			*label;
	size_t 			label_size;
	size_t			nb_line;
	t_cmd			*list;
}					t_asm;

#endif