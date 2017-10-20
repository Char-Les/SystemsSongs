#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node {
  char * song;
  char * artist;
  struct song_node * next;
}song_node;

// song_node
song_node * insert_front(song_node * node, char * name, char * artist);
song_node * insert_order(song_node * node, char * name, char * artist);
void print_songs(song_node * node);
song_node * find_song(song_node * node, char * name);
song_node * find_artist(song_node * node, char * name);
song_node * random_song(song_node * node);
void remove_song(song_node * node, song_node * toremove);
song_node * free_list(song_node *);

// playlist
void add_song(char * song, char* artist);
song_node * search_song(char * song, char* artist);
song_node * search_artist(char* artist);
void print_letter(char letter);
void print_artist(char* artist);
void print_library();
void shuffle();
void delete_song(char* song);
void delete_all();
