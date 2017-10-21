#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "heads.h"\

int main(){
  if(0){
    printf("\n------------song_node Testing------------\n");
    printf("----insert_front and print_songs:\n");
    song_node * test = insert_order(0, "song", "artist1");
    print_songs(test);

    printf("\n----insert_order:\n");
    test = insert_order(test, "song2", "artist2");
    test = insert_order(test, "song1", "artist1");
    test = insert_order(test, "song5", "artist5");
    test = insert_order(test, "question", "axemea");
    test = insert_order(test, "abc", "abc");
    test = insert_order(test, "1313", "aim");
    print_songs(test);

    printf("\n----find_song and find_artist:\n");
    song_node * temp = find_song(test, "song1", "artist1");
    print_songs(temp);
    temp = find_song(test, "song4", "artist4");
    print_songs(temp);
    temp = find_artist(test, "artist5");
    print_songs(temp);
    temp = find_artist(test, "artist4");
    print_songs(temp);

    printf("\n----random_song:\n");
    srand(time(NULL));
    temp = random_song(test);
    print_songs(temp);
    temp = random_song(test);
    print_songs(temp);
    temp = random_song(test);
    print_songs(temp);

    printf("\n----remove_song:\n");
    remove_song(test, "song1", "artist1");
    print_songs(test);
    remove_song(test, "song", "artist1");
    print_songs(test);

    printf("\n----free_list:\n");
    test = free_list(test);
    print_songs(test);

  }

  if (1){
    printf("\n------------playlist Testing------------\n");
    // cleared array
    song_node * lib[26];
    for (int x = 0; x < 26; x++)
      lib[x] = 0;

    printf("\n----add_song and print_list:\n");
    add_song(lib, "asd", "asd");
    add_song(lib, "song1", "artist1");
    add_song(lib, "question", "axemea");
    add_song(lib, "abc", "abc");
    add_song(lib, "hhh", "hhh");
    add_song(lib, "feelsbad", "feelsbad");
    add_song(lib, "acdc", "acdc");
    add_song(lib, "ghi", "abc");
    add_song(lib, "def", "abc");
    print_library(lib);

    printf("\n----search_song and search_artist:\n");
    print_song(search_song(lib, "asd", "asd"));
    printf("\n");
    print_song(search_song(lib, "aaa", "aaa"));
    printf("\n");
    print_song(search_artist(lib, "artist1"));
    printf("\n");
    print_song(search_artist(lib, "artist2"));
    printf("\n");

    printf("\n----print_artist:\n");
    print_artist(lib, "abc");


    printf("\n----shuffle:\n");
    shuffle(lib);

    printf("\n----deleting:\n");
    delete_song(lib, "abc", "abc");
    print_library(lib);
    delete_all(lib);
    print_library(lib);
  }
}
