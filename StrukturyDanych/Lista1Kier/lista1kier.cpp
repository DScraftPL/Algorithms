#include "lista1kier.h"
#include <iostream>

using namespace std;

Lista1Kier :: Lista1Kier(){
  head = nullptr;
  tail = nullptr;
  counter = 0;
}

bool Lista1Kier :: checkEmpty(){
  return head == nullptr;
}

void Lista1Kier:: addTail(int liczba){
  elementyListy1Kier *element = new elementyListy1Kier;
  element->dane = liczba;
  element->next = nullptr;
  if(tail!=nullptr){
    tail->next = element;
  }
  tail = element;
  if(head==nullptr){
    head = element;
  }
  counter++;
}

void Lista1Kier::addHead(int liczba){
  elementyListy1Kier *element = new elementyListy1Kier;
  element->dane = liczba;
  element->next = nullptr;
  element->next = head;
  head = element;
  if(tail==nullptr){
    tail = element;
  }
  counter++;
}

void Lista1Kier::addPos(int liczba, int pos){
  elementyListy1Kier *position = head;
  elementyListy1Kier *element = new elementyListy1Kier;
  element->dane = liczba;
  element->next = nullptr;
  for(int i=0; i<pos-1; i++){
    position = position->next;
  }
  element->next = position->next;
  position->next = element;
  counter++;
}

void Lista1Kier::deleteTail(){
  elementyListy1Kier *trash = tail, *position = head;
  while(position->next!=tail){
    position = position->next;
  }
  position->next = nullptr;
  tail = position;
  delete trash;
  counter--;
}

void Lista1Kier::deleteHead(){
  elementyListy1Kier *trash = head;
  if(head == tail){
    head = nullptr;
    tail = nullptr;
  } else {
    head = head->next;
  }
  delete trash;
  counter--;
}

void Lista1Kier::deletePos(int pos){
  elementyListy1Kier *position = head, *trash;
  for(int i=0; i<pos-1; i++){
    position = position->next;
  }
  position->next = trash;
  position->next = position->next->next;
  delete trash;
  counter--;
}

float Lista1Kier::srednia(){
  float suma = 0;
  elementyListy1Kier *position = head;
  while(position!=nullptr){
    suma+=position->dane;
    position=position->next;
  }
  return suma/counter;
}

int Lista1Kier::maximum(){
  elementyListy1Kier *position = head;
  int maksimum = head->dane;
  while(position!=nullptr){
    if(maksimum < position->dane){
      maksimum = position->dane;
    }
    position = position->next;
  }
  return maksimum;
}

