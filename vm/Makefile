# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 14:37:23 by plaurent          #+#    #+#              #
#    Updated: 2019/11/11 17:57:03 by tlandema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                 BUILD TARGETS                                #
#------------------------------------------------------------------------------#

NAME = ../corewar

OBJS = $(patsubst %.c, $(OBJS_PATH)%.o, $(SRCS))

LIBS += $(addprefix $(LIB_PATH), $(LIB_FILES))

#------------------------------------------------------------------------------#
#                                   LIB_FILES                                  #
#------------------------------------------------------------------------------#

LIB_FILES += libft.a

LIB_DWN += sdl2 sdl2_image sdl2_mixer sdl2_ttf

#------------------------------------------------------------------------------#
#                                   SRCS_FILES                                 #
#------------------------------------------------------------------------------#

SRCS += main.c \
		window.c \
		parsopt.c \
		draw_text.c \
		draw_image.c \
		draw_arena.c \
		main_drawer.c \
		draw_corewar.c \
		draw_champions.c \
		draw_process_list.c \
		object_creation.c \
		draw_rectangles.c \
		draw_command_panel.c \

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

DWL = brew

DEBUG += $(CFLAGS)
DEBUG += -fsanitize=address,undefined
DEBUG += -g3

IFLAGS += $(addprefix -I, $(INC_PATH)) $(foreach dir, $(shell find ~/.brew/include -type d), -I$(dir))

LDLIBS = ft sdl2 sdl2_image sdl2_mixer sdl2_ttf

LDFLAGS = $(addprefix -L , $(LIB_PATH)) $(addprefix -l, $(LDLIBS))

#CFLAGS += -Werror -Wall -Wextra

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

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log 2> /dev/null; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

#------------------------------------------------------------------------------#
#                                   COMMANDS                                   #
#------------------------------------------------------------------------------#

.PHONY: all $(NAME) $(OBJS) $(OBJS_PATH) $(LIBS) $(CLEAR) lc lfc clean fclean re
.SILENT:

all: $(CLEAR) $(NAME)

$(NAME): $(LIBS) $(OBJS_PATH) $(OBJS)
	$(call run_and_test, $(CC) $(OBJS) $(CFLAGS) $(IFLAGS) $(LDFLAGS) -o $@)

$(OBJS): $(OBJS_PATH)%.o : %.c $(INCS) Makefile
	$(call run_and_test, $(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@)

$(OBJS_PATH):
	$(MKDIR) $@

$(LIBS):
	echo "$(COM_COLOR)Compiling $(OBJ_COLOR)Libraries$(NO_COLOR)"
	make -C $(LIB_DIR)

$(CLEAR):
	$@

show:
	@echo "IFLAGS : \n$(IFLAGS)"
	@echo "CFLAGS : \n$(CFLAGS)"
	@echo "LDFLAGS : \n$(LDFLAGS)"

install:
	$(foreach lib, $(LIB_DWN), $(DWL) install $(lib); )

norme:
	norminette $(SRCS_PATH) $(INC_PATH) | grep -v 'Warning: Not a valid file' | grep -B 1 -e 'Error' -e 'Warning'

lc:
	$(call run_and_test, $(RM) $(OBJS_PATH) && $(CLEAN_LIB))

lfc:
	$(call run_and_test, $(RM) $(OBJS_PATH) && $(RM) $(NAME) && $(FCLEAN_LIB))

clean: $(CLEAR)
	$(call run_and_test, $(RM) $(OBJS_PATH))

fclean: $(CLEAR) clean
	$(call run_and_test, $(RM) $(NAME))

re: fclean all
