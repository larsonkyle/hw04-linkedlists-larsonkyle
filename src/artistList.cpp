// artistList.cpp: function definitions for prototypes for artistList.h header file
#include "artist.h"
#include "artistList.h"


// doubly linked list to vector conversion for testing purposes
// DO NOT MODIFY
vector<ARTIST> linkedList2Vector(ALIST *l) {
  vector<ARTIST> ll_vec;
  AENTRY *e;
  if (!l) return ll_vec;
  e = l->first;
  while(e) {
    ll_vec.push_back(*e->artist);
    e = e->next;
  }
  return ll_vec;
}

ALIST *newArtistList() {
  ArtistList *p = nullptr;

  p = new ArtistList;

  p->length = 0;
  p->first = nullptr;
  p->last = nullptr;

  return p;
}

AENTRY *newArtistEntry(ARTIST *a) {
  ArtistEntry *p = nullptr;

  p = new ArtistEntry;

  p->list = nullptr;
  p->next = nullptr;
  p->prev = nullptr;

  p->artist = a;

  return p;
}

