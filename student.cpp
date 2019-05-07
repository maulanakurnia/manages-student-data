#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
 
void garis(){
    cout << "------------------------------------------------------------------------------\n";
}
 
struct data_matkul{
    char kode[100];
    char namkul[20];
    char dosen[20];
    double nilai;
    string nilhur;
         
};int mhs,sks;
 
struct data_mhs{
    char nim[10];
    char nama[20];
    int jumsks;
    double ipk;
    double harkat;
    int banyak;
    data_matkul matkul[10];
     
}mahasiswa[100];
 
void ipk(){
        for (int i = 0; i < mhs; i++){
         
        for (int j = 0; j < mahasiswa[i].banyak; j++){
            mahasiswa[i].jumsks=sks;
            mahasiswa[i].ipk = (mahasiswa[i].harkat*sks);
        }
        mahasiswa[i].ipk = mahasiswa[i].ipk/mahasiswa[i].jumsks;
    }
}
 
int main(){
    int i,j,jumsks;
    cout << "Jumlah Mahsiswa : "; cin >> mhs;
    cout <<"\tInput Data\n";
     
    for (i=0; i<mhs; i++){
        jumsks=0;
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "NIM                : "; cin >> mahasiswa[i].nim;
        cin.ignore();
        cout << "Nama               : "; cin.getline(mahasiswa[i].nama, sizeof(mahasiswa[i].nama));
        cout << "Jumlah Mata Kuliah : "; cin >> mahasiswa[i].banyak;
         
        for (j=0; j<mahasiswa[i].banyak; j++){
                cout << "\n\tMata Kuliah Ke-" << j+1 << endl;
                cout << "\t\tKode  : "; cin >> mahasiswa[i].matkul[j].kode;
                cin.ignore();
                cout << "\t\tNama  : "; cin.getline(mahasiswa[i].matkul[j].namkul, sizeof(mahasiswa[i].matkul[j].namkul));
                cout << "\t\tDosen : "; cin.getline(mahasiswa[i].matkul[j].dosen, sizeof(mahasiswa[i].matkul[j].dosen));
                cout << "\t\tNilai : "; cin >> mahasiswa[i].matkul[j].nilai;
                cout << "\t\tSKS   : "; cin >> sks;
                jumsks=jumsks+sks;
                 
                 
                    if ((mahasiswa[i].matkul[j].nilai <= 100) && (mahasiswa[i].matkul[j].nilai > 80)){mahasiswa[i].matkul[j].nilhur='A'; mahasiswa[i].harkat=4;}
                    if ((mahasiswa[i].matkul[j].nilai <= 80)  && (mahasiswa[i].matkul[j].nilai > 75)){mahasiswa[i].matkul[j].nilhur="B+"; mahasiswa[i].harkat=3.5;}
                    if ((mahasiswa[i].matkul[j].nilai <= 75)  && (mahasiswa[i].matkul[j].nilai > 65)){mahasiswa[i].matkul[j].nilhur='B'; mahasiswa[i].harkat=3;}  
                    if ((mahasiswa[i].matkul[j].nilai <= 65)  && (mahasiswa[i].matkul[j].nilai > 60)){mahasiswa[i].matkul[j].nilhur="C+"; mahasiswa[i].harkat=2.5;}
                    if ((mahasiswa[i].matkul[j].nilai <= 60)  && (mahasiswa[i].matkul[j].nilai > 50)){mahasiswa[i].matkul[j].nilhur='C'; mahasiswa[i].harkat=2;}
                    if ((mahasiswa[i].matkul[j].nilai <= 50)  && (mahasiswa[i].matkul[j].nilai > 30)){mahasiswa[i].matkul[j].nilhur='D'; mahasiswa[i].harkat=1;}
                    if ((mahasiswa[i].matkul[j].nilai <= 30)  && (mahasiswa[i].matkul[j].nilai > 0)) {mahasiswa[i].matkul[j].nilhur='E'; mahasiswa[i].harkat=0;}  
                 
        }
        mahasiswa[i].jumsks=jumsks;
    }
    ipk();
    cout << "\n Output Data\n";
     
        for (i=0; i<mhs; i++){
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "NIM        : " << mahasiswa[i].nim << endl;
        cout << "Nama       : " << mahasiswa[i].nama << endl;
        cout << "Jumlah SKS : " << mahasiswa[i].jumsks << endl;
        cout << "IPK        : " << mahasiswa[i].ipk << endl;
         
         
            garis();
            cout << "No" << setw(8) << "Kode" << setw(25)<< "Nama Mata Kuliah"<< setw(20) << "Pengampu"<< setw(20) << "Nilai" <<endl;
            garis();    
            for(j=0; j<mahasiswa[i].banyak;j++){     
            cout << setiosflags(ios::left) << setw(6) << j+1 << setw(13) <<mahasiswa[i].matkul[j].kode << setw(28)<< mahasiswa[i].matkul[j].namkul  << setw(25) << mahasiswa[i].matkul[j].dosen  <<  setw(34) << mahasiswa[i].matkul[j].nilhur << endl;
            }
             
         
            }
     
}
