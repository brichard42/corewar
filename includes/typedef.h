/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:30:02 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/19 12:18:02 by brichard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

/*
**	-------PARSING	STATES ENUM-------------------------------------------------
*/
enum				e_state
{
	S_OPTION,
	S_DUMP,
	S_CHP_NUM,
	S_CHAMP,
	S_ERR
};

/*
**	--------TYPEDEF DRAW STRUCTURE----------------------------------------------
*/

typedef struct		s_draw
{
	int32_t			process_ind;
	int32_t			cycles_per_sec;
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
**  -------TYPEDEF PROCESS STRUCTURE--------------------------------------------
*/
typedef struct			s_process
{
    struct s_process	*next;
    struct s_process	*prev;
    int32_t				reg[REG_NUMBER];
    int32_t				pc;
    int32_t				cycles_left;
    uint8_t				carry;
}						t_process;

/*
**	-------TYPEDEF CHAMPION STRUCTURE-------
*/
typedef struct		s_champ
{
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	uint32_t		size;
	int32_t			num;
	int32_t			last_live_cycle;
}					t_champ;

/*
**	-------TYPEDEF COREWAR STRUCTURE-------
*/
typedef struct		s_vm
{
	t_process			*process_list;
	t_champ				champ[MAX_PLAYERS + 1];
	char				mem[MEM_SIZE];
	uint8_t				mem_owner[MEM_SIZE];
	uint32_t			current_cycle;
	uint32_t			cycles_to_die;
	int32_t				cycles_to_dump;
	uint8_t				champ_amount;
	uint8_t				visu;
	uint8_t				verbose;
}					t_vm;

/*
**	-------TYPEDEF PARSING STRUCTURE-------
*/
typedef struct		s_parser
{
	t_vm			env;
	enum e_state	state;
	int32_t			chp_num;
	uint8_t			cur_chp_index;
}					t_parser;

#endif
