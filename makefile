# test: test.c dist.o funs.o funsetter.c
# 	gcc -g -lgsl -lgslcblas $^ -o test

stat: main.o dist.o funs.o funsetter.c
	gcc -g -lgsl -lgslcblas $^ -o stat

%.o: %.c
	gcc -g -c $^

clean:
	rm *.o stat
