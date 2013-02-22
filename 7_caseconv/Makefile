TARG=$(shell readlink -f . | grep -oPi '[^/._]*(?=[^/_]*)$$')

run: compile
	./$(TARG)<linecnt.c

compile:
	gcc -o $(TARG) -std=c99 *.c
