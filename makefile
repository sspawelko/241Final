TARGETS=checkers

all: $(TARGETS)

checkers: temp_checker.c
	gccx -o checkers temp_checker.c

clean: 
	rm -f *.o $(TARGETS)

