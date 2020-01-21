# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by brichard          #+#    #+#              #
#    Updated: 2020/01/21 16:14:34 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                   VARIABLES                                  #
################################################################################

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes

SRCS_PATH = srcs
PRINTF_SRCS_PATH = srcs/ft_printf

OBJS_PATH = obj
PRINTF_OBJS_PATH = $(OBJS_PATH)

OBJS = $(SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS))
D_PRINTF_OBJS = $(addprefix $(PRINTF_OBJS_PATH)/, $(PRINTF_OBJS))

################################################################################
#                                    SOURCES                                   #
################################################################################

PRINTF_SRCS =	ft_printf.c \
				utils.c \
				exf_tab_maker.c \
				bonus.c \
				ex_cfun.c \
				ex_cfun_2.c \
				prefwp_fun.c \
				ex_floats.c \
				get_length.c \
				get_int.c \
				get_floats.c \
				get_hex_oct.c \
				parsing.c \
				parsing_ffun.c \


SRCS =			ft_strlen.c \
				ft_exit_malloc.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_strdup.c \
				ft_strndup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strchr.c \
				ft_strnchr.c \
				ft_strrchr.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_realloc.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
\
				ft_atoi.c \
				ft_atol.c \
				ft_lltoa.c \
				ft_ftoa_u.c \
				ft_ulltoa_ubase.c \
				ft_get_num_size.c \
\
				ft_pow_ldo.c \
\
				get_next_line.c \
				ft_gnl.c \
\
				ft_isupper.c \
				ft_islower.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
\
				ft_toupper.c \
				ft_tolower.c \
\
				ft_printf.c \
\
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_print_tab.c \
				ft_putnbr_base.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
\
				ft_bzero.c \
				ft_memcmp.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_memjoin.c \
				ft_int_realloc.c \
\
				ft_lstnew.c \
				ft_lstmap.c \
				ft_lstfind.c \
				ft_lstnelem.c \
				ft_lstlen.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstapp.c \
				ft_lstswap.c \
				ft_del_cont.c \
				ft_quicksort.c\
\
				ft_strcheck.c\
				ft_isspace.c\
				ft_splitwhite.c\
				ft_freetabsplit.c\
				ft_str_is_numeric.c

################################################################################
#                                    COlORS                                    #
################################################################################

# COLORS
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

#STRINGS
BIN_STRING	= Binary
DEL_STRING	= Deleted.
CREA_STRING	= Created.
COM_STRING	= Compiled.

################################################################################
#                                   COMMANDS                                   #
################################################################################

.PHONY: all clean fclean re
.SILENT:

all: $(NAME)
	#echo > /dev/null

$(NAME): $(OBJS_PATH) $(INC) $(D_PRINTF_OBJS) $(D_OBJS)
	ar -rc $(NAME) $(D_OBJS) $(D_PRINTF_OBJS) $@
	ranlib $(NAME)
	printf "%-20b%-60b%b" "$(NAME):" "$(GREEN)$@" "$(COM_STRING)$(RESET)\n"

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)
	printf "%-20b%-60b%b" "$(NAME):" "$(GREEN)$@" "$(CREA_STRING)$(RESET)\r"

$(PRINTF_OBJS_PATH)/%.o: $(PRINTF_SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)
	printf "%-20b%-60b%b" "$(NAME):" "$(GREEN)$@" "$(CREA_STRING)$(RESET)\r"

$(OBJS_PATH):
	mkdir -p $@

clean:
	rm -f $(D_OBJS) && rm -rf $(OBJS_PATH)
	printf "%-20b%-60b%b" "$(NAME):" "$(RED)$(BIN_STRING)" "$(DEL_STRING)$(RESET)\n"

fclean: clean
	rm -f $(NAME)
	printf "%-20b%-60b%b" "$(NAME):" "$(RED)$(OBJS_PATH)" "$(DEL_STRING)$(RESET)\n"

re: fclean all
