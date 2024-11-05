#include <iostream>
#include <fstream>
#include "../funkcje.h"

using namespace std;

int main(){
  int n; char *temp = new char ;
  ifstream plik;
  plik.open("studenci.csv");
  plik >> n;
  for(int i=0; i<2; i++){
    plik >> *temp;
  }
  cout << n << endl;
  student *t = new student[n];
  for(int i=0; i<n; i++){
    getline(plik, t[i].imie, ';');
    getline(plik, t[i].nazwisko, ';');
    plik >> t[i].punkty;
  }
  int x;
  cin >> x;
  sortowanieQuickSort(t,n,0);
  wyswietlStudentow(t,n);
  int miejsce = wyszkiwanieBisekcyjne(t,x,n,0,n-1);
  if(miejsce == -1){
    cout << "brak elementów";
  }
  else{
    cout << "miejsce: " << miejsce;
    int miejsceN = miejsce;
    while(t[miejsce].punkty == t[miejsceN+1].punkty){
      miejsceN += 1;
      cout << " " << miejsceN;
    }
    miejsceN = miejsce;
    while(t[miejsce].punkty == t[miejsceN-1].punkty){
      miejsceN -= 1;
      cout << " " << miejsceN;
    }
  }
  return 0;
}
