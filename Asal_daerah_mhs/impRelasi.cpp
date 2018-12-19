#include "relasi.h"

void createListRel(ListRelasi &L){
    L.first = NULL;
}

add_relasi alokasiRel(add_daerah P, add_mhs Q){
    add_relasi R = new elmRelasi;
    Ldaerah(R) = P;
    Lmhs(R) = Q;
    next(R) = NULL;
    return R;

}

void insertFirstRel(ListRelasi &L, add_relasi P){
    next(P) = L.first;
    L.first = P;

}

void showListRel(ListRelasi L){
    if (L.first != NULL) {
        int i = 1;
        add_relasi P = L.first;
        cout<<" ====================================================="<<endl;
        cout<<"| NO | ID DAERAH |    NIM MAHASISWA    |     STATUS   |"<<endl;
        cout<<" ====================================================="<<endl;
        while(P != NULL) {
            cout<<"| "<<i<<"  |     "<<info(Ldaerah(P)).id_daerah<<"      \t"<<info(Lmhs(P)).nim<<"   \t"<<"  TERHUBUNG"<<endl;
            P = next(P);
            i++;
        }
    }else{
        cout<<"DATA KOSONG"<<endl;
    }
}

add_relasi cariRelasiid(ListRelasi &L, string id){ //mencari relasi melalui id daerah
    add_relasi P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && id!=info(Ldaerah(P)).id_daerah){
            P = next(P);
        }
    }
    return P;

}

add_relasi cariRelasimhs(ListRelasi &L, string nama){ //mencari relasi melalui nama mhs
    add_relasi P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL && nama!=info(Lmhs(P)).nama){
            P = next(P);
        }
    }
    return P;

}


add_relasi cariRelasiid2(ListRelasi &L, string id,string nama){ //mencari relasi melalui id daerah
    add_relasi P;
    if (L.first==NULL){
        return NULL;
    }else{
        P = L.first;
        while (P!=NULL){
            if (nama==info(Lmhs(P)).nama && id==info(Ldaerah(P)).id_daerah){
                return P;
            }
            P = next(P);
        }
    }
    return P;

}


void deletePrecRel(ListRelasi &L,add_relasi &Prec){
    if (L.first==NULL){
      //  cout<<"List Kosong"<<endl;
    }else if (next(L.first)==NULL && Prec==NULL){
      //  cout<<"data tidak ditemukan"<<endl;
    }else if (next(Prec)==NULL){
        add_relasi P = L.first;
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
        add_relasi P = L.first;
        while (next(P)!=Prec){
            P = next(P);
        }
        next(P) = next(Prec);
        next(Prec) = NULL;
    }

}

void deleteLastRel(ListRelasi &L, add_relasi &P){
    if (L.first==NULL){

    }else if(next(L.first)==NULL){
        P = L.first;
        L.first = NULL;
    }else{
        add_relasi Q;
        P = L.first;
        while (next(P)!=NULL){
            Q = P;
            P = next(P);
        }
        next(Q) = NULL;
    }

}

bool cekRelasi(ListRelasi &L,string nim ){
    if (L.first==NULL){
        return true;
    }else{
        add_relasi P = L.first;
        while (P!=NULL &&info(Lmhs(P)).nim!=nim){
            P = next(P);
        }
        if (P==NULL){
            return true;
        }else{
            return false;
        }
    }
}

bool isEmptyRel(ListRelasi LR){
    return (LR.first==NULL);
}


void ShowListID(ListRelasi &L,string id){
    if (L.first==NULL){
        cout<<"Data Masih Kosong"<<endl;
        cout<<endl;
        cout<<" =========================================================================================================="<<endl;
        cout<<"| NO |       NIM         |      NAMA      |   JENIS KELAMIN   |        UMUR        |        FAKULTAS       |"<<endl;
        cout<<" =========================================================================================================="<<endl;
    }else{
        cout<<" =========================================================================================================="<<endl;
        cout<<"| NO |       NIM         |      NAMA      |   JENIS KELAMIN   |        UMUR        |        FAKULTAS       |"<<endl;
        cout<<" =========================================================================================================="<<endl;
        add_relasi P = L.first;
        int i = 1;
        while (P!=NULL){
            if (info(Ldaerah(P)).id_daerah==id){
                cout<<"| "<<i<<"  |"<<" \t"<<info(Lmhs(P)).nim<<"          \t"<<info(Lmhs(P)).nama<<"          \t"<<info(Lmhs(P)).jk<<"                 \t"<<info(Lmhs(P)).umur<<"          \t"<<info(Lmhs(P)).fak<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
            }
            P = next(P);
            i++;
        }
    }

}

int HitungId(ListRelasi L, string x){
    if (L.first == NULL){
        return 0;
    }else{
        int i = 0;
        add_relasi P = L.first;
        while (P!=NULL){
            if (info(Ldaerah(P)).id_daerah==x){
                i++;
            }
            P = next(P);
        }
        return i;
    }
}

