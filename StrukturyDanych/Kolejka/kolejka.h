#ifndef KOLEJKA
#define KOLEJKA

typedef struct element_kolejki{
  int liczba;
  element_kolejki* next;
} element_kolejki;

typedef struct kolejka{
  element_kolejki* first;
  element_kolejki* last;
} kolejka;

bool kolejka_empty(kolejka k);
void kolejka_push(kolejka &k, int liczba);
int kolejka_pop(kolejka &k);
void kolejka_wyswietl(kolejka &k);
int podzielne(kolejka &k);
#endif // !KOLEJKA

