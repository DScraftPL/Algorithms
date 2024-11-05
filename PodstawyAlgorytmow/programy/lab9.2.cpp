#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "../funkcje.h"
#include <fstream>

using namespace std;
  
void stos_push(elementyStosu* &stos, char x){
  elementyStosu* element = new elementyStosu;
  element -> data = x;
  element -> next = stos;
  stos = element;
}

bool check_stos(elementyStosu* &stos){
  if(stos==nullptr){
    return 0;
  }
  return 1;
}

void stos_pop(elementyStosu* &stos){
  if(check_stos(stos))
  {
    elementyStosu* temp = stos;
    stos = stos->next;
    delete temp;
  }
  else
  {
    cout << "Stos jest pusty!\n";
  }
}

char stos_top(elementyStosu* &stos){
  if(check_stos(stos))
  {
    return stos->data;
  }
}

void stos_popAll(elementyStosu* &stos){
  while(check_stos(stos)){
    stos_pop(stos);
  }
  cout << "Usunieto wszystkie elementy stosu\n";
}

void stos_topALL(elementyStosu* &stos){
  stos_top(stos);
  if(check_stos(stos->next)){
    stos_topALL(stos->next);
  }
}

int main(){
  elementyStosu* stos = nullptr;
  fstream Plik("znaki.txt");
  fstream PlikW("wynik.txt");
  char c;
  while(Plik >> c){
     stos_push(stos, c);
  }
  while(check_stos(stos)){
    PlikW << stos_top(stos);
    stos_pop(stos);
  }
}
