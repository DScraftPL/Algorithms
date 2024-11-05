#include <iostream>
#include <time.h>
#include <cstdlib>
#include "../funkcje.h"

using namespace std;
  
void stos_push(elementyStosu* &stos){
  elementyStosu* element = new elementyStosu;
  element -> data = rand() % 10 + 1;
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

void stos_top(elementyStosu* &stos){
  if(check_stos(stos))
  {
    cout << stos->data << "\n";
  }
  else
  {
    cout << "Stos jest pusty\n";
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
  } else
  {
    cout << "koniec stosu\n";
  }
}

int main(){
  srand(time(NULL));
  elementyStosu* stos = nullptr;
  int n;
  cin >> n;
  while(n>0){
    switch(n){
      case 1: cout << "dodano element\n"; stos_push(stos); break;
      case 2: cout << "usunieto element\n"; stos_pop(stos); break;
      case 3: stos_top(stos); cout <<"\n"; break;
      case 4: stos_popAll(stos); break;
      case 5: stos_topALL(stos);
    }
    cin >> n;
  }
  return 0;
}
