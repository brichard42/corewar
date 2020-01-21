# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2020/01/21 16:05:02 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                 BUILD TARGETS                                #
#------------------------------------------------------------------------------#

NAME = ../$(BINARY)
BINARY = asm

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

LIBS += $(addprefix $(LIB_PATH), $(LIB_FILES))

#------------------------------------------------------------------------------#
#                                   LIB_FILES                                  #
#------------------------------------------------------------------------------#

LIB_FILES +=

#------------------------------------------------------------------------------#
#                                   SRCS_FILES                                 #
#------------------------------------------------------------------------------#

SRCS += main.c
SRCS += op.c
SRCS += error.c
SRCS += list_tools.c
SRCS += read_file.c
SRCS += get_header.c
SRCS += get_label.c
SRCS += get_op.c
SRCS += get_params.c
SRCS += check_params.c
SRCS += check_params_2.c
SRCS += check_labels.c
SRCS += check_types.c
SRCS += write_tools.c
SRCS += write_file.c

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

INC_PATH += ./$(INC_DIR)
INC_PATH += $(addsuffix $(INC_DIR), $(LIB_DIR)/)

OBJS_PATH = $(OBJS_DIR)

SRCS_PATH += $(SRCS_DIR)

LIB_PATH += $(LIB_DIR)

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

ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -g3
endif

IFLAGS += $(addprefix -I, $(INC_PATH))

LDLIBS = ft

LDFLAGS = $(addprefix -L , $(LIB_PATH)) $(addprefix -l, $(LDLIBS))

CFLAGS += -Werror -Wall -Wextra

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

.PHONY: all $(CLEAR) lc lfc clean fclean re install norme show
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

norme:
	norminette $(SRCS_PATH) $(INC_PATH) | grep -v 'Warning: Not a valid file' | grep -B 1 -e 'Error' -e 'Warning'

clean: 
	$(RM) $(OBJS_PATH)
	printf "%-20b%-60b%b" "$(BINARY):" "$(RED)$(OBJS_PATH)" "$(DEL_STRING)$(RESET)\n"

fclean: clean
	$(RM) $(NAME)
	printf "%-20b%-60b%b" "$(BINARY):" "$(RED)$(BIN_STRING)" "$(DEL_STRING)$(RESET)\n"

re: fclean all
