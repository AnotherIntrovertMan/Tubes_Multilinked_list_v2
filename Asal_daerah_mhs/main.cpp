#include "header.h"
#include "headerMhs.h"
#include "relasi.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

ListDaerah LD;
add_daerah Dm;
daerahMHS daerah;
//////////////////////
bool unavailable;
string id,prov,kabkot,kec,kel;
char pilih,out;
int menu;
////////////////////
ListMahasiswa LM;
add_mhs Ds;
dataMHS mahasiswa;
///////////////////
bool unavailable2;
string nim,nama,jk,fak;
int umur;
//////////////////
ListRelasi LR;
bool unavailable3;
string nimm,idd,namaa,namda;

void mainmenu();
void tampilanawal();


void menudaerah(){
        cout<<endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[            MENU DAERAH             ]]" << endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[ 1. Tambah Data Daerah Mahasiswa    ]]" <<endl;
        cout <<"[[ 2. Hapus Data Daerah Mahasiswa     ]]" <<endl;
        cout <<"[[ 3. Cari Data Daerah                ]]" <<endl;
        cout <<"[[ 4. View Data Daerah                ]]" <<endl;
        cout <<"[[ 5. Update ID daerah                ]]" <<endl;
        cout <<"[[ 0. Keluar                          ]]" <<endl;
        cout <<"[[====================================]]" <<endl;
        cout<<"  Pilih Menu: ";
        cin>>menu;
        if (menu==1){
            system("cls");
            cout<<"=================="<<endl;
            cout<<"Input Data Daerah "<<endl;
            cout<<"=================="<<endl;
            cout<<"Input '.' Pada ID_DAERAH jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"ID_DAERAH: ";
            cin>>id;
            while (id!="."){
            unavailable = cekDaerah(LD,id);
            if (unavailable){
                cout<<"Provinsi: ";
                cin>>prov;
                cout<<"Kabupaten/Kota: ";
                cin>>kabkot;
                cout<<"Kecamatan: ";
                cin>>kec;
                cout<<"Kelurahan: ";
                cin>>kel;
                insertLast(LD,Alokasi(id,prov,kabkot,kec,kel));
            }else{
                cout<<"Data sudah ada, input kembali"<<endl;
                system("PAUSE");
                cout<<endl;
            }
            cout<<endl;
            cout<<"Input '.' Pada ID_DAERAH jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"ID_DAERAH: ";
            cin>>id;
            }
            system("cls");
            menudaerah();
       }else if (menu==2){
            string id;
            cout<<"    Delete Daerah   "<<endl;
            cout<<endl;
            cout<<"Masukkan id daerah: ";
            cin>>id;
            add_daerah cari = cariElm(LD,id);
            if (isEmpty(LD)&&cari==NULL){
                cout<<"List Kosong"<<endl;
                system("pause");
            }else{
                if (cari==NULL){
                    cout<<"ID Daerah Tidak Ditemukan"<<endl;
                    system("PAUSE");
                    cout<<endl;
                }else if (next(cari)==NULL){
                    deleteLast( LD,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }else{
                    deletePrec(LD,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }
            }
            system("cls");
            menudaerah();
        }else if (menu==3){
            cout<<"    Cari Daerah   "<<endl;
            cout<<endl;
            cout<<"Masukkan ID daerah: ";
            cin>>id;
            add_daerah cari = cariElm(LD,id);
            if (cari==NULL){
                cout<<"ID tidak ditemukan"<<endl;
                system("PAUSE");
                system("cls");
                menudaerah();
            }else{
                cout<<endl;
                cout<<"Data ditemukan"<<endl;
                cout<<endl;
                cout<<"ID_DAERAH: "<<info(cari).id_daerah<<endl;
                cout<<"  PROVINSI      || "<<info(cari).provinsi <<" ||"<<endl;
                cout<<"  KABUPATEN/KOTA|| "<<info(cari).kabkot <<" ||"<<endl;
                cout<<"  KECAMATAN     || "<<info(cari).kecamatan <<" ||"<<endl;
                cout<<"  KELURAHAN     || "<<info(cari).kelurahan <<" ||"<<endl;
                system("PAUSE");
                system("cls");
                menudaerah();
            }
            system("cls");
        }else if (menu==4){
            system("CLS");
            ShowList(LD);
            system("PAUSE");
            system("cls");
            menudaerah();
        }else if (menu==5){
            system("cls");
            cout<<"UPDATE DATA DAERAH"<<endl;
            cout<<endl;
            cout<<"Masukkan ID daerah:";
            cin>>idd;
            add_daerah P = cariElm(LD,idd);
            if (isEmpty(LD)&&P==NULL){
                cout<<"DATA MASIH KOSONG"<<endl;
                system("pause");
                system("cls");
                menudaerah();
            }else{
                if (P==NULL){
                    cout<<"ID Tidak Ditemukan"<<endl;
                    system("pause");
                    system("cls");
                    menudaerah();
                }else{
                    cout<<endl;
                    cout<<"------------------"<<endl;
                    cout<<"Input Data Baru"<<endl;
                    cout<<endl;
                    cout<<"Provinsi: ";
                    cin>>prov;
                    cout<<"Kabupaten/Kota: ";
                    cin>>kabkot;
                    cout<<"Kecamatan: ";
                    cin>>kec;
                    cout<<"Kelurahan: ";
                    cin>>kel;
                    info(P).provinsi = prov;
                    info(P).kabkot = kabkot;
                    info(P).kecamatan = kec;
                    info(P).kelurahan = kel;
                    cout<<endl;
                    cout<<"Data Terupdate"<<endl;
                    system("pause");
                    system("cls");
                    menudaerah();
                }
            }



        }else if (menu==0){
             cout<<"yakin ingin keluar?(y/n): ";
            cin>>out;
            if (out=='y'){
                system("cls");
                mainmenu();
            }else{
                system("cls");
                menudaerah();
            }
        }
}



void menumahasiswa(){
        cout<<endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[          MENU MAHASISWA            ]]" << endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[ 1. Tambah Data  Mahasiswa          ]]" <<endl;
        cout <<"[[ 2. Hapus Data  Mahasiswa           ]]" <<endl;
        cout <<"[[ 3. Cari Data Mahasiswa             ]]" <<endl;
        cout <<"[[ 4. View Data Mahasiswa             ]]" <<endl;
        cout <<"[[ 5. Update Data Mahasiswa           ]]" <<endl;
        cout <<"[[ 0. Keluar                          ]]" <<endl;
        cout <<"[[====================================]]" <<endl;
        cout<<"  Pilih Menu: ";
        cin>>menu;
        if (menu==1){
            system("cls");
            cout<<"===================="<<endl;
            cout<<"Input Data Mahasiswa "<<endl;
            cout<<"===================="<<endl;
            cout<<"Input '.' Pada NIM jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"NIM: ";
            cin>>nim;
            while (nim!="."){
            unavailable2 = cekMhs(LM,nim);
            if (unavailable2){
                cout<<"Nama: ";
                cin>>nama;
                cout<<"Jenis Kelamin: ";
                cin>>jk;
                cout<<"Umur: ";
                cin>>umur;
                cout<<"Fakultas: ";
                cin>>fak;
                insertLastMhs(LM,AlokasiMhs(nim,nama,jk,umur,fak));
            }else{
                cout<<"Data sudah ada, input kembali"<<endl;
                system("PAUSE");
                cout<<endl;
            }
            cout<<endl;
            cout<<"Input '.' Pada NIM jika proses input selesai"<<endl;
            cout<<endl;
            cout<<"NIM: ";
            cin>>nim;
            }
            system("cls");
            menumahasiswa();
       }else if (menu==2){
            cout<<"    Delete Data Mahasiswa   "<<endl;
            cout<<endl;
            cout<<"Masukkan NIM: ";
            cin>>nim;
            add_mhs cari = cariElmMhs(LM,nim);
            if (isEmpty(LM)&&cari==NULL){
                cout<<"List Kosong"<<endl;
                system("pause");
            }else{
                if (cari==NULL){
                    cout<<"NIM Tidak Ditemukan"<<endl;
                    system("PAUSE");
                    cout<<endl;
                }else if (next(cari)==NULL){
                    deleteLastMhs( LM,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }else{
                    deletePrecMhs(LM,cari);
                    cout<<"DATA TERHAPUS"<<endl;
                    system("PAUSE");
                }
            }
            system("cls");
            menumahasiswa();
        }else if (menu==3){
            cout<<"    Cari Data Mahasiswa   "<<endl;
            cout<<endl;
            cout<<"Masukkan NIM: ";
            cin>>nim;
            add_mhs cari = cariElmMhs(LM,nim);
            if (cari==NULL){
                cout<<"NIM tidak ditemukan"<<endl;
                system("PAUSE");
                system("cls");
                menumahasiswa();
            }else{
                cout<<endl;
                cout<<"Data ditemukan"<<endl;
                cout<<endl;
                cout<<"NIM MAHASISWA: "<<info(cari).nim<<endl;
                cout<<"  NAMA         || "<<info(cari).nama <<" ||"<<endl;
                cout<<"  JENIS KELAMIN|| "<<info(cari).jk <<" ||"<<endl;
                cout<<"  UMUR         || "<<info(cari).umur <<" ||"<<endl;
                cout<<"  FAKULTAS     || "<<info(cari).fak <<" ||"<<endl;
                system("PAUSE");
                system("cls");
                menumahasiswa();
            }
            system("cls");
        }else if (menu==5){
            system("cls");
            cout<<"UPDATE DATA MAHASISWA"<<endl;
            cout<<endl;
            cout<<"Masukkan NIM:";
            cin>>nimm;
            add_mhs P = cariElmMhs(LM,nimm);
            if (isEmpty(LM)&&P==NULL){
                cout<<"DATA MASIH KOSONG"<<endl;
                system("pause");
                system("cls");
                menumahasiswa();
            }else{
                if (P==NULL){
                    cout<<"NIM Tidak Ditemukan"<<endl;
                    system("pause");
                    system("cls");
                    menumahasiswa();
                }else{
                    cout<<endl;
                    cout<<"------------------"<<endl;
                    cout<<"Input Data Baru"<<endl;
                    cout<<endl;
                    cout<<"Umur: ";
                    cin>>umur;
                    cout<<"Fakultas: ";
                    cin>>fak;
                    info(P).umur = umur;
                    info(P).fak = fak;
                    cout<<endl;
                    cout<<"Data Terupdate"<<endl;
                    system("pause");
                    system("cls");
                    menumahasiswa();
                }
            }
        }else if (menu==4){
            system("CLS");
            ShowListMhs(LM);
            system("PAUSE");
            system("cls");
            menumahasiswa();
        }else if (menu==0){
            cout<<"yakin ingin keluar?(y/n): ";
            cin>>out;
            if (out=='y'){
                system("cls");
                mainmenu();
            }else{
                system("cls");
                menumahasiswa();
            }
        }
}




void menurelasi(){
        cout<<endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[            MENU RELASI             ]]" << endl;
        cout <<"[[====================================]]" << endl;
        cout <<"[[ 1. Tambah Relasi                   ]]" <<endl;
        cout <<"[[ 2. Hapus Relasi                    ]]" <<endl;
        cout <<"[[ 3. Tampil Relasi by ID             ]]" <<endl;
        cout <<"[[ 4. Record Relasi                   ]]" <<endl;
        cout <<"[[ 5. Cari Info Daerah Mahasiswa      ]]" <<endl;
        cout <<"[[ 6. Update Daerah Mahasiswa         ]]" <<endl;
        cout <<"[[ 0. Keluar                          ]]" <<endl;
        cout <<"[[====================================]]" <<endl;
        cout<<"  Pilih Menu: ";
        cin>>menu;
        if (menu==1){
            system("cls");
            cout<<"===================="<<endl;
            cout<<"   SAMBUNG RELASI   "<<endl;
            cout<<"===================="<<endl;
            cout<<endl;
            cout<<"Masukkan ID daerah: ";
            cin>>idd;
            cout<<"Masukkan NIM Mahasiswa: ";
            cin>>nimm;
            add_daerah id = cariElm(LD,idd);
            add_mhs nim = cariElmMhs(LM,nimm);
            unavailable3 = cekRelasi(LR,nimm);
            if (unavailable3 && id!=NULL && nim!=NULL){
                insertFirstRel(LR,alokasiRel(id,nim));
                cout<<"Data Terelasi"<<endl;
                system("PAUSE");
            }else{
                cout<<"GAGAL"<<endl;
                system("PAUSE");
            }
            system("cls");
            menurelasi();
        }else if(menu==2){
            cout<<"Hapus Relasi"<<endl;
            cout<<endl;
            cout<<"Masukkan ID daerah: ";
            cin>>idd;
            cout<<"Masukkan Nama Mahasiswa: ";
            cin>>namaa;
            add_relasi P = cariRelasiid2(LR,idd,namaa);
            if (P==NULL){
                cout<<"Tidak ada relasi"<<endl;
                system("PAUSE");
            }else if (next(P)==NULL){
                deleteLastRel(LR,P);
                cout<<"Relasi terhapus"<<endl;
                system("PAUSE");
            }else{
                deletePrecRel(LR,P);
                cout<<"Relasi terhapus"<<endl;
                system("PAUSE");
            }
            system("cls");
            menurelasi();
        }else if (menu==3){
            cout<<"    Tampil Data by ID   "<<endl;
            cout<<endl;
            cout<<"Masukkan ID daerah: ";
            cin>>idd;
            add_relasi cari = cariRelasiid(LR,idd);
            if (isEmptyRel(LR)&& cari==NULL){
                system("cls");
                cout<<"Data Masih Kosong"<<endl;
                cout<<endl;
                cout<<"ID Daerah: "<<idd<<endl;
                cout<<"Provinsi: "<<info(Ldaerah(cari)).provinsi<<endl;
                cout<<endl;
                cout<<" =========================================================================================================="<<endl;
                cout<<"| NO |       NIM         |      NAMA      |   JENIS KELAMIN   |        UMUR        |        FAKULTAS       |"<<endl;
                cout<<" =========================================================================================================="<<endl;
                system("pause");
                system("cls");
                menurelasi();
            }else{
                if (cari==NULL){
                    cout<<"Tidak Ada Relasi"<<endl;
                    system("PAUSE");
                    system("cls");
                    menurelasi();
                }else{
                    system("cls");
                    cout<<endl;
                    cout<<"Data Ditemukan"<<endl;
                    cout<<endl;
                    cout<<"ID Daerah: "<<info(Ldaerah(cari)).id_daerah<<endl;
                    cout<<"Provinsi: "<<info(Ldaerah(cari)).provinsi<<endl;
                    ShowListID(LR,idd);
                    system("PAUSE");
                    system("cls");
                    menurelasi();
                }
            }
            system("cls");
        }else if (menu==4){
            system("CLS");
            cout<<"                    Record Relasi      "<<endl;
            showListRel(LR);
            system("PAUSE");
            system("cls");
            menurelasi();
        }else if (menu==5){
            system("cls");
            cout<<"+++++++++++++++++++++++++++"<<endl;
            cout<<"   DAERAH ASAL MAHASISWA   "<<endl;
            cout<<"+++++++++++++++++++++++++++"<<endl;
            cout<<endl;
            cout<<"Nama Mahasiswa: ";
            cin>>namaa;
            add_relasi R = cariRelasimhs(LR,namaa);
            if (R!=NULL){
                cout<<"Data Ditemukan!"<<endl;
                cout<<endl;
                cout<<"-------------------------------------------------------------------------"<<"|"<<endl;
                cout<<"Daerah Asal Mahasiswa Bernama "<<namaa<<" Berasal dari Provinsi "<<info(Ldaerah(R)).provinsi<<endl;
                cout<<"-------------------------------------------------------------------------"<<"|"<<endl;
                system("pause");
                system("cls");
            }else{
                cout<<endl;
                cout<<"Daerah Belum Diketahui!"<<endl;
                system("pause");
                system("cls");
            }
            menurelasi();
        }else if (menu==6){
            system("cls");
            cout<<endl;
            cout<<"====================="<<endl;
            cout<<"UPDATE DATA MAHASISWA"<<endl;
            cout<<"====================="<<endl;
            cout<<endl;
            cout<<"Masukkan Nama Mahasiswa: ";
            cin>>nama;
            cout<<"Nama Provinsi: ";
            cin>>namda;
            add_relasi R = cariRelasimhs(LR,nama);
            add_daerah P = cariElmbyprov(LD,namda);
            if (R!=NULL){
                Ldaerah(R) = P;
                cout<<"DATA BERHASIL TERUPDATE"<<endl;
                system("pause");
        }else{
            cout<<"GAGAL UPDATE"<<endl;
            system("pause");
        }
            system("cls");
            menurelasi();
        }else if (menu==0){
            cout<<"yakin ingin keluar?(y/n): ";
            cin>>out;
            if (out=='y'){
                system("cls");
                mainmenu();
            }else{
                system("cls");
                menurelasi();
            }
        }
}





void mainmenu(){
    while (out!='0'){
        cout<<"------------       "<<endl;
        cout<<"|PILIH MENU|       "<<endl;
        cout<<"------------       "<<endl;
        cout<<"1. DAERAH          "<<endl;
        cout<<"2. MAHASISWA       "<<endl;
        cout<<"3. RELASI          "<<endl;
        cout<<"4. Exit            "<<endl;
        cout<<"************     "<<endl;
        cout<<"Pilih Menu: ";
        cin>>pilih;
        if (pilih=='1'){
            system("cls");
            menudaerah();
        }else if (pilih=='2'){
            system("cls");
            menumahasiswa();
        }else if (pilih=='3'){
            system("cls");
            menurelasi();
        }else if (pilih=='4'){
            cout<<"exiting program... click 0"<<endl;
            cin>>out;
            tampilanawal();
        }
    }
}

void tampilanawal(){
    system("cls");
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"           TUGAS BESAR STRUKTUR DATA            "<<endl;
    cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    cout<<"   [[ JUDUL : APLIKASI DAERAH MAHASISWA  ]]     "<<endl;
    cout<<"================================================"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"code creator: Naufal Zahid Yoga P"<<endl;
    cout<<"NIM: 1301170345"<<endl;
    cout<<endl;
    system("pause");
    system("cls");
}

int main()
{
    tampilanawal();
    createListMhs(LM);
    createList(LD);
    createListRel(LR);
    insertLastMhs(LM,AlokasiMhs("1301170340","john","L",19,"Informatika"));
    insertLastMhs(LM,AlokasiMhs("1301170001","budi","L",20,"Ekonomi"));
    insertLastMhs(LM,AlokasiMhs("1301170002","anas","L",18,"Hukum"));
    insertLastMhs(LM,AlokasiMhs("1301170003","aryo","L",19,"Elektro"));
    insertLastMhs(LM,AlokasiMhs("1301170004","pras","L",19,"Telekomunikasi"));
    insertLastMhs(LM,AlokasiMhs("1301170005","rika","P",17,"Telekomunikasi"));
    insertLastMhs(LM,AlokasiMhs("1301170006","yoga","L",20,"Informatika"));
    insertLastMhs(LM,AlokasiMhs("1301170007","azis","L",19,"Hukum"));
    insertLastMhs(LM,AlokasiMhs("1301170008","yoan","L",17,"Elektro"));
    insertLastMhs(LM,AlokasiMhs("1301170009","dina","P",20,"Ekonomi"));
    insertLastMhs(LM,AlokasiMhs("1301170010","nike","P",21,"Industri"));
    insertLast(LD,Alokasi("1","Banten","tangerang","legok","medang"));
    insertLast(LD,Alokasi("2","Jabar","bogor","jonggol","mergasari"));
    insertLast(LD,Alokasi("3","Jabar","bandung","Dakol","bojongsoang"));
    insertLast(LD,Alokasi("4","Jateng","solo","slametriyadi","bolon"));
    insertLast(LD,Alokasi("5","Jatim","gresik","mojosari","dumpit"));
    insertFirstRel(LR,alokasiRel(Alokasi("1","Banten","tangerang","legok","medang"),AlokasiMhs("1301170004","pras","L",19,"Telekomunikasi")));
    insertFirstRel(LR,alokasiRel(Alokasi("1","Banten","tangerang","legok","medang"),AlokasiMhs("1301170007","azis","L",19,"Hukum")));
    insertFirstRel(LR,alokasiRel(Alokasi("1","Banten","tangerang","legok","medang"),AlokasiMhs("1301170005","rika","P",17,"Telekomunikasi")));
    insertFirstRel(LR,alokasiRel(Alokasi("1","Banten","tangerang","legok","medang"),AlokasiMhs("1301170009","dina","P",20,"Ekonomi")));
    mainmenu();

}
