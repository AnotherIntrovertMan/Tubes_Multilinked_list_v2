#ifndef HEADERMHS_H_INCLUDED
#define HEADERMHS_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next


using namespace std;

struct dataMHS{
    string nim;
    string nama;
    string jk;
    int umur;
    string fak;
};

typedef struct ElmMHS *add_mhs;

struct ElmMHS{
    dataMHS info;
    add_mhs next;
};

struct ListMahasiswa{
    add_mhs first;
};

add_mhs AlokasiMhs(string nim, string nama, string jk, int umur, string fak);
void dealokasiMhs(add_mhs &P);
void createListMhs(ListMahasiswa &L);
add_mhs cariElmMhs(ListMahasiswa L, string x);
void ShowListMhs(ListMahasiswa &L);
void insertLastMhs(ListMahasiswa &L, add_mhs P);
void deleteLastMhs(ListMahasiswa &L, add_mhs &P);
void deletePrecMhs(ListMahasiswa &L,add_mhs &Prec);
bool cekMhs(ListMahasiswa &L, string x);
bool isEmpty(ListMahasiswa L);


#endif // HEADERMHS_H_INCLUDED
