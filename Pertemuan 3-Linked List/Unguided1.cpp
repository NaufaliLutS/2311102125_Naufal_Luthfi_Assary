// Laprak 3 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include<iostream>

using namespace std;

struct node{ 
    string Nama_125;
    int Umur_125;
    node *next;
};
    node *head; 
    node *tail; 


void Inisialisasi_125(){ // Inisialisasi list menjadi kosong dengan mengatur head dan tail menjadi NULL
    
    head = NULL;
    tail = NULL;
}

bool Kosong_125(){ // Fungsi untuk memeriksa apakah list kosong atau tidak
    if(head == NULL){
        return true; // Jika head NULL, maka list kosong
    } 
    else {
        return false; // Jika tidak, maka list tidak kosong
    }
}

void TambahDepan_125(string Name_125, int Age_125){ // Menambahkan node baru di depan list
    node *baru = new node; // Membuat node baru
    baru->Nama_125 = Name_125; // Mengisi data nama pada node baru
    baru->Umur_125 = Age_125; // Mengisi data umur pada node baru
    baru->next = NULL; 
    
    if(Kosong_125() == true){ // Jika list kosong
        head = tail = baru; // Node baru menjadi satu-satunya node dalam list
        tail->next = NULL; 
    } else {
        baru->next = head; // Node baru menunjuk ke node yang saat ini menjadi head
        head = baru; // Node baru menjadi head baru
    }
}

void TambahBelakang_125(string Name_125, int Age_125){ // Menambahkan node baru di belakang list
    node *baru = new node; // Membuat node baru
    baru->Nama_125 = Name_125; // Mengisi data nama pada node baru
    baru->Umur_125 = Age_125; // Mengisi data umur pada node baru
    baru->next = NULL; 
    
    if(Kosong_125() == true){ // Jika list kosong
        head = tail = baru; // Node baru menjadi satu-satunya node dalam list
        tail->next = NULL; 
    } else {
        tail->next = baru; // Node tail menunjuk ke node baru
        tail = baru; // Node baru menjadi tail baru
    }
}

int HitungNode_125(){ // Menghitung jumlah node dalam list
    node *hitung; 
    hitung = head; 
    int jumlah = 0;

    while(hitung != NULL){ // Selama belum mencapai akhir list
        jumlah++; // Menambah jumlah node
        hitung = hitung->next; // Beralih ke node selanjutnya
    }
    return jumlah; // Mengembalikan jumlah node
}

void TambahTengah_125(string Name_125, int Age_125, int Posisi_125){
    if(Posisi_125 < 1 || Posisi_125 > HitungNode_125()){ 
        cout << "Posisi node yang ditambahkan diluar jangkauan\n";
    } else if(Posisi_125 == 1){ 
        cout << "Posisi node yang akan ditambahkan bukan di tengah\n";
    } else {
       
        node *baru, *bantu;
        baru = new node; // Membuat node baru
        baru->Nama_125 = Name_125; // Mengisi data nama pada node baru
        baru->Umur_125 = Age_125; // Mengisi data umur pada node baru
        baru->next = NULL; 

        bantu = head; 
        int Nomor_125 = 1; 
        
        while(Nomor_125 < Posisi_125 - 1){ // Mencari posisi sebelum posisi yang ditentukan
            bantu = bantu->next; // Beralih ke node selanjutnya
            Nomor_125++; // Menambah nomor posisi
        }
        
        baru->next = bantu->next; 
        bantu->next = baru;  
    }
}


void HapusDepan_125(){ // Menghapus node pertama dalam list
    node* hapus; 

    if(Kosong_125() == false){ 
        if(head->next != NULL){ 
            hapus = head; 
            head = head->next; 
            delete hapus; 
        } 
        else { 
            head = tail = NULL; 
        }
    } 
    else { 
        cout << "List ini kosong!\n"; 
    }
}

void HapusBelakang_125(){ // Menghapus node terakhir dalam list
    node* hapus; 
    node* bantu; 
    if (Kosong_125() == false){ 
        if(head != tail){ 
            hapus = tail; 
            bantu = tail; 
            bantu = head; 

            while(bantu->next != tail){ 
                bantu = bantu->next; 
            }

            tail = bantu; 
            tail->next = NULL; 
            delete hapus;
        } 
        else {
            head = tail = NULL;
        }
    } 
    else {
        cout << "List ini kosong!\n";
    }
}

void HapusTengah_125(int Posisi_125){ // Menghapus node pada posisi tengah list
    node* hapus, * bantu, * bantu2;

    if(Posisi_125 < 1 || Posisi_125 > HitungNode_125()){ 
        cout << "Posisi node yang dihapus diluar jangkauan\n";
    } 
    else if(Posisi_125 == 1){
        cout << "Node yang dihapus bukan node tengah\n";
    } 
    else {
        int Nomor_125 = 1;
        bantu = head;
        
        while(Nomor_125 <= Posisi_125){
            if(Nomor_125 == Posisi_125 - 1){
                bantu2 = bantu;
            } 
            else if(Nomor_125 == Posisi_125){
                hapus = bantu;
            }
            bantu = bantu->next;
            Nomor_125++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

void UbahDepan_125(string Name_125, int Age_125){ // Mengubah data pada node pertama dalam list
    if(Kosong_125() == false){
        head->Nama_125 = Name_125;
        head->Umur_125 = Age_125;
    } 
    else {
        cout << "List ini kosong!\n";
    }
}

void UbahBelakang_125(string Name_125, int Age_125){ // Mengubah data pada node terakhir dalam list
    if(Kosong_125() == false){
        tail->Nama_125 = Name_125;
        tail->Umur_125 = Age_125;
    } 
    else {
        cout << "List ini kosong!\n";
    }
}

void UbahTengah_125(string Name_125, int Age_125, int Posisi_125){ // Mengubah data pada node di posisi tengah list
    node* bantu;

    if(Kosong_125() == false){
        if(Posisi_125 < 1 || Posisi_125 > HitungNode_125()){
            cout << "Node yang diubah diluar jangkauan\n";
        } 
        else if(Posisi_125 == 1){
            cout << "Node yang diubah bukan head\n";
        } 
        else {
            bantu = head;
            int Nomor_125 = 1;

            while(Nomor_125 < Posisi_125){
                Nomor_125++;
                bantu = bantu->next;
            }

            bantu->Nama_125 = Name_125;
            bantu->Umur_125 = Age_125;
        }
    } 
    else {
        cout << "List ini kosong!\n";
    }
}

void HapusList_125(){ // Menghapus seluruh isi list
    node* bantu, * hapus;
    bantu = head;

    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List telah terhapus!\n";
}

void TampilList_125(){ // Menampilkan seluruh isi list
    node* bantu;
    bantu = head;

    if(Kosong_125() == false){
        for(int i=0; i<=HitungNode_125() && bantu != NULL; i++){
            cout << bantu->Nama_125 << '\t' << bantu->Umur_125 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List ini kosong!\n";
    }
}

int main(){

    char Pilihan_125;

    MenuJawaban:
    cout << "---> Naufal-Menu Jawaban <---\n";
    cout << "A. Jawaban Poin A\n";
    cout << "B. Jawaban Poin B\n";
    cout << "C. Jawaban Poin C\n";
    cout << "D. Jawaban Poin D\n";
    cout << "E. Jawaban Poin E\n";
    cout << "F. Jawaban Poin F\n";
    cout << "G. Keluar\n";
    cout << "Pilihan anda : "; cin >> Pilihan_125;
    cout << endl;

    switch(Pilihan_125){

        case 'A':
            Inisialisasi_125();
            //Menjawab Poin A
            cout << "---> Naufal-Program Linked List <---\n";
            TambahDepan_125("Karin", 18);
            TambahDepan_125("Hoshino", 18);
            TambahDepan_125("Akechi", 20);
            TambahDepan_125("Yusuke", 19);
            TambahDepan_125("Michael", 18);
            TambahDepan_125("Jane", 20);
            TambahDepan_125("John", 19);
            TambahDepan_125("Naufal", 18);
            TampilList_125();
            goto MenuJawaban;
            break;

        case 'B':
            //Menjawab Poin B
            cout << "---> Penghapusan data 'Akechi' <---\n"; 
            HapusTengah_125(6);
            TampilList_125();
            goto MenuJawaban;
            break;

        case 'C':
            //Menjawab Poin C
            cout << "---> Penambahan data 'Futaba, 18' diantara John & Jane <---\n";
            TambahTengah_125("Futaba", 18, 3);
            TampilList_125();
            goto MenuJawaban;
            break;

        case 'D':
            //Menjawab Poin D
            cout << "---> Penambahan data 'Igor, 20' diawal <---\n";
            TambahDepan_125("Igor", 20);
            TampilList_125();
            goto MenuJawaban;
            break;

        case 'E':
            //Menjawab Poin E
            cout << "---> Mengubah data 'Michael' menjadi 'Reyn, 18' <---\n";
            UbahTengah_125("Reyn", 18, 6);
            TampilList_125();
            goto MenuJawaban;
            break;

        case 'F':
            //Menjawab Poin F
            cout << "---> Tampilan Akhir <---\n";
            TampilList_125();
            goto MenuJawaban;
            break;

        case 'G':
            cout << "Anda Telah Keluar dari Program ini\n";
            return 0;
            break;

        default:
            cout << "Pilihan Tidak Sesuai, Silahkan Coba Lagi\n";
            goto MenuJawaban;
            break;
    }
}