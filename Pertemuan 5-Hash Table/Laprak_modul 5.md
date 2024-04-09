# <h1 align="center">Laporan Praktikum Modul 4 - Linked List Circular dan Non Circular</h1>
<p align="center">Naufal Luthfi Assary</p>
<p align="center">2311102125</p>

## Dasar Teori

Hash table adalah struktur data yang efisien digunakan untuk menyimpan dan mengakses data secara asosiatif. Dalam hash table, data disimpan dalam format array, di mana setiap nilai memiliki indeks uniknya sendiri. Ini memungkinkan akses data yang cepat, terutama jika pengguna mengetahui indeks data yang diinginkan. Sebagai hasilnya, hash table menjadi solusi yang sangat cepat untuk operasi penyisipan dan pencarian data, tidak peduli seberapa besar ukuran datanya. Penggunaan array sebagai media penyimpanan, bersama dengan teknik hashing, memungkinkan pengaksesan data yang efisien.

Fungsi utama dari hash table adalah untuk mempercepat proses akses data, yang sangat penting dalam konteks peningkatan volume data yang diproses dalam jaringan global dan lokal. Pengembangan dan penerapan hash table meluas di berbagai bidang karena menawarkan kelebihan dalam efisiensi operasi waktu, mulai dari pengarsipan hingga pencarian data. Sebagai contoh, dalam bidang jaringan komputer, hash table dikembangkan menjadi hybrid open hash table untuk memproses jaringan komputer dengan efisiensi yang tinggi.

Proses pembuatan hash table dimulai dengan alokasi memori yang sesuai, mirip dengan pembuatan array. Pengguna kemudian perlu membuat indeks berdasarkan kunci menggunakan fungsi hash. Ini penting karena indeks yang dihasilkan harus cocok dengan potongan memori yang dialokasikan. Saat menempatkan data baru dalam hash table, dua pemeriksaan penting dilakukan: nilai hash dari kunci dan bagaimana nilainya dibandingkan dengan objek lain. Di Python, ini dilakukan dengan meng-hash dan mem-mask kunci saat data dimasukkan, mengubahnya menjadi larik atau indeks yang efisien.

Hash table bekerja dengan inisialisasi awal menggunakan ukuran tertentu, biasanya bilangan prima, yang dapat disesuaikan sesuai kebutuhan. Fungsi hash digunakan untuk memetakan nilai yang diberikan dengan kunci tertentu ke indeks dalam array. Ini memastikan bahwa elemen-elemen dapat disimpan dengan benar, sehingga pemetaan nilai berfungsi dengan baik ketika elemen baru ditambahkan. Penanganan bentrokan diperlukan karena beberapa kunci yang berbeda dapat menghasilkan nilai hash yang sama. Metode umum untuk menangani bentrokan termasuk chaining dan probing.

Operasi utama yang dilakukan dalam hash table meliputi pencarian, penambahan, dan penghapusan elemen. Fungsi hash digunakan dalam operasi ini untuk menentukan indeks elemen yang akan diakses atau dimodifikasi. Efisiensi hash table sangat bergantung pada fungsi hash yang merata dan ukuran hash table yang sesuai. Penanganan collision diperlukan untuk memastikan bahwa elemen-elemen dengan indeks yang sama dapat disimpan dan diakses dengan benar.

Resize hash table dilakukan jika jumlah elemen melebihi kapasitas yang ditentukan, menjaga efisiensi dan kinerja hash table. Iterasi digunakan untuk mengakses dan memproses semua elemen dalam hash table secara berurutan. Dengan demikian, hash table menjadi alat yang sangat berguna dalam memproses dan mengakses data dengan efisiensi tinggi.

## Guided 

### 1. Linked List Non Circular

```C++
// Laprak 5 - Guided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
using namespace std;
const int MAX_SIZE = 10;
// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}

```

Deskripsi:

Program tersebut adalah implementasi dari struktur data tabel hash dengan metode chaining untuk menyimpan dan mengelola data menggunakan kelas HashTable. Program ini memiliki fungsi hash sederhana untuk menghasilkan indeks dalam tabel hash berdasarkan kunci yang diberikan. Setiap elemen dalam tabel hash direpresentasikan sebagai linked list dari node-node yang menyimpan pasangan kunci-nilai. Program menyediakan fungsi untuk menambahkan (insert), mencari (get), menghapus (remove), dan menelusuri (traverse) data dalam tabel hash. Program juga memberikan contoh penggunaan dengan melakukan operasi-insert, search, remove, dan traversal pada tabel hash yang dibuat.

### 2. Linked List Circular

```C++
// Laprak 5 - Guided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah: " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah: " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus: " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table: " << endl;
    employee_map.print();

    return 0;
}

```
Program tersebut adalah implementasi dari struktur data tabel hash untuk menyimpan dan mengelola data karyawan berupa nama dan nomor telepon. Program ini memiliki kelas HashMap yang menyediakan metode untuk menambah, menghapus, mencari, dan menampilkan data karyawan. Setiap elemen dalam tabel hash direpresentasikan sebagai objek dari kelas HashNode, yang menyimpan nama dan nomor telepon karyawan. Program juga menyediakan fungsi hashFunc untuk menghasilkan nilai hash dari nama karyawan sebagai indeks tabel hash. Program mencakup contoh penggunaan dengan memasukkan data karyawan, mencari nomor telepon berdasarkan nama, menghapus entri, dan menampilkan isi tabel hash setelah operasi dilakukan.

## Unguided 

### 1.  Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
### a. Setiap mahasiswa memiliki NIM dan nilai.
### b. Program memiliki tampilan pilihan menu berisi poin C.
### c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
// Laprak 5 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include<iostream>
#include<vector> 
#include<iomanip>

using namespace std;

// Deklarasi untuk ukuran tabel hash
const int TableSize_125 = 100;

// Deklarasi Kelas untuk node dalam tabel hash
class HashNode_125{
    public:
    string nama_125; // Nama mahasiswa
    string NIM_125; // NIM mahasiswa
    int nilai_125; // Nilai mahasiswa

    // Konstruktor untuk inisialisasi node
    HashNode_125(string name_125, string NIM_125, int grade_125){
        this->nama_125 = name_125;
        this->NIM_125 = NIM_125;
        this->nilai_125 = grade_125;
    }
};

// Kelas untuk tabel hash
class HashMap_125{
    private: 
    vector<HashNode_125*> table[TableSize_125]; // Array dari vektor node untuk tabel hash

    public:
    // Fungsi hash sederhana
    int hashFunc_125(string key_125){
        int hashValue_125 = 0;
        for(char c : key_125){
            hashValue_125 += c;
        }
        return hashValue_125 % TableSize_125;
    }

    // Fungsi untuk menambahkan data ke dalam tabel hash
    void Tambah_125(string name_125, string NIM_125, int grade_125){
        int hashValue_125 = hashFunc_125(name_125); 

        // Memeriksa apakah data dengan nama yang sama sudah ada dalam tabel hash
        for(auto node : table[hashValue_125]){
            if(node->nama_125 == name_125){ 
                // Jika sudah ada, update NIM dan nilai
                node->NIM_125 = NIM_125; 
                node->nilai_125 = grade_125; 
                return;
            }
        }
        // Jika tidak ada, tambahkan data baru ke dalam vektor di indeks hash yang sesuai
        table[hashValue_125].push_back(new HashNode_125(name_125, NIM_125, grade_125));
    }

    // Fungsi untuk memeriksa keberadaan data dalam tabel hash berdasarkan nama
    bool CekData_125(string name_125){
        int hashValue_125 = hashFunc_125(name_125);

        // Iterasi melalui vektor pada indeks hash yang sesuai
        for(auto node = table[hashValue_125].begin(); node != table[hashValue_125].end(); node++){
            if((*node)->nama_125 == name_125){
                return true; 
            } 
        }
        return false;
    }
 
    // Fungsi untuk memeriksa apakah tabel hash kosong
    bool IsEmpty_125() {
        for (int i = 0; i < TableSize_125; i++) {
            if (!table[i].empty()) {
                return false;
            }
        }
        return true;
    }

    // Fungsi untuk menghapus data dari tabel hash berdasarkan nama
    void Hapus_125(string name_125){
        int hashValue_125 = hashFunc_125(name_125); 

        // Iterasi melalui vektor pada indeks hash yang sesuai
        for(auto node = table[hashValue_125].begin(); node != table[hashValue_125].end(); node++){
            if((*node)->nama_125 == name_125){ 
                table[hashValue_125].erase(node); 
                return;
            } else { 
                cout << "Data mahasiswa " << name_125 << " Tidak Ada" << endl;
            }
        }
    }

    // Fungsi untuk mencari data dalam tabel hash berdasarkan NIM
    void SearchByNIM_125(string NIM_125){
        bool ketemu = false; 
        cout << "Data Mahasiswa --->" << endl;
        cout << "=============================================\n";
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "=============================================\n";
        for(int i=0; i < TableSize_125; i++){
            // Iterasi melalui vektor pada indeks hash yang sesuai
            for(auto node : table[i]){
                if(node->NIM_125 == NIM_125){ 
                    cout << "|" << left << setw(14) << node->nama_125 << "|" << left << setw(14) << node->NIM_125 << "|" << left << setw(13) << node->nilai_125 << "|" << endl;
                    ketemu = true; 
                }
            }
        }
        if(!ketemu){ 
            cout << "Data Mahasiswa dengan NIM " << NIM_125 << " Tidak Ada" << endl;
        }
        cout << "=============================================\n";
    }

    // Fungsi untuk mencari data dalam tabel hash berdasarkan rentang nilai
    void SearchByGrade_125(int min_125, int max_125){
        bool ketemu = false; 
        cout << "Data Mahasiswa --->" << endl;
        cout << "=============================================\n";
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "=============================================\n";
        for (int i=0; i < TableSize_125; i++){
            // Iterasi melalui vektor pada indeks hash yang sesuai
            for(auto node : table[i]){
                if(node->nilai_125 >= min_125 && node->nilai_125 <= max_125){ 
                    cout << "|" << left << setw(14) << node->nama_125 << "|" << left << setw(14) << node->NIM_125 << "|" << left << setw(13) << node->nilai_125 << "|" << endl;
                    ketemu = true;
                }
            }
        }
        if(!ketemu){ 
            cout << "Data Mahasiswa dengan Nilai " << min_125 << " - " << max_125 << " Tidak Ada" << endl;
        }
        cout << "=============================================\n";
    }

    // Fungsi untuk menampilkan semua data dalam tabel hash
    void TampilData_125(){
        for(int i=0; i < TableSize_125; i++){
            // Iterasi melalui vektor pada indeks hash yang sesuai
            for(auto node : table[i]){ 
            cout << "|" << left << setw(14) << node->nama_125 << "|" << left << setw(14) << node->NIM_125 << "|" << left << setw(13) << node->nilai_125 << "|" << endl;
            }
        }
        cout << "=============================================\n";
    }
};

// Fungsi utama
int main(){
    HashMap_125 StudentMap; // Membuat objek dari kelas HashMap_125 untuk menyimpan data mahasiswa
    int choose_125, grade_125, GradeMin_125, GradeMax_125; // Variabel untuk pilihan, nilai, dan rentang nilai
    string name_125, NIM_125; // Variabel untuk nama dan NIM mahasiswa
    MenuUtama:
    // Menampilkan menu utama
    cout << "=============================================\n";
    cout << "|--------> Naufal'S Data Mahasiswa <--------|\n";
    cout << "=============================================\n";
    cout << "| 1. Tambah Data                            |\n";
    cout << "| 2. Hapus Data                             |\n";
    cout << "| 3. Cari Data Mahasiswa Berdasarkan NIM    |\n";
    cout << "| 4. Cari Data Mahasiswa Berdasarkan Nilai  |\n";
    cout << "| 5. Tampilkan Data                         |\n";
    cout << "| 6. Keluar                                 |\n";
    cout << "=============================================\n";
    cout << "Masukkan Pilihan Anda = ";
    cin >> choose_125; // Meminta input pilihan
    cout << endl;

    switch(choose_125){ 
        case 1: 
            // Pilihan untuk menambah data
            cout << "Tambah Data --->\n";
            cout << "Masukkan Nama Mahasiswa : "; cin >> name_125;
            cout << "Masukkan NIM Mahasiswa : "; cin >> NIM_125;
            cout << "Masukkan Nilai Mahasiswa : "; cin >> grade_125;
            StudentMap.Tambah_125(name_125, NIM_125, grade_125); 
            cout << "Data Mahasiswa " << name_125 << " Berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            // Pilihan untuk menghapus data
            cout << "Hapus Data --->\n";
            if(StudentMap.IsEmpty_125() == false){ 
                cout << "Masukkan Nama Mahasiswa yang Ingin dihapus : "; cin >> name_125;
                StudentMap.CekData_125(name_125);
                if(StudentMap.CekData_125(name_125) == true){ 
                        StudentMap.Hapus_125(name_125); 
                        cout << "Data Mahasiswa " << name_125 << " Berhasil dihapus" << endl;
                } else { 
                    cout << "Data mahasiswa " << name_125 << " Tidak Dapat ditemukan" << endl;
                }
            } else { 
                cout << "Tabel ini masih kosong!\n";
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            // Pilihan untuk mencari data berdasarkan NIM
            cout << "Cari Data Mahasiswa Berdasarkan NIM --->\n";
            if(StudentMap.IsEmpty_125() == false){
                cout << "Masukkan NIM = "; cin >> NIM_125;
                cout << endl;
                StudentMap.SearchByNIM_125(NIM_125); 
            } else { 
                cout << "Tabel ini masih kosong!\n";
            }
            cout << endl;
            goto MenuUtama; 
            break;
        case 4: 
            // Pilihan untuk mencari data berdasarkan rentang nilai
            cout << "Cari Data Mahasiswa Berdasarkan Nilai --->\n";
            if(StudentMap.IsEmpty_125() == false){ 
                cout << "Masukkan Nilai Minimal : "; cin >> GradeMin_125;
                cout << "Masukkan Nilai Maksimal : "; cin >> GradeMax_125;
                cout << endl;
                StudentMap.SearchByGrade_125(GradeMin_125,GradeMax_125); 
            } else { 
                cout << "Tabel ini masih kosong!\n";
            }
            cout << endl;
            goto MenuUtama; 
            break;
        case 5: 
            // Pilihan untuk menampilkan semua data
            cout << "Tampil Data --->\n";
            if(StudentMap.IsEmpty_125() == false){
                cout << "=============================================\n";
                cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
                cout << "=============================================\n";
                StudentMap.TampilData_125(); 
            } else { 
                cout << "Tabel Ini masih kosong!\n";
            }
            cout << endl;
            goto MenuUtama; 
            break;
        case 6: 
            // Pilihan untuk keluar dari program
            cout << "Terimakasih, Anda Telah Keluar dari Program Ini\n";
            return 0;
        default:
            // Pilihan yang tidak valid
            cout << "Pilihan Anda Tidak Sesuai\n";
            cout << endl;
            goto MenuUtama; 
            break;
    }
}


```
#### Output:
![Output](<Naufal_Output1 Unguided.png>) ![Output](<Naufal_Output2 Unguided.png>) ![Output](<Naufal_Output3 Unguided.png>) ![Output](<Naufal_Output4 Unguided.png>)

Deskripsi :

Program diatas merupakan implementasi dari struktur data tabel hash untuk menyimpan dan mengelola data mahasiswa. Program ini memiliki kelas `HashMap_125` yang memiliki metode untuk menambah, menghapus, mencari, dan menampilkan data mahasiswa berdasarkan nama, NIM, atau rentang nilai. Setiap elemen dalam tabel hash direpresentasikan sebagai objek dari kelas `HashNode_125`, yang menyimpan nama, NIM, dan nilai mahasiswa. Program juga menyediakan menu interaktif untuk pengguna agar dapat memilih operasi yang diinginkan, seperti menambah, menghapus, mencari, atau menampilkan data, serta opsi untuk keluar dari program.

## Kesimpulan
Hash table adalah struktur data yang efisien untuk menyimpan dan mengakses data secara asosiatif. Dengan menggunakan teknik hashing, hash table memungkinkan akses data yang cepat terlepas dari ukuran data. Fungsi utamanya adalah mempercepat proses akses data, dan penggunaannya luas di berbagai bidang karena efisiensinya dalam operasi waktu. Dalam pembuatan hash table, fungsi hash digunakan untuk memetakan nilai kunci ke indeks dalam array, dan penanganan collision diperlukan untuk menangani bentrokan. Dengan operasi utama seperti pencarian, penambahan, dan penghapusan, hash table memberikan solusi yang cepat dan efisien untuk pengelolaan data. Kesimpulannya, hash table menjadi alat yang sangat berguna dalam mengelola dan mengakses data dengan efisiensi tinggi.

## Referensi
[1] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform, Yogyakarta, 2021.

[2] Joseph Teguh Santoso, Struktur Data dan ALgoritma, Semarang: Yayasan Prima Agus Teknik, 2021.