# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2019/10/11 15:17:17 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                 BUILD TARGETS                                #
#------------------------------------------------------------------------------#

NAME = ../asm

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

LIBS += $(addprefix $(LIB_PATH), $(LIB_FILES))

#------------------------------------------------------------------------------#
#                                   LIB_FILES                                  #
#------------------------------------------------------------------------------#

LIB_FILES += libftprintf.a

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
SRCS += check_labels.c
SRCS += check_params.c
SRCS += check_types.c
SRCS += write_file.c

#------------------------------------------------------------------------------#
#                                  DIRECTORIES                                 #
#------------------------------------------------------------------------------#

INC_DIR += includes/

OBJS_DIR += bin/

SRCS_DIR += $(shell find srcs -type d)

LIB_DIR += ft_printf

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

LDLIBS = ftprintf

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

.PHONY: all $(CLEAR) lc lfc clean fclean re install norme show
.SILENT:

all: $(NAME)

$(NAME): $(LIBS) $(OBJS_PATH) $(OBJS)
	$(call run_and_test, $(CC) $(OBJS) $(CFLAGS) $(IFLAGS) $(LDFLAGS) -o $@)

$(OBJS_PATH)%.o : %.c | Makefile
	$(call run_and_test, $(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@)

$(OBJS_PATH):
	$(MKDIR) $@

$(LIBS):
	echo "$(COM_COLOR)Compiling $(OBJ_COLOR)Libraries$(NO_COLOR)"
	make -C $(LIB_DIR)

$(CLEAR):
	$@

show:
	echo "IFLAGS : \n$(IFLAGS)"
	echo "CFLAGS : \n$(CFLAGS)"
	echo "LDFLAGS : \n$(LDFLAGS)"
	echo "OBJS : \n$(OBJS)"
	echo "INC_PATH : \n$(INC_PATH)"

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