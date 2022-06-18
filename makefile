stat: main.o dist.o funs.o
	gcc -g -lgsl -lgslcblas $^ -o stat

%.o: %.c
	gcc -g -c $^

clean:
	rm *.o stat
