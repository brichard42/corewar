# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 14:37:23 by plaurent          #+#    #+#              #
#    Updated: 2020/01/21 17:47:26 by tlandema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                 BUILD TARGETS                                #
#------------------------------------------------------------------------------#

NAME = ../$(BINARY)
BINARY = corewar

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

LIBS += $(addprefix $(LIB_PATH), $(LIB_FILES))

#------------------------------------------------------------------------------#
#                                   LIB_FILES                                  #
#------------------------------------------------------------------------------#

LIB_FILES += libft.a

LIB_DWN += sdl2 sdl2_image sdl2_mixer sdl2_ttf

#------------------------------------------------------------------------------#
#                                   SRCS_FILES                                 #
#------------------------------------------------------------------------------#

SRCS += timer.c
SRCS += window.c
SRCS += main_visu.c
SRCS += draw_text.c
SRCS += draw_image.c
SRCS +=	draw_arena.c
SRCS +=	main_drawer.c
SRCS += draw_infos.c
SRCS += draw_infos2.c
SRCS +=	draw_corewar.c
SRCS +=	draw_champions.c
SRCS +=	draw_champions2.c
SRCS +=	object_creation.c
SRCS +=	draw_rectangles.c
SRCS +=	draw_final_arena.c
SRCS +=	draw_process_list.c
SRCS +=	draw_command_panel.c
SRCS +=	draw_arena_helpers.c
SRCS += draw_process_helper.c	

SRCS += chp_num_utils.c

SRCS += main.c
SRCS += show_mem.c

SRCS += vm_parser.c

SRCS += get_opt.c
SRCS += get_dump.c
SRCS += get_chpnum.c
SRCS += get_champ.c
SRCS += get_verb.c

SRCS += padding_is_good.c

SRCS += read_champ.c

SRCS += load_memory.c
SRCS += caller.c

SRCS += parsing_error.c

SRCS += cycle.c
SRCS += winner.c
SRCS += check_cycle_to_die.c
SRCS += kill_processes.c
SRCS += check_ocp.c
SRCS += move_pc.c

SRCS += op.c

SRCS += create_op.c
SRCS += parse_op.c
SRCS += get_indirecte.c
SRCS += show_op.c

SRCS += add.c
SRCS += aff.c
SRCS += and.c
SRCS += fork.c
SRCS += ld.c
SRCS += ldi.c
SRCS += lfork.c
SRCS += live.c
SRCS += lld.c
SRCS += lldi.c
SRCS += or.c
SRCS += st.c
SRCS += sti.c
SRCS += sub.c
SRCS += xor.c
SRCS += zjump.c

SRCS += init_vm.c
SRCS += create_vm.c
SRCS += delete_vm.c

SRCS += init_process.c
SRCS += create_process.c
SRCS += delete_process.c
SRCS += free_process.c
SRCS += free_process_list.c
SRCS += copy_process.c 

#------------------------------------------------------------------------------#
#                                  DIRECTORIES                                 #
#------------------------------------------------------------------------------#

INC_DIR += includes/

OBJS_DIR += obj/

SRCS_DIR += $(shell find srcs -type d)

LIB_DIR += ../libft

#------------------------------------------------------------------------------#
#                                     PATHS                                    #
#------------------------------------------------------------------------------#

INC_PATH += ../$(INC_DIR)
INC_PATH += $(addsuffix $(INC_DIR), $(LIB_DIR)/)

OBJS_PATH = $(OBJS_DIR)

SRCS_PATH += $(SRCS_DIR)

LIB_DWN_PATH = ~/.brew/lib

LIB_PATH += $(LIB_DIR)
LIB_PATH += ~/.brew/lib

#------------------------------------------------------------------------------#
#                                     VPATH                                    #
#------------------------------------------------------------------------------#
vpath %.h $(INC_PATH)
vpath %.c $(SRCS_PATH)

#------------------------------------------------------------------------------#
#                                  COMPILATION                                 #
#------------------------------------------------------------------------------#

CC = gcc

DEBUG = 0

DWL = brew

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
else
	CFLAGS += -Werror -Wall -Wextra
endif

IFLAGS += $(addprefix -I, $(INC_PATH)) $(foreach dir, $(shell find ~/.brew/include -type d), -I$(dir))

LDLIBS = ft sdl2 sdl2_image sdl2_mixer sdl2_ttf

LDFLAGS = $(addprefix -L , $(LIB_PATH)) $(addprefix -l, $(LDLIBS))


#------------------------------------------------------------------------------#
#                                   COMMANDS                                   #
#------------------------------------------------------------------------------#

CLEAR = clear

MKDIR = mkdir -p

RM = rm -rf

#------------------------------------------------------------------------------#
#                                    CLEAN                                     #
#------------------------------------------------------------------------------#

CLEAN_LIB += $(addprefix make clean -C , $(LIB_PATH))

FCLEAN_LIB += $(addprefix make fclean -C , $(LIB_PATH))

#------------------------------------------------------------------------------#
#                                    OUTPUT                                    #
#------------------------------------------------------------------------------#

# COLORS
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

#STRINGS
BIN_STRING	= Binary
DEL_STRING	= Deleted.
CREA_STRING	= Created.
COM_STRING	= Compiled.

#------------------------------------------------------------------------------#
#                                   COMMANDS                                   #
#------------------------------------------------------------------------------#

.PHONY: all fclean re install norme show
.SILENT:

all: $(NAME)

$(NAME): $(LIBS) $(OBJS_PATH) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(IFLAGS) $(LDFLAGS) -o $@
	printf "%-20b%-60b%b" "$(BINARY):" "$(GREEN)$(BIN_STRING)" "$(COM_STRING)$(RESET)\n"

$(OBJS_PATH)%.o : %.c | Makefile
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	printf "%-20b%-60b%b" "$(BINARY):" "$(GREEN)$@" "$(CREA_STRING)$(RESET)\r"

$(OBJS_PATH):
	$(MKDIR) $@
	printf "%-20b%-60b%b" "$(BINARY):" "$(GREEN)$(OBJS_PATH)" "$(CREA_STRING)$(RESET)\n"

$(CLEAR):
	$@

$(LIBS):
	make -C $(LIB_DIR)

install:
	$(foreach lib, $(LIB_DWN), $(DWL) install $(lib); )

norme:
	norminette $(SRCS_PATH) $(INC_PATH) | grep -v 'Warning: Not a valid file' | grep -B 1 -e 'Error' -e 'Warning'

clean: 
	$(RM) $(OBJS_PATH)
	printf "%-20b%-60b%b" "$(BINARY):" "$(RED)$(OBJS_PATH)" "$(DEL_STRING)$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "%-20b%-60b%b" "$(BINARY):" "$(RED)$(BIN_STRING)" "$(DEL_STRING)$(RESET)\n"

re: fclean all
