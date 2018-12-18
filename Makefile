all: checker

basegame.o: basegame.c
	gccx -c basegame.c

checkmove.o: checkmove.c
	gccx -c checkmove.c

movepiece.o: movepiece.c
	gccx -c movepiece.c

checkjump.o: checkjump.c
	gccx -c checkjump.c

movelist.o: movelist.c
	gccx -c movelist.c

makenode.o: makenode.c
	gccx -c makenode.c

gametree.o: gametree.c
	gccx -c gametree.c

checker: basegame.o checkmove.o movepiece.o checkjump.o movelist.o makenode.o gametree.o checker.c
	gccx -o checker basegame.o checkmove.o movepiece.o checkjump.o movelist.o makenode.o gametree.o checker.c

clean: 
	rm -f *.o checker

cleanlog: 
	rm -f *.o checker gamelog .c*
