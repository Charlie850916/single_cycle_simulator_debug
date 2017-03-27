single_cycle: main.o Setting.o R_type.o I_type.o Decode.o ErrorMsg.o
	gcc -o single_cycle main.o Setting.o R_type.o I_type.o Decode.o ErrorMsg.o
main.o: main.c
	gcc -c main.c
Setting.o: Setting.c
	gcc -c Setting.c
R_type.o: R_type.c
	gcc -c R_type.c
I_type.o: I_type.c
	gcc -c I_type.c
Decode.o: Decode.c
	gcc -c Decode.c
ErrorMsg.o: ErrorMsg.c
	gcc -c ErrorMsg.c

clean:
	-rm *.o
