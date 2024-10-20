#include <iostream>
#include "DLL.h"
using namespace std;

int main() {
    List L1, L2, L3;
    createList(L1);
    createList(L2);
    createList(L3);

    infotype lagu1, lagu2, lagu3, lagu4;

    cout << "Masukkan Nama Band untuk Lagu 1: ";
    cin >> lagu1.namaBand;
    cout << "Masukkan Judul Lagu 1: ";
    cin >> lagu1.judulLagu;
    address p1 = createNewElmt(lagu1);
    insertFirst(L1, p1);

    cout << "Masukkan Nama Band untuk Lagu 2: ";
    cin >> lagu2.namaBand;
    cout << "Masukkan Judul Lagu 2: ";
    cin >> lagu2.judulLagu;
    address p2 = createNewElmt(lagu2);
    insertLast(L1, p2);

    cout << "Masukkan Nama Band untuk Lagu 3: ";
    cin >> lagu3.namaBand;
    cout << "Masukkan Judul Lagu 3: ";
    cin >> lagu3.judulLagu;
    address p3 = createNewElmt(lagu3);
    insertLast(L2, p3);

    cout << "Masukkan Nama Band untuk Lagu 4: ";
    cin >> lagu4.namaBand;
    cout << "Masukkan Judul Lagu 4: ";
    cin >> lagu4.judulLagu;
    address p4 = createNewElmt(lagu4);
    insertLast(L2, p4);

    cout << "\nList L1:" << endl;
    show(L1);
    cout << "\nList L2:" << endl;
    show(L2);

    concat(L1, L2, L3);
    cout << "\nList L3 setelah concat:" << endl;
    show(L3);

    string judulCari;
    cout << "\nMasukkan judul lagu yang ingin dicari di L3: ";
    cin >> judulCari;
    address ditemukan = findLagu(judulCari, L3);
    if (ditemukan != NULL) {
        cout << "Lagu ditemukan: " << info(ditemukan).namaBand << " - " << info(ditemukan).judulLagu << endl;
    } else {
        cout << "Lagu tidak ditemukan." << endl;
    }

    string judulHapus;
    cout << "\nMasukkan judul lagu yang ingin dihapus dari L3: ";
    cin >> judulHapus;
    removeLagu(judulHapus, L3);

    cout << "\nList L3 setelah penghapusan:" << endl;
    show(L3);

    return 0;
}
