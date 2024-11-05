#include <iostream>
#include <fstream>
#include "Kolejka/kolejka.h"

using namespace std;

int main(){
  kolejka kolej;
  kolej.first = nullptr;
  kolej.last = nullptr;
  int n;
  do{
    cout << "1-wyswietl\n2-dodaj za\n3-dodaj przed\n4-usun za\n5-usun przed\n6-liczba elementow\n";
    cin >> n;
    system("clear");
    switch (n) {
      case 1:{
        cout << podzielne(kolej) << endl; 
        break;
      }
      case 2:{
        int x;
        cin >> x;
        kolejka_push(kolej, x);
        break;
      }
      case 3:{
        kolejka_wyswietl(kolej);
        break;
      }
      case 4:{
        break;
      }
      case 5:{
        break;
      }
      case 6:{
        break;
      }
    }
  } while (n>0);
  return 0;
}
