/*
Nama        : Natasya Rizky Maharani
NPM         : 140810180004
Deskripsi   : Program ini menampilkan data pegawai
Tahun       : 2019
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct pegawai{
    char nama[40];
    char divisi[20];
    int gaji;
    pegawai* next;
};
typedef pegawai* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast (List& First, pointer& pHapus);
void traversal (List First);

main()
{
    pointer pBaru;
    List first;
    int pilihan;

    createList(first);
    while(1){
        system("cls");
        cout<<">>>>>>>>Menu<<<<<<<<"<<endl;
        cout<<"-------------------- "<<endl;
        cout<<"1. Insert First     |"<<endl;
        cout<<"2. Insert Last      |"<<endl;
        cout<<"3. Delete First     |"<<endl;
        cout<<"4. Delete Last      |"<<endl;
        cout<<"5. Traversal        |"<<endl;
        cout<<"-------------------- "<<endl;
        cout << "Pilih nomor berapa?  "; cin >> pilihan;
        switch(pilihan){
        case 1:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 3:
            deleteFirst(first, pBaru);
        break;

        case 4:
            deleteLast(first, pBaru);
        break;

        case 5:
            traversal(first);
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}

void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new pegawai;
    cout<<"Nama Lengkap Pegawai    : "; cin>>pBaru->nama;
    cout<<"Divisi  :"; cin>>pBaru->divisi;
    cout<<"Gaji     : "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada  yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast (List& First, pointer& pHapus){
    pointer Last, precLast;
    if (First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL){
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}

void traversal (List First){
    pointer pBantu;
    pBantu=First;
    while(pBantu != NULL){
        cout<<"Nama     : "<<pBantu->nama<<endl;
        cout<<"Divisi   : "<<pBantu->divisi<<endl;
        cout<<"Gaji     : "<<pBantu->gaji<<endl;
        pBantu=pBantu->next;
    }
}
