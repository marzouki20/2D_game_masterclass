prog:main.o image.o menu.o
	gcc main.o image.o menu.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer 
main.o:main.c
	gcc -c main.c -g
image.o:image.c
	gcc -c image.c -g
menu.o:menu.c
	gcc -c menu.c -g
	
