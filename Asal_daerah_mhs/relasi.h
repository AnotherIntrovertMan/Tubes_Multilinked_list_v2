#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include <stdlib.h>


#include "header.h"
#include "headerMhs.h"

using namespace std;

#define next(P) P->next
#define Lmhs(P) P->Lmhs
#define Ldaerah(P) P->Ldaerah

typedef struct elmRelasi *add_relasi;

struct elmRelasi{
    add_daerah Ldaerah;
    add_mhs Lmhs;
    add_relasi next;
};

struct ListRelasi{
    add_relasi first;
};

void createListRel(ListRelasi &L);
add_relasi alokasiRel(add_daerah P, add_mhs Q);
void insertFirstRel(ListRelasi &L, add_relasi P);
void showListRel(ListRelasi L);
add_relasi cariRelasiid(ListRelasi &L, string id);
add_relasi cariRelasiid2(ListRelasi &L, string id,string nama);
void deletePrecRel(ListRelasi &L,add_relasi &Prec);
void deleteLastRel(ListRelasi &L, add_relasi &P);
bool cekRelasi(ListRelasi &L,string nim );
bool isEmptyRel(ListRelasi LR);
void ShowListID(ListRelasi &L,string id);
add_relasi cariRelasimhs(ListRelasi &L, string nama);
int HitungId(ListRelasi L, string x);

#endif // RELASI_H_INCLUDED
