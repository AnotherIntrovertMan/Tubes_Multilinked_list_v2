#include "headerMhs.h"

add_mhs AlokasiMhs(string nim, string nama, string jk, int umur, string fak){
    add_mhs P;
    P = new ElmMHS;
    info(P).nim = nim;
    info(P).nama = nama;
    info(P).jk = jk;
    info(P).umur = umur;
    info(P).fak = fak;
    next(P) = NULL;
    return P;
}

void dealokasiMhs(add_mhs &P){
    delete P;
}

void createListMhs(ListMahasiswa &L){
    L.first = NULL;
}

add_mhs cariElmMhs(ListMahasiswa L, string x){
    add_mhs P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && info(P).nim!= x){
            P = next(P);
        }
    }
    return P;
}

void ShowListMhs(ListMahasiswa &L){
    if (L.first==NULL){
        cout<<"List Kosong...."<<endl;
    }else{
        add_mhs P = L.first;
        cout<<" =========================================================================================================="<<endl;
        cout<<"|       NIM         |      NAMA      |   JENIS KELAMIN   |        UMUR        |        FAKULTAS            |"<<endl;
        cout<<" =========================================================================================================="<<endl;
        while (P!=NULL){
            cout<<"| "<<info(P).nim<<"          \t"<<info(P).nama<<"             \t"<<info(P).jk<<"              \t"<<info(P).umur<<"              \t"<<info(P).fak<<endl;
            P = next(P);
        }
    }
    cout<<"==========================================================================================================="<<endl;

}

void insertLastMhs(ListMahasiswa &L, add_mhs P){
     if (L.first==NULL){
        L.first = P;
    }else{
        add_mhs Q = L.first;
        while (next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;

    }

}

void deleteLastMhs(ListMahasiswa &L, add_mhs &P){
    if (L.first==NULL){

    }else if(next(L.first)==NULL){
        P = L.first;
        L.first = NULL;
    }else{
        add_mhs Q;
        P = L.first;
        while (next(P)!=NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }

}

void deletePrecMhs(ListMahasiswa &L,add_mhs &Prec){
    if (L.first==NULL){
      //  cout<<"List Kosong"<<endl;
    }else if (next(L.first)==NULL && Prec==NULL){
      //  cout<<"data tidak ditemukan"<<endl;
    }else if (next(Prec)==NULL){
        add_mhs P = L.first;
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
        add_mhs P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = next(Prec);
        next(Prec) = NULL;
    }

}

bool cekMhs(ListMahasiswa &L, string x){
    if (L.first==NULL){
        return true;
    }else{
        add_mhs P = L.first;
        while (P!=NULL && info(P).nim!=x){
            P = next(P);
        }
        if (P==NULL){
            return true;
        }else{
            return false;
        }
    }

}

bool isEmpty(ListMahasiswa L){
    return (L.first==NULL);
}

