/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_typedef.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brichard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:30:02 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/17 15:45:54 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

/*
**	-------ENUM PARSING	STATES-------------------------------------------------
*/
enum				e_state
{
	S_OPTION,
	S_DUMP,
	S_CHP_NUM,
	S_CHAMP,
	S_VERB,
	S_ERR
};

/*
**	--------TYPEDEF DRAW STRUCTURE----------------------------------------------
*/

typedef struct		s_draw
{
	int32_t			process_ind;
	int32_t			cycles_per_sec;
	int32_t			time;
	uint8_t			state;
	uint8_t			champ_ind;
	uint8_t			champ_number;
	uint8_t			play;
}					t_draw;

/*
**	--------TYPEDEF BORDER RECT STRUCTURE---------------------------------------
*/

typedef struct		s_brect
{
	SDL_Rect		rect;
	SDL_Color		c_front;
	SDL_Color		c_back;
}					t_brect;

/*
** -------TYPEDEF WINDOW_STRUCTURE----------------------------------------------
*/
typedef struct		s_window
{
	int				x;
	int				y;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
}					t_window;
/*
** --------TYPEDEF IMAGE STRUCTURE----------------------------------------------
*/
typedef struct		s_image
{
	SDL_Surface		*surface;	
	SDL_Texture		*texture;
}					t_image;

/*
**	-------TYPEDEF OP STRUCTURE-------------------------------------------------
*/
typedef struct s_op
{
	int32_t				param[3];
	int32_t				type_param[3];
	int32_t				op_code;
	int32_t				nb_cycle;
	int32_t				pos_op_code;
	uint8_t				active;
	unsigned char		ocp;
}				t_op;

/*
**  -------TYPEDEF PROCESS STRUCTURE--------------------------------------------
*/
typedef struct			s_process
{
    struct s_process	*next;
	t_op				op;
    int32_t				reg[REG_NUMBER + 1];
    int32_t				pc;
    int32_t				cycles_left;
	int32_t				last_live;
	int32_t				visu_num;
	int32_t				num;
    uint8_t				carry;
	uint8_t				active;
}						t_process;

/*
**	-------TYPEDEF CHAMPION STRUCTURE-------
*/
typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	char			code[CHAMP_MAX_SIZE];
	uint32_t		size;
	int32_t			num;
	int32_t			last_live_cycle;
}					t_champ;

/*
**	-------TYPEDEF COREWAR STRUCTURE-------
*/
typedef struct		s_vm
{
	t_process		*process_list;
	t_champ			champ[MAX_PLAYERS];
	t_window		*win;
	char			mem[MEM_SIZE];
	uint8_t			mem_owner[MEM_SIZE];
	int32_t			current_cycle;
	int32_t			current_sub_cycle;
	int32_t			cycle_to_dump;
	int32_t			cycle_to_die;
	uint32_t		live_count;
	uint32_t		live_check_count;
	uint8_t			champ_amount;
	uint8_t			verbose;
	uint8_t			winner_index;
}					t_vm;

/*
**	-------TYPEDEF PARSING STRUCTURE-------
*/
typedef struct		s_parser
{
	t_vm			env;
	uint8_t			flag_n[4];
	enum e_state	state;
	uint8_t			chp_num;
	uint8_t			cur_chp_index;
	uint8_t			visu;
}					t_parser;

/*
 **	-------TYPEDEF OP_TAB FUNCTIONS-------
 */
typedef struct		s_op_tab
{
	char			*name;
	void			(*func)(t_vm *vm, t_process *process);
	uint32_t		nb_param;
	int32_t			type_param[3];
	int32_t			op_code;
	int32_t			nb_cycle;
	char			*com;
	int32_t			bytecode;
	int32_t			direct_size;
}					t_op_tab;

/*
**	-------TYPEDEF PROCESS APPLY FUNC-------------------------------------------------
*/
typedef void		(*t_proc_apply)(t_vm*, t_process **);

/*
**	-------TYPEDEF ARG_PARSER FUNCTIONS-------
*/
typedef void		(*t_get_func)(t_parser *, char **);

/*
**	-------TYPEDEF READ_CHAMP.C FUNCTIONS---------------------------------------
*/

typedef void		(*t_read_func)(t_parser *, int32_t);

extern t_op_tab		g_op_tab[17];

#endif
