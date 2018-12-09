TARGETS=play

all: $(TARGETS)

initboard.o: initboard.c
	gccx -c initboard.c

printboard.o: printboard.c
	gccx -c printboard.c

checkwin.o: checkwin.c
	gccx -c checkwin.c

checkmove.o: checkmove.c
	gccx -c checkmove.c

makepromotion.o: makepromotion.c
	gccx -c makepromotion.c

movepiece.o: movepiece.c
	gccx -c movepiece.c

checkjump.o: checkjump.c
	gccx -c checkjump.c

printmovelist.o: printmovelist.c
	gccx -c printmovelist.c

printlist.o: printlist.c
	gccx -c printlist.c

movelist.o: movelist.c
	gccx -c movelist.c

makenode.o: makenode.c
	gccx -c makenode.c

printnode.o: printnode.c
	gccx -c printnode.c

setchild.o: setchild.c
	gccx -c setchild.c

play: initboard.o printboard.o checkwin.o checkmove.o makepromotion.o movepiece.o checkjump.o printmovelist.o printlist.o movelist.o makenode.o printnode.o setchild.o main.c
	gccx -o play main.c initboard.o printboard.o checkwin.o checkmove.o makepromotion.o movepiece.o checkjump.o printmovelist.o printlist.o movelist.o makenode.o printnode.o setchild.o

clean: 
	rm -f *.o $(TARGETS)
