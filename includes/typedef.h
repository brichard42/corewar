/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:30:02 by tlandema          #+#    #+#             */
/*   Updated: 2019/11/07 11:19:32 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

/*
** --------TYPEDEF BORDER RECT STRUCTURE----------------------------------------
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
**  -------TYPEDEF COREWAR STRUCTURE--------------------------------------------
*/
typedef struct          s_vm
{
    t_window			*window;
    t_process			*process_list;
    char				*champ_names[MAX_PLAYERS];
    uint32_t			cycles_to_die;
    char				mem[MEM_SIZE];
    uint8_t				visu_on;
}                       t_vm;

#endif
