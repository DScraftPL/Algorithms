#include "lista2kiercykl.h"
#include <iostream>

Lista2KierCykl::Lista2KierCykl(){
  head = nullptr;
}

bool Lista2KierCykl::ifEmpty(){
  return head == nullptr;
}

void Lista2KierCykl::addNext(int _liczba){
  elementListy2KierCykl* element = new elementListy2KierCykl;
  element->liczba = _liczba;
  element->next = nullptr;
  element->prev = nullptr;
  if(ifEmpty()){
    head = element;
    head->next = element;
    head->prev = element;
  } else {
    element->next = head->next;
    head->next->prev = element;
    element->prev = head;
    head->next = element;
  }
}

void Lista2KierCykl::addPrev(int _liczba){
  elementListy2KierCykl* element = new elementListy2KierCykl;
  element->liczba = _liczba;
  element->next = nullptr;
  element->prev = nullptr;
  if(ifEmpty()){
    head = element;
    head->next = element;
    head->prev = element;
  } else {
    element->prev = head->prev;
    head->prev->next = element;
    element->next = head;
    head->prev = element;
  }
}

void Lista2KierCykl::print(){
  if(ifEmpty()){
    std::cout << "Lista Pusta!\n";
  } else {
  elementListy2KierCykl *current = head;
  do {
    std::cout << current->liczba << " ";
    current = current->next;
  } while (head!=current);
  std::cout << std::endl;
  }
}

void Lista2KierCykl::popNext(){
  if(ifEmpty()){
    std::cout << "Lista Pusta!";
  } else if(head==head->next){
    elementListy2KierCykl *temp = head;
    head = nullptr;
    delete temp;
  } else {
    elementListy2KierCykl *temp = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    delete temp;
  }
}

void Lista2KierCykl::popPrev(){
  if(ifEmpty()){
    std::cout << "Lista Pusta!";
  } else if(head==head->next){
    elementListy2KierCykl *temp = head;
    head = nullptr;
    delete temp;
  } else {
    elementListy2KierCykl *temp = head->prev;
    head->prev = head->prev->prev;
    head->prev->next = head;
    delete temp;
  }
}

int Lista2KierCykl::count(){
  elementListy2KierCykl *current = head;
  int counter=0;
  if(!ifEmpty()){
    do {
      counter++;
      current = current->prev;
    } while (head!=current);
  }
  return counter;
}
