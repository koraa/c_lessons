TARG=$(shell readlink -f . | grep -oPi '[^/._]*(?=[^/_]*)$$')

run: compile
	./$(TARG)

compile:
	gcc -o $(TARG) -std=c99 *.c

clean:
	rm $(TARG)
