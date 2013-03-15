TARG=$(shell readlink -f . | grep -oPi '[^/._]*(?=[^/_]*)$$')
GCC_COMMON=-Wall -o $(TARG) -std=gnu99 *.c

run: compile
	./$(TARG)

debug:
	gcc $(GCC_COMMON) -g -O0
	gdb $(TARG)

compile:
	gcc $(GCC_COMMON)

clean:
	rm $(TARG)
