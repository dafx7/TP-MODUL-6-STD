#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#define first(L) L.first
#define last(L) L.last
#define info(P) P -> info
#define next(P) P -> next
#define prev(P) P -> prev

using namespace std;

struct Lagu {
    string namaBand;
    string judulLagu;
};

typedef Lagu infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

bool isEmpty(List L);

void createList(List &L);
address createNewElmt(infotype X);


void insertFirst(List &L, address P);
void insertAfter(List &L, address &prec, address &P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address &prec, address &P);
void deleteLast(List &L, address &P);

void concat(List L1, List L2, List &L3);
address findLagu(string Judul, List L);
void removeLagu(string Judul, List &L);

void show(List L);

#endif // DLL_H_INCLUDED
