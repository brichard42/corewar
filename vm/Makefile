.PHONY: vm asm clean fclean lfc

CLEAR = clear

all: $(CLEAR) vm asm

vm:
	make -C vm

asm:
	make -C asm_dir

$(CLEAR):
	$@

clean:
	make clean -C vm ; make clean -C asm_dir

fclean:
	make fclean -C vm ; make fclean -C asm_dir

lfc:
	make fclean -C libft

re: fclean all
