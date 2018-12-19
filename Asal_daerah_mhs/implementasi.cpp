#include "header.h"

add_daerah Alokasi(string id, string prov, string kabkot, string kec, string kel){
    add_daerah P;
    P = new ElmDaerah;
    info(P).id_daerah = id;
    info(P).provinsi = prov;
    info(P).kabkot = kabkot;
    info(P).kecamatan = kec;
    info(P).kelurahan = kel;
    next(P) = NULL;
    return P;
}

void dealokasi(add_daerah &P){
    delete P;
}

void createList(ListDaerah &L){
    L.first = NULL;
}

add_daerah cariElm(ListDaerah L, string x){
    add_daerah P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && info(P).id_daerah!= x){
            P = next(P);
        }
    }
    return P;
}

add_daerah cariElmbyprov(ListDaerah L, string x){
    add_daerah P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && info(P).provinsi!= x){
            P = next(P);
        }
    }
    return P;
}

void ShowList(ListDaerah &L){
    if (L.first==NULL){
        cout<<"List Kosong...."<<endl;
    }else{
        add_daerah P = L.first;
        cout<<" ============================================================================================================================================="<<endl;
        cout<<"|       ID DAERAH       |          PROVINSI         |         KAB/KOTA          |          KECAMATAN          |           KELURAHAN           |"<<endl;
        cout<<" ============================================================================================================================================="<<endl;
        while (P!=NULL){
            cout<<"|         "<<info(P).id_daerah<<"                    \t"<<info(P).provinsi<<"                \t"<<info(P).kabkot<<"                    \t"<<info(P).kecamatan<<"                   \t"<<info(P).kelurahan<<endl;
            P = next(P);
        }
        cout<<"=============================================================================================================================================="<<endl;
    }
}


void insertLast(ListDaerah &L, add_daerah P){
    if (L.first==NULL){
        L.first = P;
    }else{
        add_daerah Q = L.first;
        while (next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;

    }
}


void deleteLast(ListDaerah &L, add_daerah &P){
    if (L.first==NULL){

    }else if(next(L.first)==NULL){
        P = L.first;
        L.first = NULL;
    }else{
        add_daerah Q;
        P = L.first;
        while (next(P)!=NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }
}


void deletePrec(ListDaerah &L,add_daerah &Prec){
    if (L.first==NULL){
      //  cout<<"List Kosong"<<endl;
    }else if (next(L.first)==NULL && Prec==NULL){
      //  cout<<"data tidak ditemukan"<<endl;
    }else if (next(Prec)==NULL){
        add_daerah P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = NULL;
    }else if (Prec==L.first){
        L.first = next(Prec);
        next(Prec) = NULL;
    }else if (Prec==L.first&&next(L.first)==NULL){
        L.first = NULL;
    }else{
        add_daerah P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = next(Prec);
        next(Prec) = NULL;
    }
}



bool cekDaerah(ListDaerah &L, string x){  //Return true jika tidak ada duplikat
    if (L.first==NULL){
        return true;
    }else{
        add_daerah P = L.first;
        while (P!=NULL && info(P).id_daerah!=x){
            P = next(P);
        }
        if (P==NULL){
            return true;
        }else{
            return false;
        }
    }
}



bool isEmpty(ListDaerah L){
    return (L.first==NULL);
}
