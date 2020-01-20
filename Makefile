.PHONY: clean fclean lfc $(CLEAR) asm_bin corewar_bin
.SILENT:

CLEAR = clear

DEBUG = 0

ifeq ($(DEBUG), 1)
	CFLAGS = DEBUG=1
else
	CFLAGS =
endif

all: corewar_bin asm_bin

corewar_bin:
	make $(CFLAGS) -C vm

asm_bin:
	make $(CFLAGS) -C asm_dir

$(CLEAR):
	$@

clean:
	make clean -C vm ; make clean -C asm_dir

fclean:
	make fclean -C vm ; make fclean -C asm_dir

lfc:
	make fclean -C libft

re: $(CLEAR) fclean all
