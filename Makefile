.PHONY: clean fclean lfc $(CLEAR) asm_bin corewar_bin
.SILENT:

CLEAR = clear

DEBUG = 0

ifeq ($(DEBUG), 1)
	CFLAGS = DEBUG=1
else
	CFLAGS =
endif

LIB_FILES += libft.a

LIB_DIR += $(basename $(LIB_FILES))

LIB_PATH += $(LIB_DIR)

LIBS += $(addprefix $(LIB_PATH), $(LIB_FILES))

all: corewar_bin asm_bin

corewar_bin: $(LIBS)
	make $(CFLAGS) -C vm

asm_bin: $(LIBS)
	make $(CFLAGS) -C asm_dir

$(LIBS):
	make -C $(LIB_PATH)

$(CLEAR):
	$@

clean: $(CLEAR) 
	make clean -C vm ; make clean -C asm_dir

fclean: $(CLEAR) 
	make fclean -C vm ; make fclean -C asm_dir

lfc: fclean
	make fclean -C libft

re: fclean all

lre: lfc re
