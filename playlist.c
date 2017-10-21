#include "heads.h"

void add_song(song_node * library[26], char * song, char* artist){
  int index = artist[0] - 'a';
  library[index] = insert_order(library[index], song, artist);
}

song_node * search_song(song_node * library[26], char * song, char* artist){
  int index = artist[0] - 'a';
  return find_song(library[index], song, artist);
}

song_node * search_artist(song_node * library[26], char* artist){
  int index = artist[0] - 'a';
  return find_artist(library[index], artist);
}

void print_letter(song_node * library[26], char letter){
  int index = letter - 'a';
  print_songs(library[index]);
}

void print_artist(song_node * library[26], char* artist){
  song_node * temp = 0;
  song_node * node = search_artist(library, artist);
  // while artists are equal
  while (! strcmp(node->artist, artist)){
    temp = insert_order(temp, node->song,node->artist);
    node = node -> next;
  }
  print_songs(temp);
}

void print_library(song_node * library[26]){
  for (int x = 0; x < 26; x++) {
    if (library[x])
      print_songs(library[x]);
  }
}

song_node * random_node(song_node * library[26]){
  int index = rand() % 26;
  while (!library[index])
    index = rand() % 26;
  return random_song(library[index]);
}

void shuffle(song_node * library[26]){
  srand(time(NULL));
  song_node * node = random_node(library);
  print_song(node);
  node = random_node(library);
  print_song(node);
  node = random_node(library);
  print_song(node);
  printf("\n" );
}
void delete_song(song_node * library[26], char* song, char* artist){
  int index = song[0] - 'a';
  song_node * x = find_song(library[index], song, artist);
  if(x)
    library[index] = remove_song(library[index], song, artist);
}
void delete_all(song_node * library[26]){
  for (int i = 0; i < 26; i++) {
      if(library[i]){
        free(library[i]);
        library[i] = 0;
      }
  }
}
