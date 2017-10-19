all:
	gcc -o my_tunez.exe song_node.c heads.h main.c playlist.c

run: all
	./my_tunez.exe
