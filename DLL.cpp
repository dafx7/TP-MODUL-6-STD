#include <iostream>
#include "DLL.h"

bool isEmpty(List L)
{
    return first(L) == NULL;
}

void createList(List &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address createNewElmt(infotype X)
{
    address p = new elmList;
    if (p != NULL)
    {
        info(p) = X;
        next(p) = NULL;
    }
    return p;
}

void insertFirst(List &L, address P)
{
    if (first(L) != NULL)
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
    else
    {
        first(L) = P;
        last(L) = P;
    }
}

void insertAfter(List &L, address &prec, address &P)
{
    next(P) = next(prec);
    prev(P) = prec;
    if (next(prec) != NULL)
    {
        prev(next(prec)) = P;
    }
    next(prec) = P;
}

void insertLast(List &L, address P)
{
    if (last(L) != NULL)
    {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
    else
    {
        first(L) = P;
        last(L) = P;
    }
}

void deleteFirst(List &L, address &P)
{
    if (first(L)!= NULL)
    {
        P = first(L);
        if (next(first(L)) != NULL)
        {
            first(L) = next(first(L));
            prev(first(L)) = NULL;
        }
        else
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        next(P) = NULL;
    }
    else
    {
        P = NULL;
    }
}

void deleteAfter(List &L, address &prec, address &P)
{
    P = next(prec);
    next(prec) = next(P);
    prev(next(P)) = prec;

    prev(P) = NULL;
    next(P) = NULL;
}

void deleteLast(List &L, address &P)
{
    if (last(L) != NULL)
    {
        P = last(L);
        if (prev(last(L)) != NULL)
        {
            last(L) = prev(last(L));
            next(last(L)) = NULL;
        }
        else
        {
            last(L) = NULL;
            first(L) = NULL;
        }
        prev(P) = NULL;
    }
    else
    {
        P = NULL;
    }
}

void concat(List L1, List L2, List &L3)
{
    first(L3) = first(L1);
    next(last(L1)) = first(L2);
    prev(first(L2)) = last(L1);
    last(L3) = last(L2);
}

address findLagu(string Judul, List L)
{
    if (!isEmpty(L))
    {
        address p = first(L);
        while (p != NULL)
        {
            if (info(p).judulLagu == Judul)
            {
                return p;
            }
            p = next(p);
        }
        return NULL;
    }
    else
    {
        cout << "List Kosong" << endl;
    }
}

void removeLagu(string Judul, List &L)
{
    if (!isEmpty(L))
    {
        address lagu = findLagu(Judul, L);
        address p;
        if (lagu != NULL)
        {
            if (lagu == first(L))
            {
                deleteFirst(L, p);
            }
            else if (lagu == last(L))
            {
                deleteLast(L, p);
            }
            else
            {
                deleteAfter(L, prev(lagu), p);
            }
        }
        else
        {
            cout << "Lagu tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "List kosong." << endl;
    }
}

void show(List L)
{
    address p = first(L);
    cout << "List Lagu: " << endl;
    int i = 1;
    while (p != NULL)
    {
        cout << i << ". " << info(p).namaBand << " - " << info(p).judulLagu << endl;
        p = next(p);
    }
}
