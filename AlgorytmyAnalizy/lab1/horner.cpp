#include <iostream>

using namespace std;

double horner2(int n, double a[], double x){
  if(n == 0){
    return a[n];
  } else {
    return horner2(n-1, a, x)*(x/2) + a[n];
  }
}

double pary(float parametr[], int n){
  if(n == 0){
    return 0;
  }
  if(n == 1){
    return parametr[0]; 
  }
  if(n == 2){
    return parametr[0] + parametr[1];
  }
  return pary(parametr, n/2) + pary(parametr, n - n/2);
}

double kahan(float parametr[], int n){
  float temp, temp_suma, blad = 0, suma = 0;
  for(int i=0; i<n; i++){
    temp = parametr[i] - blad;
    temp_suma = suma + temp;
    blad = temp_suma - suma - temp;
    suma = temp_suma;
  }
  return suma;
}

float calkadol(float n){
  float temp = 0.182;
  for(float i=1; i<n; i++){
    temp = 1.0/i - 5.0 * (temp);
  }
  return temp;
};

double calkagora(){
  double temp = 0.017;
  for(float i=8; i>0; i--){
    temp = 1.0/(5.0*i) - (1.0/5.0) * (temp);
  }
  return temp;
}

int main(){
  int n = 3;
  double a[] = {3,5,1,2};
  double x = 2.0;
  cout << horner2(n, a, x) << endl;
  float suma = 0, temp = 0.1, parametry[1000];
  for(int i=0; i<1000; i++){
    suma += temp;
    parametry[i] = temp;
  }
  cout << suma << endl;
  cout << pary(parametry,1000) << endl;
  cout << kahan(parametry, 1000) << endl;
  cout << calkagora() << endl;
  float temp1 = 0.182;
  for(float i=1; i<9; i++){
    cout << temp1 << endl;
    temp1 = 1.0/i - 5.0 * (temp1);
  }
  cout << temp1 << endl;
  return 0;
}
