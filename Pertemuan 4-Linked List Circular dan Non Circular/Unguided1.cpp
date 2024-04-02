// Laprak 4 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include<iostream>
#include<iomanip>

using namespace std;

// deklarasi struct node
struct node{
    string Nama_125;
    string NIM_125;
    node *next;
};
    node *head;
    node *tail;

// Inisialisasi node head & tail
void Inisialisasi_125(){
    head = NULL;
    tail = NULL;
}

// fungsi pengecekan
bool isEmpty_125(){
    if(head == NULL){
        return true;
    } else {
        return false;
    }
}

// prosedur hitung node
int HitungNode_125(){
    node *hitung = head;
    int jumlah_125 = 0;
    while (hitung != NULL){
        hitung = hitung->next;
        jumlah_125++;
    }
    return jumlah_125;
}

// prosedur tambah depan
void TambahDepan_125(string Nama, string NIM){
    node *baru = new node;
    baru->Nama_125 = Nama;
    baru->NIM_125 = NIM;
    baru->next = NULL;
    if(isEmpty_125() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

// prosedur tambah belakang
void TambahBelakang_125(string Nama, string NIM){
    node *baru = new node;
    baru->Nama_125 = Nama;
    baru->NIM_125 = NIM;
    baru->next = NULL;
    if(isEmpty_125() == true){
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// prosedur tambah tengah
void TambahTengah_125(string Nama, string NIM, int Posisi){
    if(Posisi < 1 || Posisi > HitungNode_125()){
        cout << "Node yang ingin ditambah diluar jangkauan!\n";
    } else if(Posisi == 1){
        cout << "Node yang ingin ditambah bukan ditengah!\n";
    } else {
        node *bantu = head;
        node *baru = new node;
        baru->Nama_125 = Nama;
        baru->NIM_125 = NIM;
        int hitung_125 = 1;
        while(hitung_125 < Posisi - 1){
            bantu = bantu->next;
            hitung_125++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// prosedur hapus depan
void HapusDepan_125(){
    node *hapus;
    if(isEmpty_125() == true){
        cout << "List ini kosong!\n";
    } else {
        if(head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

// fungsi tampil data depan
string TampilDepan_125(){
    string NamaYangDihapus_125 = "";
    if(isEmpty_125() == false){
        NamaYangDihapus_125 = head->Nama_125;
    } else {
        cout << "List ini kosong\n";
    }
    return NamaYangDihapus_125;
}

// prosedur hapus belakang
void HapusBelakang_125(){
    node *hapus, *bantu;
    if(isEmpty_125() == true){
        cout << "List ini kosong!\n";
    } else {
        if(head != tail){
            hapus = tail;
            bantu = head;
            while(bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    }
}

// fungsi tampil data belakang
string TampilBelakang_125(){
    string NamaYangDihapus_125 = "";
    if(isEmpty_125() == false){
        NamaYangDihapus_125 = tail->Nama_125;
    } else {
        cout << "List ini kosong\n";
    }
    return NamaYangDihapus_125;
}


// prosedur hapus tengah
void HapusTengah_125(int posisi_125){
    if(posisi_125 < 1 || posisi_125 > HitungNode_125()){ 
        cout << "Posisi node yang akan dihapus offside\n";
    } else if(posisi_125 == 1){
        cout << "Node yang ingin dihapus bukan node tengah\n";
    } else {
        node *hapus, *bantu, *bantu2;
        bantu = head;
        int nomor_125 = 1;
        while(nomor_125 <= posisi_125){
            if(nomor_125 == posisi_125 - 1){
                bantu2 = bantu;
            } else if(nomor_125 == posisi_125){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor_125++; 
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

// fungsi tampil data tengah
string TampilTengah_125(int Posisi){
    string NamaYangDihapus_125 = "";
    node *tampil = head;
    node *bantu;
    if(isEmpty_125() == false){
        int nomor_125 = 1;
        while (nomor_125 <= Posisi - 1){
            if(nomor_125 == Posisi - 1){
                bantu = tampil;
            }
            tampil = tampil->next;
            nomor_125++;
        }
        bantu->next = tampil;
        NamaYangDihapus_125 = tampil->Nama_125;       
    } else {
        cout << "List ini kosong\n";
    }
    return NamaYangDihapus_125;
}

// prosedur Ubah depan
void UbahDepan_125(string NewName, string NewNIM){
    if(isEmpty_125() == true){
        cout << "List ini kosong!\n";
    } else {
        head->Nama_125 = NewName;
        head->NIM_125 = NewNIM;
    }
}

// prosedur ubah belakang
void UbahBelakang_125(string NewName, string NewNIM){
    if(isEmpty_125() == true){
        cout << "List ini kosong!\n";
    } else {
        tail->Nama_125 = NewName;
        tail->NIM_125 = NewNIM;
    }
}

// prosedur ubah tengah
void UbahTengah_125(string NewName, string NewNIM, int Posisi){
    if(isEmpty_125() == true){
        cout << "List ini kosong!\n";
    } else {
        if(Posisi < 1 || Posisi > HitungNode_125()){
            cout << "Node yang ingin diubah diluar jangkauan!\n";
        } else if(Posisi == 1){
            cout << "Node yang ingin diubah bukan ditengah!\n";
        } else {
            node *bantu;
            bantu = head;
            int nomor_125 = 1;
            while(nomor_125 < Posisi){
                bantu = bantu->next;
                nomor_125++;
            }
           bantu->Nama_125 = NewName;
           bantu->NIM_125 = NewNIM;
        }
    }
}

// prosedur hapus list
void HapusList_125(){
    node *hapus;
    node *bantu = head;
    if(isEmpty_125() == true){
        cout << "List ini kosong!\n";
    } else {
        while(bantu != NULL){
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;   
        }
        head = tail = NULL;
    }
}

// prosedur tampil list
void TampilList_125(){
    node *bantu = head;
    if(isEmpty_125() == true){
        cout << "List ini kosong!\n";
    } else {
        cout << "------------------------------------------\n";
        cout << "|         NAMA         |       NIM       |\n";
        cout << "------------------------------------------\n";
        while(bantu != NULL){
            cout << "|" << setw(22) << left << bantu->Nama_125 << "|" << setw(17) << left << bantu->NIM_125 << "|" << endl;
            bantu = bantu->next;
        }
        cout << "------------------------------------------\n";
    }
}

int main(){
    int Posisi, Pilih;
    string Nama, NamaLama, NIM, NIMLama;
    Inisialisasi_125();
    MenuUtama:
    cout << "-----------------------------------------------------\n";
    cout << "|------> NAUFAL'S PROGRAM SINGLE LINKED LIST <------|\n";
    cout << "|------------------- NON-CIRCULAR ------------------|\n"; 
    cout << "| 1. TAMBAH DEPAN                                   |\n";
    cout << "| 2. TAMBAH BELAKANG                                |\n";
    cout << "| 3. TAMBAH TENGAH                                  |\n";
    cout << "| 4. UBAH DEPAN                                     |\n";
    cout << "| 5. UBAH BELAKANG                                  |\n";
    cout << "| 6. UBAH TENGAH                                    |\n";
    cout << "| 7. HAPUS DEPAN                                    |\n";
    cout << "| 8. HAPUS BELAKANG                                 |\n";
    cout << "| 9. HAPUS TENGAH                                   |\n";
    cout << "| 10. HAPUS LIST                                    |\n";
    cout << "| 11. TAMPILKAN                                     |\n";
    cout << "| 0. KELUAR                                         |\n";
    cout << "-----------------------------------------------------\n";
    cout << "Masukkan pilihan anda = ";
    cin >> Pilih;
    cout << endl;
    switch(Pilih){
        case 1:
            cout << "--------------> TAMBAH DEPAN <--------------\n";
            cout << "-- Masukkan data yang ingin ditambahkan --\n";
            cout << "Nama Mahasiswa = ";
            cin >> Nama;
            cout << "NIM Mahasiswa = ";
            cin >> NIM;
            TambahDepan_125(Nama, NIM);
            cout << "Data berhasil ditambahkan\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            cout << "------------> TAMBAH BELAKANG <-------------\n";
            cout << "-- Masukkan data yang ingin ditambahkan --\n";
            cout << "Nama Mahasiswa = ";
            cin >> Nama;
            cout << "NIM Mahasiswa = ";
            cin >> NIM;
            TambahBelakang_125(Nama, NIM);
            cout << "Data berhasil ditambahkan\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            cout << "--------------> TAMBAH TENGAH <-------------\n";
            cout << "-- Masukkan data yang ingin ditambahkan --\n";
            cout << "Nama Mahasiswa = ";
            cin >> Nama;
            cout << "NIM Mahasiswa = ";
            cin >> NIM;
            cout << "Masukkan posisi yang ingin ditambahkan = ";
            cin >> Posisi;
            TambahTengah_125(Nama, NIM, Posisi);
            cout << "Data berhasil ditambahkan\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 4:
            cout << "----------------> UBAH DEPAN <--------------\n";
            cout << "-- Masukkan data yang ingin diubah pada --\n";
            cout << "---------------- urutan pertama ----------\n";
            cout << "Nama Mahasiswa baru = ";
            cin >> Nama;
            cout << "NIM Mahasiswa baru = ";
            cin >> NIM;
            UbahDepan_125(Nama, NIM);
            cout << "Data berhasil diubah\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 5:
            cout << "-------------> UBAH BELAKANG <--------------\n";
            cout << "-- Masukkan data yang ingin diubah pada --\n";
            cout << "--------------- urutan terakhir ----------\n";
            cout << "Nama Mahasiswa baru = ";
            cin >> Nama;
            cout << "NIM Mahasiswa baru = ";
            cin >> NIM;
            UbahBelakang_125(Nama, NIM);
            cout << "Data berhasil diubah\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 6:
            cout << "--------------> UBAH TENGAH <---------------\n";
            cout << "-- Masukkan data yang ingin diubah pada --\n";
            cout << "---------- urutan tengah tertentu --------\n";
            cout << "Nama Mahasiswa baru = ";
            cin >> Nama;
            cout << "NIM Mahasiswa baru = ";
            cin >> NIM;
            cout << "Masukkan posisi yang ingin diubah = ";
            cin >> Posisi;
            UbahTengah_125(Nama, NIM, Posisi);
            cout << "Data berhasil diubah\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 7:
            cout << "--------------> HAPUS DEPAN <---------------\n";
            HapusDepan_125();
            cout << "Data berhasil dihapus\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 8:
            cout << "-------------> HAPUS BELAKANG <-------------\n";
            HapusBelakang_125();
            cout << "Data berhasil dihapus\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 9:
            cout << "--------------> HAPUS TENGAH <--------------\n";
            cout << "-- Masukkan posisi data yang ingin dihapus\n";
            cout << "Posisi data = ";
            cin >> Posisi;
            HapusTengah_125(Posisi);
            cout << "Data berhasil dihapus\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 10:
            cout << "---------------> HAPUS LIST <----------------\n";
            HapusList_125();
            cout << "List berhasil dihapus\n";
            cout << endl;
            goto MenuUtama;
            break;
        case 11:
            cout << "---------------> TAMPILKAN <-----------------\n";
            TampilList_125();
            cout << endl;
            goto MenuUtama;
            break;
        case 0:
            cout << "-----------------> KELUAR <------------------\n";
            cout << "Teramakasih, Anda Telah Keluar dari Program Ini\n";
            break;
        default:
            cout << "Pilihan tidak tersedia!\n";
            goto MenuUtama;
            break;
    }
}
