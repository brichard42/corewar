/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:08:18 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/16 14:38:09 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define THE_END		3
# define CONTINUE		1
# define TO_START		0
# define PAUSED			1
# define ACTIVE			2
# define FONT_PATH 		"vm/ressources/font/Tinos-Regular.ttf"
# define NB_SIZE		150
# define NB_COLOR		26
# define NB_STYLE		5
# define BLACK			0
# define WHITE			1
# define LIGHT_BLUE		2
# define BLUE			3
# define DARK_BLUE		4
# define LIGHT_RED		5
# define RED			6
# define DARK_RED		7
# define LIGHT_GREEN	8
# define GREEN			9
# define DARK_GREEN		10
# define LIGHT_CYAN		11
# define CYAN			12
# define DARK_CYAN		13
# define LIGHT_GREY		14
# define GREY			15
# define DARK_GREY		16
# define ORANGE			17
# define TEXT2			18
# define CHAMP_1		19
# define CHAMP_2		20
# define CHAMP_3		21
# define CHAMP_4		22
# define LIGHT_ORANGE	23
# define BORDER			24
# define TEXT			25

# define NORMAL TTF_STYLE_NORMAL
# define BOLD TTF_STYLE_BOLD
# define ITALIC TTF_STYLE_ITALIC
# define UNDERLINE TTF_STYLE_UNDERLINE
# define STRICK TTF_STYLE_STRIKETHROUGH

/*
**	--------WINDOW FUNCTIONS----------------------------------------------------
*/
t_window 			*open_window(char *name);
void 				clear(t_window *win);
void				render(t_window *win);
int8_t				drawer(t_window *win, t_vm *env);
void				time_dealer(t_draw *infos, uint8_t plus_minus);

/*
**	--------OBJECT CREATION FUNCTIONS-------------------------------------------
*/
SDL_Rect			create_rect(int x, int y, int w, int h);
SDL_Color			create_color(int r, int g, int b, int a);
SDL_Point			create_point(int x, int y);
int8_t				create_tab_int3(int *dest, int size, int color, int style);
t_image				load_t_image(t_window *win, SDL_Surface *p_surface);
t_image				*malloc_t_image(t_window *win, SDL_Surface *p_surface);
t_image				load_t_image_from_file(t_window *win, char *path);

/*
**	--------GENERIC DRAWING FUNCTIONS-------------------------------------------
*/
int8_t				main_visu(t_vm	*env);
int8_t				draw_image(t_window *win, t_image *image, SDL_Rect dest);
int8_t				draw_rectangle(t_window *win, SDL_Rect rect, SDL_Color color);
int8_t				draw_centred_rectangle(t_window *win, SDL_Rect rect, SDL_Color color);
int8_t				draw_border_rectangle(t_window *win, t_brect *infos,
					int border);
int8_t				draw_centred_border_rectangle(t_window *win, t_brect *infos,
					int border);
int					draw_text(t_window *win, char *str, SDL_Point pos,
					int infos[3]);
int					draw_centred_text(t_window *win, char *str, SDL_Point pos,
					int infos[3]);

/*
**	--------SPECIFIC DRAWING FUNCTIONS------------------------------------------
*/
int8_t				draw_command_panel(t_window *win, int i);
char				*action_name(int op_code);
int8_t              draw_arena(t_window *win, t_vm *env, t_draw infos);
int8_t              draw_structure_sides(t_window *win);
int8_t				draw_champions(t_window *win, t_vm *env, int champ_n);
int8_t				draw_last_live(t_window *win, int last_live,
					SDL_Point point, int text[3]);
int8_t				draw_champion_name(t_window *win, char *name,
					SDL_Point point, int test[3]);
int8_t				draw_corewar(t_window *win);
int8_t				draw_procs_pannel(t_window *win, t_vm *env, t_draw infos,
					t_process *process_list);
int32_t				draw_process_pos(t_window *win, t_process *proc,
					int text[3], SDL_Point point);
int32_t				draw_process_num(t_window *win, t_process *proc,
					int text[3], SDL_Point point);
int8_t				draw_infos(t_window *win, t_vm *env, t_draw infos);
int8_t				underliner(t_window *win, t_vm *env);

#endif
