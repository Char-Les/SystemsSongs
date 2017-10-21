#include "heads.h"

// add a song to the library
void add_song(song_node * library[26], char * song, char* artist){
  // subtract 'a' to find index and insert at that llist
  int index = artist[0] - 'a';
  library[index] = insert_order(library[index], song, artist);
}

// search for a song
song_node * search_song(song_node * library[26], char * song, char* artist){
  int index = artist[0] - 'a';
  return find_song(library[index], song, artist);
}

// search for an artist (returns first song)
song_node * search_artist(song_node * library[26], char* artist){
  int index = artist[0] - 'a';
  return find_artist(library[index], artist);
}

// prints the entire llist at the letter's index
void print_letter(song_node * library[26], char letter){
  int index = letter - 'a';
  print_songs(library[index]);
}

// prints all of an artist's songs
void print_artist(song_node * library[26], char* artist){
  // make a temp llist of the artist's songs
  song_node * temp = 0;
  song_node * node = search_artist(library, artist);
  // loop while artists are equal
  while (! strcmp(node->artist, artist)){
    temp = insert_order(temp, node->song,node->artist);
    node = node -> next;
  }
  print_songs(temp);
}

// prints all the songs
void print_library(song_node * library[26]){
  for (int x = 0; x < 26; x++) {
    // do nothing if already null
    if (library[x])
      print_songs(library[x]);
  }
}

// selects a random node from library
// seed before use
song_node * random_node(song_node * library[26]){
  // choose a radom index and then a random song
  int index = rand() % 26;
  while (!library[index])
    index = rand() % 26;
  return random_song(library[index]);
}

// prints 3 random songs
void shuffle(song_node * library[26]){
  srand(time(NULL));
  // print out 3 occasions of random_node
  song_node * node = random_node(library);
  print_song(node);
  node = random_node(library);
  print_song(node);
  node = random_node(library);
  print_song(node);
  printf("\n" );
}

// deletes a specific song from the library
void delete_song(song_node * library[26], char* song, char* artist){
  int index = song[0] - 'a';
  song_node * x = find_song(library[index], song, artist);
  // if song is in the library, remove it
  if(x)
    library[index] = remove_song(library[index], song, artist);
}

// delete the entire library
void delete_all(song_node * library[26]){
  // loop through and clear when necessary
  for (int i = 0; i < 26; i++) {
      if(library[i]){
        library[i] = free_list(library[i]);
      }
  }
}
