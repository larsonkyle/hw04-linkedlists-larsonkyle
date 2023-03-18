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

void prependArtist(ALIST *l, ARTIST *a){
  ArtistEntry *traverseList = nullptr;

  if (!l->first){
    l->first = newArtistEntry(a);
    l->last = l->first;
    l->length++;
  } 
  else{
    traverseList = l->first;

    traverseList->prev = newArtistEntry(a);
    traverseList = traverseList->prev;

    traverseList->next = l->first;
    l->first = traverseList;
    l->length++;
  }
}

void appendArtist(ALIST *l, ARTIST *a){
  ArtistEntry *traverseList = nullptr;

  if(!l->last){
    l->last = newArtistEntry(a);
    l->first = l->last;
    l->length++;
  }
  else{
    traverseList = l->last;

    traverseList->next = newArtistEntry(a);
    traverseList = traverseList->next;

    traverseList->prev = l->last;
    l->last = traverseList;
    l->length++;
  }
}

void insertArtistBefore(AENTRY *e, ARTIST *a){
  ArtistEntry *newNode = nullptr; 
  ArtistEntry *temp = nullptr; 

  newNode = new ArtistEntry;
  newNode->artist = a;

  if (e->prev == nullptr){
    newNode->next = e; 
    e->prev = newNode;

    e->list.first = newNode;
    e->list.length++;

    newNode = nullptr;
    temp = nullptr;
  }
  else{
    temp = e->prev;

    temp->next = newNode;
    e->prev = newNode;

    newNode->next = e; 
    newNode->prev = temp;

    e->list.length++;
    
    newNode = nullptr;
    temp = nullptr;
  }
}

void insertArtistAfter(AENTRY *e, ARTIST *a){
  ArtistEntry *newNode = nullptr; 
  ArtistEntry *temp = nullptr; 

  newNode = new ArtistEntry;
  newNode->artist = a;

  if (e->next == nullptr){
    e->next = newNode;
    newNode->prev = e;

    e->list.last = newNode;
    e->list.length++;

    newNode = nullptr;
    temp = nullptr;
  }
  else{
    temp = e->next;

    e->next = newNode;
    newNode->prev = e; 

    temp->prev = newNode;
    newNode->next = temp; 

    e->list.length++;

    newNode = nullptr;
    temp = nullptr;
  }
}

void removeFirstArtist(ALIST *l){
  ArtistEntry *temp;

  temp = l->first; 
  l->first = temp->next;

  l->first.prev = nullptr;

  delete temp;
  temp = nullptr;
}

void removeLastArtist(ALIST *l){
  ArtistEntry *temp;

  temp = l->last;
  l->last = temp->prev; 

  l->last.next = nullptr;

  delete temp; 
  temp = nullptr;
}

void printArtistList(ALIST *l){
  int test;
}

ARTIST *findArtistName(ALIST *l, string name){
  ARTIST *test = nullptr;

  return test;
}

void removeArtistbyName(ALIST *l, string name){
  int test;
}