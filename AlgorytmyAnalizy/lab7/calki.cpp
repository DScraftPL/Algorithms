#include <iostream>
#include <math.h>

using namespace std;

double f(double x){
  return (1/sqrt(2*3.14))*exp(-x*x/2);
}

double trapez(double a, double b, double m){
  double suma = (f(b) + f(a))/2;
  double x = a;
  double h = (b-a)/m;
  for(int i=0; i<m; i++){
    x+=h;
    suma+=f(x);
  }
  return h*suma;
}

double simpson(double a, double b, double m){
  if((int)m % 2 != 0){
    m+=1;
  }
  double suma = (f(a) + f(b));
  double s1=0; 
  double s0=0;
  double h = (b-a)/m;
  double x = a;
  for(int i=0; i<m; i+=2){
    x += h;
    s0 += f(x);
    x += h;
    s1 += f(x);
  }
  suma += 2*s0 + 4*s1;
  return h*suma/3;
}

int main(){
  cout << "TRAPEZ: " << endl;
  cout << trapez(-3,3,60) << endl;
  cout << trapez(-3,3,100) << endl;
  cout << trapez(-3,3,600) << endl;
  cout << "SIMPSON: " << endl;
  cout << simpson(-3,3,60) << endl;
  cout << simpson(-3,3,100) << endl;
  cout << simpson(-3,3,600) << endl;
  return 0;
}
