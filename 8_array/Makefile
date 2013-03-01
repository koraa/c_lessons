TARG=$(shell readlink -f . | grep -oPi '[^/._]*(?=[^/_]*)$$')

run: compile
	./$(TARG)

compile:
	gcc -Wall -o $(TARG) -std=gnu99 *.c

clean:
	rm $(TARG)
