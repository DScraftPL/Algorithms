#include <iostream>
#include "kolejka.h"

using namespace std;

bool kolejka_empty(kolejka k){
  return k.first == nullptr;
}

void kolejka_push(kolejka &k, int liczba){
  element_kolejki *element = new element_kolejki;
  element->liczba = liczba;
  element->next = nullptr;
  if(k.last != nullptr){
    k.last->next = element;
  } else {
    k.first = element;
  }
  k.last = element;
}

int kolejka_pop(kolejka &k){
  element_kolejki *temp = k.first;
  k.first = k.first->next;
  int x = temp->liczba;
  delete temp;
  if(k.first == nullptr){
    k.last = nullptr;
  }
  return x;
}

void kolejka_wyswietl(kolejka &k){
  int x;
  kolejka temp;
  temp.first = nullptr;
  temp.last = nullptr;
  while(!kolejka_empty(k)){
    x = kolejka_pop(k);
    cout << x << " ";
    kolejka_push(temp, x);
  }
  cout << endl;
  k = temp;
}

int podzielne(kolejka &k){
  kolejka  _k;
  int pepe;
  int cos=0;
  _k.first = nullptr;
  _k.last = nullptr;
  while(k.first != nullptr){
    cout << "tu!!!!!!!!!!!!!!!!!!!!!\n";
    pepe = kolejka_pop(k);
    if(pepe%3==0){
      cos++;
    }
    kolejka_push(_k, pepe);
  }
  k = _k;
  return cos;
}
