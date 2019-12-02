.PHONY: clean fclean lfc $(CLEAR) asm_bin corewar_bin

CLEAR = clear

all: corewar_bin asm_bin

corewar_bin:
	make -C vm

asm_bin:
	make -C asm_dir

$(CLEAR):
	@$@

clean:
	make clean -C vm ; make clean -C asm_dir

fclean:
	make fclean -C vm ; make fclean -C asm_dir

lfc:
	make fclean -C libft

re: fclean all
