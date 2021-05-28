all:sanJuan.o print.o
	gcc main.c sanJuan.o print.o -o main
sanJuan:
	gcc -c sanJuan.c -o sanJuan.o
print:
	gcc -c print.c -o print.o
clean:
	rm -rf *.o main