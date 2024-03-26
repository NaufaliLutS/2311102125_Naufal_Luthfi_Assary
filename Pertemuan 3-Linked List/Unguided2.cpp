// Laprak 3 - Unguided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include<iostream>
#include<iomanip>

using namespace std;

// Struktur data untuk node linked list
struct node{
    string Barang_125;
    int Harga_125;
    node *prev;
    node *next;
};
    node *head;
    node *tail;

// Prosedur inisialisasi linked list
void Inisialisasi_125(){
    head = nullptr;
    tail = nullptr;
}

// Prosedur untuk menambahkan node baru ke linked list
void TambahNode_125(string Produk_125, int Harga_125, int Posisi_125){
    if(Posisi_125 < 1 ){
        cout << "Node yang ditambah diluar Jangkauan\n";
    } else if(Posisi_125 == 1){
        node *baru = new node;
        baru->Barang_125 = Produk_125;
        baru->Harga_125 = Harga_125;
        baru->next = head;
        baru->prev = nullptr;
        if(head != nullptr){
            head->prev = baru;
        } else {
            tail = baru;
        }
        head = baru;
    } else {
        node *current = head;
        node *baru = new node;
        baru->Barang_125 = Produk_125;
        baru->Harga_125 = Harga_125;
        baru->next = nullptr;
        baru->prev = nullptr;
        int Hitung_125 = 1;
        while(Hitung_125 < Posisi_125 - 1){
            Hitung_125++;
            current = current->next;
        }
        baru->next = current->next;
        baru->prev = current;
        if(current->next != nullptr){
            current->next->prev = baru;
        } else {
            tail = baru;
        }
        current->next = baru;
    }
}

// Prosedur untuk menghapus node dari linked list
void HapusNode_125(int Posisi_125){
    if(Posisi_125 < 1){
        cout << "Posisi Node yang dihapus diluar Jangkauan\n";
    } else if(Posisi_125 == 1){
        node *current = head;  
        head = head->next;     
        if(head != nullptr) {
            head->prev = nullptr;  
        }
        delete current; 
    } else {
        node *current = head;
        int Hitung_125 = 1;
        while(Hitung_125 < Posisi_125){
            Hitung_125++;
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
}

// Fungsi untuk memperbarui data pada linked list
bool UpdateData_125(string ProdukLama_125, string ProdukBaru_125, int HargaBaru_125){
    node *current = head;
    while (current != nullptr){
        if(current->Barang_125 == ProdukLama_125){
            current->Barang_125 = ProdukBaru_125;
            current->Harga_125 = HargaBaru_125;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Prosedur untuk menghapus semua data dari linked list
void HapusSemua_125(){
    node *current = head;
    while(current != nullptr){
        node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}

// Prosedur untuk menampilkan data dalam linked list
void TampilData_125(){
    node *current = head;
    if(head != nullptr){
        cout << left << setw(20) << "- Nama Produk -" << right << setw(5) << "- Harga -" << endl; 
        while(current != nullptr){
            cout << left << setw(20) << current->Barang_125 << right << setw(7) << current->Harga_125 << endl; 
            current = current->next;
        }
    }
    cout << endl;
}

int main(){
    int Pilih_125, HargaBaru_125, PosisiProduk_125;
    string ProdukBaru_125, ProdukLama_125;
    
    Inisialisasi_125();
    cout << "---> Daftar Produk Skincare <---\n";
    TambahNode_125("Hanasui", 30000, 1 );
    TambahNode_125("Wardah", 50000, 1);
    TambahNode_125("Skintific", 100000, 1);
    TambahNode_125("Somethinc", 150000, 1);
    TambahNode_125("Originote", 60000, 1);
    TampilData_125();

    MenuSkincare:
    cout << "---> Naufal-Toko Skincare Purwokerto <---\n";
    cout << "1. Tambah Data\n";
    cout << "2. Hapus Data\n";
    cout << "3. Update Data\n";
    cout << "4. Tambah Data Urutan Tertentu\n";
    cout << "5. Hapus Data Urutan Tertentu\n";
    cout << "6. Hapus Seluruh Data\n";
    cout << "7. Tampilkan Data\n";
    cout << "8. Keluar\n";
    cout << "Pilihan anda : "; cin >> Pilih_125;
    cout << endl;

    switch(Pilih_125){
        case 1 :
            cout << "---> Tambah Data <---\n";
            cout << "Masukkan Nama Produk : "; cin >> ProdukBaru_125;
            cout << "Masukkan Harga Produk : "; cin >> HargaBaru_125;
            TambahNode_125(ProdukBaru_125, HargaBaru_125, 1);
            cout << "Produk Berhasil ditambahkan\n";
            cout << endl;
            goto MenuSkincare;
            break;
        case 2 :
            cout << "---> Hapus Data <--- \n";
            HapusNode_125(1);
            cout << "Data produk Pertama Berhasil dihapus\n";
            cout << endl;
            goto MenuSkincare;
            break;
        case 3 :
            cout << "---> Update Data <---\n";
            cout << "Masukkan Nama Produk yang ingin diubah : ";cin >> ProdukLama_125;
            cout << "Masukkan Nama Produk Baru : "; cin >> ProdukBaru_125;
            cout << "Masukkan Harga Produk Baru : "; cin >> HargaBaru_125;
            UpdateData_125(ProdukLama_125, ProdukBaru_125, HargaBaru_125);
            cout << "Produk Berhasil diperbarui\n";
            cout << endl;
            goto MenuSkincare;
            break;
        case 4 :
            cout << "---> Tambah Data Urutan Tertentu <---\n";
            cout << "Masukkan Nama Produk Baru : "; cin >> ProdukBaru_125;
            cout << "Masukkan Harga Produk Baru : "; cin >> HargaBaru_125;
            cout << "Masukkan Posisi untuk Produk Baru : "; cin >> PosisiProduk_125;
            TambahNode_125(ProdukBaru_125, HargaBaru_125, PosisiProduk_125);
            cout << "Produk Berhasil ditambahkan\n";
            cout << endl;
            goto MenuSkincare;
            break;
        case 5 :
            cout << "---> Hapus Data Urutan Tertentu <---\n";
            cout << "Masukkan Posisi Produk yang dihapus : "; cin >> PosisiProduk_125;
            HapusNode_125(PosisiProduk_125);
            cout << "Data Produk Posisi ke-" << PosisiProduk_125 << " Berhasil dihapus\n";
            cout << endl;
            goto MenuSkincare;
            break;
        case 6 :
            cout << "---> Hapus Seluruh Data <---\n";
            HapusSemua_125();
            cout << "Seluruh Data Produk Berhasil dihapus\n";
            goto MenuSkincare;
            break;
        case 7 :
            cout << "---> Tampilkan Data <---\n";
            TampilData_125();
            cout << endl;
            goto MenuSkincare;
            break;
        case 8 :
            cout << "Terimakasih, Anda Telah Keluar Dari Program Ini\n";
            return 0;
        default :
            cout << "Pilihan Anda Tidak Valid!\n";
            cout << endl;
            goto MenuSkincare;
            break;
    }    
}