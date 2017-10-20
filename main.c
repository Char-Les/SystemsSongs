#include "heads.h"\

int main(){
  // song_node testing
  if(1){
    printf("\n------------song_node Testing------------\n");
    printf("insert_front and print_songs:\n");
    song_node * test = insert_front(0, "song", "artist");
    test = insert_front(test, "song2", "artist");
    // test = insert_front(test, "song1", "artist");
    print_songs(test);
    printf("%s: %s | \n", "thing 1", "thing 2");
  }
}
