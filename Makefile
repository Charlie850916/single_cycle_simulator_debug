single_cycle: main.o Setting.o R_type.o I_type.o Decode.o ErrorMsg.o
	gcc -O3 -o single_cycle main.o Setting.o R_type.o I_type.o Decode.o ErrorMsg.o
%.o: %.c
	gcc -O3 -c $^

clean:
	rm -f *.o
