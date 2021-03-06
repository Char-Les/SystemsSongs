#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct song_node {
  char * song;
  char * artist;
  struct song_node * next;
}song_node;

// song_node
song_node * insert_front(song_node * node, char * name, char * artist);
song_node * insert_order(song_node * node, char * name, char * artist);
void print_song(song_node * node);
void print_songs(song_node * node);
song_node * find_song(song_node * node, char * name, char * artist);
song_node * find_artist(song_node * node, char * name);
song_node * random_song(song_node * node);
song_node * remove_song(song_node * node, char * song, char * artist);
song_node * free_list(song_node *);

// playlist
void add_song(song_node * library[26], char * song, char* artist);
song_node * search_song(song_node * library[26], char * song, char* artist);
song_node * search_artist(song_node * library[26], char* artist);
void print_letter(song_node * library[26], char letter);
void print_artist(song_node * library[26], char * artist);
void print_library(song_node * library[26]);
void shuffle(song_node * library[26]);
void delete_song(song_node * library[26], char * song, char * artist);
void delete_all(song_node * library[26]);
