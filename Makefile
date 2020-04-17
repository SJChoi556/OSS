myProgram : base.o extras.o main.o
	gcc -o myProgram base.o extras.o main.o

base.o: base.c
	gcc -c -o base.o base.c

extras.o: extras.c
	gcc -c -o extras.o extras.c

main.o: main.c
	gcc -c -o main.o main.c

clean:
	rm myProgram extras.o base.o main.o
