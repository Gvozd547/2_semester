main : main.c  ./mqv/2_step/*.c ./salsa/*.c ./gost3411-2012/*.c
	gcc main.c ./mqv/2_step/gen_number.c ./mqv/2_step/get_data.c ./salsa/salsa20.c ./gost3411-2012/gost3411-2012-core.c -o main -lgmp
run:
	./main
