OBJECTS = main.o dist.o funs.o funsetter.o
CFLAGS = -g
LIBS = -lgsl -lgslcblas
BINARY = dist

$(BINARY): $(OBJECTS) utils.h
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(BINARY)

funsetter.o: funsetter.c utils.h

clean:
	rm $(BINARY) $(OBJECTS)

.PHONEY: clean
