DEPS=main.o movement.o communication.o mapping.o


1DM1103_20Z_projekt: $(DEPS)
	cc $(DEPS) -o $@ -Wall --pedantic -lcurl ~/laby/cJSON/cJSON.o

%.o:%.c
	cc -c $^ -o $@


clean:
	rm -f main
	rm -f *.o

test: main
	./main E M E