#ifndef LISTA2KIERCYKL
#define LISTA2KIERCYKL

typedef struct elementListy2KierCykl{
  elementListy2KierCykl * prev;
  elementListy2KierCykl * next;
  int liczba;
} elementListy2KierCykl;

class Lista2KierCykl{
private:
  elementListy2KierCykl* head;
public:
  Lista2KierCykl();
  bool ifEmpty();
  void addNext(int _liczba);
  void addPrev(int _liczba);
  void popNext();
  void popPrev();
  int count();
  void print();
};
#endif // !LISTA2KIERCYKL
