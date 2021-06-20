all:sanJuan.o card.o print.o
	gcc main.c sanJuan.o card.o print.o -o play
sanJuan:
	gcc -c sanJuan.c -o sanJuan.o
card:
	gcc -c card.c -o card.o
print:
	gcc -c print.c -o print.o
clean:
	rm -rf *.o play