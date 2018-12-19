#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next


using namespace std;

struct daerahMHS{
    string id_daerah;
    string provinsi;
    string kabkot;
    string kecamatan;
    string kelurahan;
};

typedef struct ElmDaerah *add_daerah;

struct ElmDaerah{
    daerahMHS info;
    add_daerah next;
};

struct ListDaerah{
    add_daerah first;
};

add_daerah Alokasi(string id, string prov, string kabkot, string kec, string kel);
void dealokasi(add_daerah &P);
void createList(ListDaerah &L);
add_daerah cariElm(ListDaerah L, string x);
void ShowList(ListDaerah &L);
void insertLast(ListDaerah &L, add_daerah P);
void deleteLast(ListDaerah &L, add_daerah &P);
void deletePrec(ListDaerah &L,add_daerah &Prec);
bool cekDaerah(ListDaerah &L, string x);
bool isEmpty(ListDaerah L);
add_daerah cariElmbyprov(ListDaerah L, string x);

#endif // HEADER_H_INCLUDED
