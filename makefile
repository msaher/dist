stat: main.o dist.o funs.o
	gcc -lgsl -lgslcblas $^ -o stat

%.o: %.c
	gcc -c $^
