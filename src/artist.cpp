// artist.cpp: function definitions file for artist.h

#include "artist.h"

// Array to Vector TESTING PURPOSES DO NOT MODIFY
vector<string> array2vec(string src[AR_LEN]) {
  vector<string> dest;
  for (int i = 0; i < AR_LEN; ++i) dest.push_back(src[i]);
  return dest;
}

ARTIST *newArtist(string artist_id, string artist_name, int total_followers, string genres[AR_LEN], int popularity){
  Artist *p = nullptr; 

  p = new Artist; 

  p->artist_id = artist_id;
  p->artist_name = artist_name;
  p->total_followers = total_followers;

  for (int i = 0; i < AR_LEN; i++){
    p->genres[i] = genres[i];
  }

  p->popularity = popularity;

  return p;
}

void deleteArtist(ARTIST *a){
  int test;
}

void printArtist(ARTIST *a){
  int test;
}