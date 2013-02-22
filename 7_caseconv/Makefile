TARG=$(shell readlink -f . | grep -oPi '[^/._]*(?=[^/_]*)$$')

run: compile
	ls | grep -iP '\.(c|h)(pp)?$$' | xargs cat | ./$(TARG)

compile:
	gcc -o $(TARG) -std=c99 *.c

clean:
	rm $(TARG)
