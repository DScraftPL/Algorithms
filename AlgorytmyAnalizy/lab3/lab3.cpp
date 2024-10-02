#include <iostream>

using namespace std;

double Newton(int n, int x[], double f[], double c){
  double a[n][n],suma=0;
  for(int i=n-1; i>=0; i--){
    a[0][i] = f[i];
  }
  int roznica = 0;
  for(int kolumna=1; kolumna < n; kolumna++){
    int indeks = kolumna;
    roznica++;
    for(int poczatek = 0; poczatek < n-kolumna; poczatek++){
      a[kolumna][poczatek] = (a[kolumna-1][poczatek+1] - a[kolumna-1][poczatek])/(x[indeks]-x[indeks-roznica]);
      cout << a[kolumna][poczatek] << " ";
      indeks++;
    }
    cout << endl;
  }
  int temp[n];
  for(int i=0; i<n; i++){
    temp[i] = a[i][0];
  }
  suma = temp[n-1];
  for(int i=n-2; i>=0; i--){
    suma = suma*(c-x[i]) + temp[i];
  }
  cout << endl;
  return suma;
}

int main(){
  double f[] = {25,10,15,10,90};
  int x[] = {-1,0,1,2,4};
  cout << Newton(5,x,f,3) << " ";
  cout << 25 + -15*(3-(-1)) + 10*(3-(-1))*(3-0) + -5*(3-(-1))*(3-0)*(3-1) + 2*(3-(-1))*(3-0)*(3-1)*(3-2);
}

// 0 1 2
// 1 2 3
// f[0] = 1, f[0,1] = (2-1)/(1-0) = 1, f[0,1,2] = (1-1)/(2-0) = 0;
// f[1] = 2, f[1,2] = (3-2)/(2-1) = 1
// f[2] = 3,  
