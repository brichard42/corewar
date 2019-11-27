# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 14:37:23 by plaurent          #+#    #+#              #
#    Updated: 2019/11/27 16:43:45 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                 BUILD TARGETS                                #
#------------------------------------------------------------------------------#

NAME = ../asm

OBJS = $(patsubst %.c, $(OBJS_PATH)%.o, $(SRCS))

LIBS += $(addprefix $(LIB_PATH), $(LIB_FILES))

#------------------------------------------------------------------------------#
#                                   LIB_FILES                                  #
#------------------------------------------------------------------------------#

LIB_FILES += libft.a

#------------------------------------------------------------------------------#
#                                   INC_FILES                                  #
#------------------------------------------------------------------------------#

INC_FILES += 

#------------------------------------------------------------------------------#
#                                   SRCS_FILES                                 #
#------------------------------------------------------------------------------#

SRCS += main.c

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

INC_PATH += $(INC_DIR)
INC_PATH += $(addsuffix $(INC_DIR), $(LIB_DIR)/)

OBJS_PATH = $(OBJS_DIR)

SRCS_PATH += $(SRCS_DIR)

LIB_PATH += $(LIB_DIR)

#------------------------------------------------------------------------------#
#                                     VPATH                                    #
#------------------------------------------------------------------------------#

vpath %.c $(SRCS_PATH)
vpath %.h $(INC_PATH)

#------------------------------------------------------------------------------#
#                                  COMPILATION                                 #
#------------------------------------------------------------------------------#

CC = gcc

DEBUG += $(CFLAGS)
DEBUG += -fsanitize=address,undefined
DEBUG += -g3

IFLAGS += $(addprefix -I, $(INC_PATH))

LDFLAGS = $(addprefix -L , $(LIB_PATH))

LDLIBS = -lft

CFLAGS += -Werror
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += $(IFLAGS)

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

.PHONY: all $(NAME) $(OBJS_PATH) $(CLEAR) lc lfc clean fclean re
.SILENT:

all: $(NAME)

$(NAME): $(LIBS) $(OBJS_PATH) $(OBJS)
	$(call run_and_test, $(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $@)

$(OBJS_PATH)%.o : %.c $(INCS) Makefile
	$(call run_and_test, $(CC) $(CFLAGS) -c $< -o $@)

$(OBJS_PATH):
	$(MKDIR) $@

$(LIBS):
	echo "$(COM_COLOR)Compiling $(OBJ_COLOR)Libraries$(NO_COLOR)"
	make -C $(LIB_PATH)

$(CLEAR):
	$@

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
