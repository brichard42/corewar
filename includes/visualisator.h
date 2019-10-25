#ifndef TEST_H
#define TEST_H

#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

typedef struct s_window
{
	int x;
	int y;

	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
}				t_window;

typedef struct s_image
{
	SDL_Surface *surface;
	SDL_Texture *texture;
}				t_image;

#define FONT_PATH "vm/ressources/font/Tinos-Regular.ttf"

#define NB_SIZE			150
#define NB_COLOR		26
#define NB_STYLE		5

#define BLACK			0
#define WHITE			1
#define LIGHT_BLUE		2
#define BLUE			3
#define DARK_BLUE		4
#define LIGHT_RED		5
#define RED				6
#define DARK_RED		7
#define LIGHT_GREEN		8
#define GREEN			9
#define DARK_GREEN		10
#define LIGHT_CYAN		11
#define CYAN			12
#define DARK_CYAN		13
#define LIGHT_GREY		14
#define GREY			15
#define DARK_GREY		16
#define LIGHT_ORANGE	17
#define ORANGE			18
#define DARK_ORANGE		19
#define LIGHT_YELLOW	20
#define YELLOW			21
#define DARK_YELLOW		22
#define LIGHT_PURPLE	23
#define PURPLE			24
#define DARK_PURPLE		25

#define NORMAL TTF_STYLE_NORMAL
#define BOLD TTF_STYLE_BOLD
#define ITALIC TTF_STYLE_ITALIC
#define UNDERLINE TTF_STYLE_UNDERLINE
#define STRICK TTF_STYLE_STRIKETHROUGH

t_window *open_window(char *name);
void clear(t_window *win);
void render(t_window *win);
void handle_event(t_window *win);
SDL_Rect create_rect(int x, int y, int w, int h);
SDL_Color create_color(int r, int g, int b, int a);
SDL_Point create_point(int x, int y);
void draw_rectangle(t_window *win, SDL_Rect rect, SDL_Color color);
void draw_centred_rectangle(t_window *win, SDL_Rect rect, SDL_Color color);
void draw_border_rectangle(t_window *win, SDL_Rect rect, SDL_Color color_back, SDL_Color color_front, int border);
void draw_centred_border_rectangle(t_window *win, SDL_Rect rect, SDL_Color color_back, SDL_Color color_front, int border);
t_image load_t_image(t_window *win, SDL_Surface *p_surface);
t_image *malloc_t_image(t_window *win, SDL_Surface *p_surface);
t_image load_t_image_from_file(t_window *win, char *path);
void draw_image(t_window *win, t_image *image, SDL_Rect dest);
int draw_text(t_window *win, char *str, SDL_Point pos, int size, int color_index, int style_index);
int	draw_centred_text(t_window *win, char *str, SDL_Point pos, int size, int color_index, int style_index);

#endif
