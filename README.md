# Corewar 

## Pitch


Corewar is a pedagogical project from 42 School which aims to introduce the students to Virtual Machines and assembler.  
In this project, you create a virtual “arena” in which programs will fight against one another (the “Champions”). You also create an assembler to compile
those Champions as well as a Champione.

## Main features

- Compile asm from file in .s to file in .cor
- Emulate a virtual machine
- Run programs and processus until the last process die

## Things I have learned

- Better understanding of the C programming language and how to structure the code to keep a growing program maintanable, and open to new features.
- Mecanism of a CPU.
- Working in groups, being well organized with github as tool.
- Use of a state-machine as parser.


## Compile and run

Start compiling using make.
</br>
Then run './asm \<file.s\>' using the champs file in test_champs.
</br>
You can then run './corewar \<file.cor\>' using --visual for visualiser
</br>
example :
	
	make
	./asm test_champs/champs/42.s
	./corewar --visual test_champs/champs/42.cor test_champs/champs/42.cor
