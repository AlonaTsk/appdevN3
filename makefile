OBJ = screen.o testscreen.o comm.o sound.o
APPNAME = screentest

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)

%.o : %.c
	gcc -c -o $@ $<

clean:
	rm $(APPNAME) $(OBJ)

#archiving rule
zip :
	tar cf appdev.tar *.c *.h makefile 