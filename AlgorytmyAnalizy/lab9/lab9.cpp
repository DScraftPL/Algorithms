#include <cmath>
#include <iostream>
#include <math.h>

using namespace std;


double ** Choleski(double A[4][4], int w, int k){
  double ** wynik = new double*[w];
  for(int i=0; i<w; i++){
    wynik[i] = new double[k];
  }
  double suma = 0;
  for(int i=0; i<w; i++){
    for(int j=0; j<k; j++){
      if(i == j){
        for(int m = 1; m < i; m++){
          suma += wynik[i][m];
        }
        wynik[i][j] = sqrt(A[i][j] - suma);
      } else {
        for(int m = 1; m < i; m++){
          suma += wynik[i][m]*wynik[j][m];
        }
        wynik[i][j] = (A[i][j] - suma)/wynik[i][i];
      }
    }
  }
  return wynik; 
}

double ** CholeskiLt(double **A, double w, double k){

}

int main(){

  double A[4][4] = {
    {1,1,-2,-2},
    {1,2,-1,-1},
    {-2,-1,6,3},
    {-2,-4,3,11}
  }; 
  double ** C = Choleski(A, 4, 4);
  cout << "HELLO1";
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      cout << C[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
