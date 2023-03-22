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

ARTIST *deleteArtistEntry(AENTRY *e){
  Artist *artist;
  ArtistEntry *temp;

  artist = e->artist;
	delete e;

  return artist;
}

void deleteArtistList(ALIST *l){
  ArtistEntry *traverseList;

  traverseList = l->first; 
  
  while(traverseList != nullptr){
    l->first = traverseList->next;

    traverseList->prev = nullptr; //redundant
    delete traverseList;

    traverseList = l->first;
    l->length--;
  }

  l->last = nullptr;
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
  ArtistEntry *newNode; //= nullptr; 
  ArtistEntry *temp; //= nullptr; 

  newNode = newArtistEntry(a); // new ArtistEntry 

  if (e->prev == nullptr){
    newNode->next = e; 
    e->prev = newNode;

    //e->list->first = newNode;
    //e->list->length++;

     newNode = nullptr;
     temp = nullptr;
  }
  else{
    temp = e->prev;

    temp->next = newNode;
    e->prev = newNode;

    newNode->next = e; 
    newNode->prev = temp;

    //e->list->length++;
    
     newNode = nullptr;
     temp = nullptr;
  }
}

void insertArtistAfter(AENTRY *e, ARTIST *a){
  ArtistEntry *newNode; //= nullptr; 
  ArtistEntry *temp; //= nullptr; 

  newNode = newArtistEntry(a); // new ArtistEntry 

  if (e->next == nullptr){
	newNode->prev = e;
	e->next = newNode;

    //e->list->last = newNode;
    //e->list->length++;

     newNode = nullptr;
     temp = nullptr;
  }
  else{
    temp = e->next;

    temp->prev = newNode;
    e->next = newNode; 

    newNode->prev = e;
    newNode->next = temp; 

    //e->list->length++;

     newNode = nullptr;
     temp = nullptr;
  }
}

void removeFirstArtist(ALIST *l){
  ArtistEntry *temp;

  temp = l->first; 
  l->first = temp->next;

  l->first->prev = nullptr;
  l->length--;

  delete temp;
  temp = nullptr;
}

void removeLastArtist(ALIST *l){
  ArtistEntry *temp;

  temp = l->last;
  l->last = temp->prev; 

  l->last->next = nullptr;
  l->length--;

  delete temp; 
  temp = nullptr;
}

void printArtistList(ALIST *l){
  ArtistEntry *traverseList;
  traverseList = l->first;

// artist_id,artist_name,total_followers,genres, popularity\n
  while(traverseList != nullptr){
    cout << traverseList->artist->artist_id << ", "
         << traverseList->artist->artist_name << ", "
         << traverseList->artist->total_followers << ", ";
  
    for(int i = 0; i < AR_LEN; i++)
      cout << traverseList->artist->genres[i] << ", ";

    cout << traverseList->artist->popularity << ", ";
    cout << "\n";

    traverseList = traverseList->next;
  }
}

ARTIST *findArtistName(ALIST *l, string name){
  ArtistEntry *traverseList;
  Artist *artist; 
  bool found = false; 

  traverseList = l->first;

  while(!found){
    if(traverseList == nullptr)
      found = true;

    if(traverseList->artist->artist_name == name){
      found = true;
    }
    else{
      traverseList = traverseList->next;
    }
  }

  if(traverseList == nullptr){
    artist = nullptr;
  }
  else{
    artist = traverseList->artist; 
  }

  return artist;
}

void removeArtistbyName(ALIST *l, string name){
  ArtistEntry *traverseList;
  ArtistEntry *temp;
  bool found = false; 

  traverseList = l->first;

  while(!found){
    if(traverseList == nullptr){
      found = true;
    }

    if(traverseList->artist->artist_name == name){
      found = true;
    }
    else{
      traverseList = traverseList->next;
    }
  }

  if(traverseList->prev == nullptr){
    temp = traverseList->next;
    temp->prev = nullptr;

    l->first = temp;
    l->length--;

    delete traverseList;
    //traverseList = nullptr;
  }else if(traverseList->next == nullptr){
    temp = traverseList->prev;
    temp->next = nullptr;

    l->last = temp;
    l->length--;

    delete traverseList;
    //traverseList = nullptr;
  }else{
    temp = traverseList->prev; 
    temp->next = traverseList->next; 

    temp = traverseList->next;
    temp->prev = traverseList->prev; 

    l->length--;

    delete traverseList; 
  //traverseList = nullptr;
  }
}
