DEPS=main.o movement.o communication.o mapping.o


1DM1103_20Z_projekt: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic -lcurl

%.o:%.c
	cc -c $^ -o $@


clean:
	rm -f main
	rm -f *.o

test: main
	./main 1 2 3