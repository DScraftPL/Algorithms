#include <iostream>

using namespace std;

double Horner(int n, double a[], double c){
  double w = a[0];
  for(int i=1; i<=n; i++){
    w = w*c + a[i];
  }
  return w;
}

void HornerN(int n, double a[], double c){
  for(int i=1; i<=n; i++){
    a[i] = a[i-1]*c + a[i];
  }
}

void HornerU(int n, double a[], double c){
  for(int j=n; j>=0; j--){
    for(int i=1; i<=n; i++){
      a[i] = a[i-1]*c + a[i];
    }
    cout << a[j] << " ";
  }
  cout << endl;
}

int silnia(int n){
  int il = 1;
  for(int i=2; i<=n; i++){
      il*=i;
  }
  return il;
}

double interpolacja(int n, int c, double x[], double y[]){
  double l=0, mianownik, licznik;
  for(int i=0; i<n; i++){
    mianownik = 1, licznik = 1;
    for(int j=0; j<n; j++){
      if(i != j){
        mianownik *= (c-x[j]);
        licznik *= (x[i]-x[j]);
      }
    }
    cout << mianownik << " " << licznik << " ";
    double temp = mianownik/licznik;
    cout << temp << endl;
    l+=y[i]*temp;
  }
  return l;
}


//zad5 po na kartce
int main(){
  double x[] = {-1,0,1,2,4};
  double y[] = {25,10,15,10,90};
  cout << interpolacja(5, 3, x, y);
  /*cout << Horner(4, t, 2) << endl;
  for(int i=4; i>=0; i--){
    HornerN(i, t, 2);
    for(int j=0; j<=i; j++){
      cout << t[j] << " ";
    }
    cout << endl;
  }
  for(int i=4; i>=0; i--){
    cout << t[i] / silnia(5-i) << " "; 
  }
  cout << endl;*/
}

//1,2,3,7,8
//
//mantysa * podstawa ^ cecha
//sprowadzic do wiekszego
//1)
//a = 0.31426 * 10^3
//b = 0.92577 * 10^5 
//a + b = 0.0031426 * 10^5 + 0.92577 * 10^5 = 0.9289126 * 10^5 ~~ zaokrąglenie ~~ 0.92891 * 10^5, tracimy 2 liczby
//mantysa musi mieć 5 cyfr
//0.9257700
//0.0031426
//0.9289126
//2)
//fL(x[]y) = (x[]y)(1+e), |e| <= 2^-t
//fl(x*(y+z)) = (x*fl(y+z))(1+e1) <- mnożenie jest obarczone takim błędem, trzeba wyznaczyć fl(y+z)
// = x(y+z)(1+e1)(1+e2) = x(y+z)[1+e1+e2+e1e2] ~~ x(y+z)[1+e1+e2] //e1*e2 <= 2^-t * 2^-t = 2*-2t, mniejszy rzad niz e1 i e2, mozna pominac bo wplywa mniej znaczaco
// e3 = e1+e2 |e3| <= 2^(-t+1), stała nie wiele psuje, operacja jest nadal rzędu 2^(-t)
//3)
//w(x) = x^4 - 2x^2 - x + 2, c = 2
//dzieimy przez x-c, powstaje iloraz o stopien nizej, wyjdzie reszta bn, w(x) = (x-c)*p(x) + r, w(c) = r
//i 
//b0 = a0
//bi = b(i-1)*c+ai
//  c = 2
//  i| 0| 1| 2| 3| 4|
//  a| 1| 0|-2|-1| 2|
//  b| 1| 2| 2| 3| 8| <- 8 to reszta, w(2) = 8
//  c| 1| 4|10|23| <- 23 to reszta 
//
//  p(x) = x^3 + 2x^2 + 2x + 3, r = 8 = w(2)
//  w = a0
//  w = w*c + ai, i=1...n
//
//
//INTERPOLACJA
//wielomian istnieje jak punkty są parami różne
//xi != xj
// x | 0| 1| 3|
// y |-1| 2| 4|
// i | 0| 1| 2|
// l0(x) = (x-1)(x-3)/(0-1)(0-3) = (x-1)(x-3)/3 = (x^2-3x-x+3)/3
// l1(x) = (x-0)(x-3)/(1-0)(1-3) = -(x)(x-3)/2 = -(x^2-3x)/2
// l2(x) = (x-0)(x-1)/(3-0)(3-1) = (x)(x-1)/6 = (x^2-x)/6
// L(x) = l0(x) + l1(x) + l2(x)



