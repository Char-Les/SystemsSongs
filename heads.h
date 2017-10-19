#include <stdio.h>
#include <stdlib.h>

typedef struct song_node {
  int i;
  song_node *next;
}song_node;

// song_node
song_node * insert_front(song_node * node, char * name, char * artist);
song_node * insert_order(/*something*/);
void print_songs();
song_node * find_song(char * name);
song_node * find_artist(char * artist);
song_node * random_song();
void remove(song_node * node);
song_node * free_list(song_node *);

// playlist
