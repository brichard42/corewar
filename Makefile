.PHONY: vm asm clean fclean lfc

all: vm asm

vm:
	make -C vm

asm:
	make -C asm_dir

clean:
	make clean -C vm ; make clean -C asm_dir

fclean:
	make fclean -C vm ; make fclean -C asm_dir

lfc:
	make fclean -C libft

re:
	make re -C vm ; make re -C asm_dir
