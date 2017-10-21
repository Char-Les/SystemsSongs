#include <string.h>
#include <time.h>
#include "heads.h"

// insert the song; artist into the front of the given node
song_node * insert_front(song_node * node, char * name, char * artist){
  // make the new head of the list
  song_node * temp = (song_node *) malloc(sizeof(song_node));
  // set its values
  temp -> song = name;
  temp -> artist = artist;
  temp -> next = node;
  return temp;
}

// insert the song in the correct position in the node
song_node * insert_order(song_node * node, char * name, char * artist){
  //easy case
  if(node == NULL)
    return insert_front(0, name, artist);
  //song belongs in front; smaller artist or smaller song w/ same artist
  if(strcmp(node->artist, artist) > 0
      || (strcmp(node->artist, artist) == 0 && strcmp(node->song, name) > 0)){
    // print_songs(node);
    song_node * in = insert_front(node, name, artist);
    return in;
  }

  song_node * current = node;
  song_node * before = node;
  // loop until null or until the artist passes or until song reaches its place
  while(current
        && (strcmp(current->artist, artist) < 0
           || (strcmp(current->artist, artist) == 0
              && strcmp(current->song, name) < 0))){
  before = current;
  current = current->next;
  }
  //insert the song between before and current
  before -> next = insert_front(current, name, artist);
  return node;
}

void print_song(song_node * node){
  if(node)
    printf("%s: %s |", node->artist,  node->song );
}
void print_songs(song_node * node){
  // loop through the list
  // printf("\n");
  while (node){
    // printf("\n");
    print_song(node);
    node = node->next;
  }
  printf("\n");
}

song_node * find_song(song_node * node, char * name, char * artist){
  // loop until null or strcmp is 0
  while(node && (strcmp(node->song, name) || strcmp(node->artist, artist)))
    node = node->next;
  // either null or node->song is name
  return node;
}

song_node * find_artist(song_node * node, char * name){
  // while there is a node and strcmp isn't 0
  while(node && strcmp(node->artist, name))
    node = node->next;
  // either null or node->artist is name
  return node;
}

song_node * random_song(song_node * node){
  int count = 0;
  song_node * temp = node;
  while (temp && ++count)
    temp = temp->next;
  count = rand() % count;
  while (count--){
    node = node->next;
  }
  return node;
}

song_node * remove_song(song_node * node, char * name, char * artist){
  song_node * temp = find_song(node, name, artist);
  if (!temp)
    return node;
  if(node == temp)
    return node->next;
  // while node is not null and you're not at temp
  song_node * head = node;
  while (node->next != temp)
    node = node->next;
  node->next = temp->next;
  free(temp);
  return head;
}

song_node * free_list(song_node * node){
  while (node){
    song_node * temp = node;
    node = node->next;
    free(temp);
  }
  return 0;
}
