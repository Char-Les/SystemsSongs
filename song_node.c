#include <string.h>
#include "heads.h"

// insert the song; artist into the front of the given node
song_node * insert_front(song_node * node, char * name, char * artist){
  // make the new head of the list
  song_node * temp;
  temp = (song_node *) malloc(sizeof(node));
  // set its values
  temp -> song = name;
  temp -> artist = artist;
  temp -> next = node;
  return temp;
}

song_node * insert_order(song_node * node, char * name, char * artist){
  song_node * temp = node;
  // loop until the next node is null
  while(temp -> next){
    // check if this artist is bigger; yes = done; no = keep looping
    if(strcmp(temp->artist, artist) > 0){
      temp = insert_front(temp, name, artist);
      return node;
    }
    temp = temp->next;
  }
  // else temp is last element in the llist; not yet compared
  if(strcmp(temp->artist, artist) > 0){
    temp = insert_front(temp, name, artist);
    return node;
  }else{
    temp->next = insert_front(0, name, artist);
    return node;
  }
}

void print_songs(song_node * node){
  // loop through the list
  // printf("\n");
  while (node){
    // printf("\n");
    // printf("%s: %s", node->artist, node->song);
    node = node->next;
  }
  printf("\n");
}

song_node * find_song(song_node * node, char * name){
  // while there is a node and strcmp isn't 0
  while(node && strcmp(node->song, name))
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
  while (count)
    node = node->next;
  return node;
}

void remove_song(song_node * node, song_node * toremove){
  song_node * temp = find_artist(node, toremove->artist);
  // terminate if it's not in the list
  if (temp != find_song(node, toremove->song) || temp == 0)
    return;
  // while node is not null and you're not at temp
  while (node->next != temp)
    node = node->next;
  node->next = temp->next;
  free(temp);
}

song_node * free_list(song_node * node){
  while (node){
    song_node * temp = node;
    node = node->next;
    free(temp);
  }
  return 0;
}
