OBJECTS = main.o dist.o funs.o funsetter.o
CFLAGS = -g
LIBS = -lgsl -lgslcblas
BINARY = dist

$(BINARY): $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(BINARY)

clean:
	rm $(BINARY) $(OBJECTS)

.PHONEY: clean
