Changer:macChanger.c
	clang -o changer.o macChanger.c


Changer2:macchanger2.c
	clang -o changer2.o macchanger2.c

clean: 
	rm -rf *.o
