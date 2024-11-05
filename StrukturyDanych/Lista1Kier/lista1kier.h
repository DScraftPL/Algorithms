#ifndef LISTA1
#define LISTA1

typedef struct elementyListy1Kier{
  int dane;
  elementyListy1Kier *next;
} elementyListy1Kier;

class Lista1Kier{
public:
  elementyListy1Kier *head;
  elementyListy1Kier *tail;
  unsigned int counter;
  Lista1Kier();
  bool checkEmpty();
  void addTail(int liczba);
  void addHead(int liczba);
  void addPos(int liczba, int pos);
  void deleteTail();
  void deleteHead();
  void deletePos(int pos);
  int firstElement();
  float srednia();
  int maximum();
  int operator[](int x){
    elementyListy1Kier *position = head;
    for(int i=0; i<x; i++){
      position = position->next;
    }
    return position->dane;
  }
};

#endif // !LISTA1
