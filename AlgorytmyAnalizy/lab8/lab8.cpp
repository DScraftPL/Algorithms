#include <iostream>

using namespace std;

int main () {

  return 0;
}

// I = całka od -1 do 1 f(x) dx -> K_2(f) = A0f(x0) + A1f(x1) + A2f(x2)
// węzły -1, 0, 1
// nie ma podanych wartości
// trzeba wyznaczyć A0, A1, A2
// A0 = całka od -1 do 1 l0(x) dx -> l0(x) wielomian lagrange'a
//  
// Kwadratura jest dokładna na Pn, n - index ostatniego węzła
// P - polynomial, wielomiany bazowe z których można zbudować wielomian n stopnia
// P2: 1,x,x^2 
// całki z funkcji bazowych == kwadratury 
// całka od -1 do 1 1 dx,
// całka od -1 do 1 x dx,
// całka od -1 do 1 x^2 dx,
//
// K2(f) = A0 * f(x0) + A1* f(x1) + A2 * f(x2)
//
// f(x) = 1 -> wartość w węzłach x0, x1, x2 -> f(x0) = f(x1) = f(x2) = 1
// K2(1) = A0 * 1 + A1 * 1 + A2 * 1
// f(x) = x -> f(x0) = -1, f(x1) = 0, f(x2) = 1
// K2(x) = A0*(-1) + A1 * 0 + A2 * 1
// f(x) = x^2 itd.. 
// układ 3 równań powstawnie
//
// K2(1) <- wartość całki dla bazowego 1
// K2(x) <- wartość całki dla bazowego x
// K2(x^2) <- wartość całki dla bazoweg x^2
//
// zad 5
// f(x) = 1/(1+x^2)
//
// całka od 0 do 1 f(x) dx
//
// a = 0, b = 1 <- granice całkowania
//
// wzór trapezów:
// K1(f) = (b-a)/2 * (f(a) + f(b))
// f(0) = 1/(1+0) = 1
// f(1) = 1/(1+1) = 1/2
// K1(f) = (1-0)/2 * (1 + 1/2) = 1/2 * 3/2 = 3/4
// wzór simpsona: (z wartością średnią)
// K2(f) = (b-a)/6 * (f(a) + 4 * f((a+b)/2) + f(b)) 
// f(1/2) = 1/(1+1/4) = 4/5
// K2(f) = 1/6 * (1 + 4*4/5 + 1/2) = 47/60
// trzy ósme: (podzielić na 3)
//
// KWADRATURY ZŁOŻONE
// I = całka od 0 do 6 1/(x+1) dx 
// h = 1 <- krok 
// a = 0, b = 6
// trapezów:
// Kt(f) = h(1/2f0 + f1 + f2 + f3 + f4 + f5 + 1/2f6)
// f0 = f(0) = 1
// f1 = f(0+h = 1) = 1/2
// f2 = f(1+h = 2) = 1/3
// 
// Kt(f) = 1 * (1/2 * 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 + 1/7 * 1/2)
// 
// simpsona:
// Ks(f) = h/3 (f0 + 2*(f2 + f4 + ... + fn-2) + 4*(f1 + f3 + ... + fn-1) + fn)
// Ks(f) = h/3 (f0 + 2*(f2 + f4) + 4*(f1 + f3 + f5) + f6)
//
// zad 7 
// 1) ma być dokładne na p1, bo 2 węzły x0, x1
// policzyć całki, wyznaczyć A0, A1
// p1: 1, x
// całka od a do b 1 dx = b - a
// K1 = (b-a)/2 * (1 + 1) = b - a <- zgadza się z całką
// (f(a+b/3) dlaa tej funkcji = 1)
// całka od a do b x dx = (b^2 - a^2)/2
// K2 = (b-a)/2 * ((a+b)/2 + (a+b)/3) != od wyniku całki, więc kwadratura jest do dupy
//
// zad 13
// wykazać 
// suma Ai = b - a
// Kn = suma Aif(xi), dla f(x) = 1, wielomain stopnia zerowego
// Kn(f) = suma Ai, musi być dokładna na P0, trzeba policzyć całkę f(x) na przedziale a,b
//
