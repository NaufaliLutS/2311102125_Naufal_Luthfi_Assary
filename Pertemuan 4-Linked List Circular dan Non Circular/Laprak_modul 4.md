# <h1 align="center">Laporan Praktikum Modul 4</h1>
# <h1 align="center">Linked List Circular dan Non Circular</h1>
<p align="center">Naufal Luthfi Assary</p>
<p align="center">2311102125</p>

## Dasar Teori

Linked list adalah struktur data dinamis yang terdiri dari sejumlah simpul yang saling terhubung melalui pointer. Setiap simpul memiliki dua bagian: data dan pointer yang menunjuk ke simpul berikutnya (dan sebelumnya dalam double linked list). Ini memungkinkan penyimpanan data secara dinamis dan mempermudah penambahan serta penghapusan elemen. Elemen pertama disebut head, dan elemen terakhir menunjuk ke NULL.

Single Linked List Non Circular:
Single linked list non-circular adalah jenis linked list di mana setiap simpul hanya memiliki satu pointer, yaitu pointer yang menunjuk ke simpul berikutnya dalam urutan. Elemen terakhir menunjuk ke NULL, menandakan akhir dari linked list. Operasi umum meliputi penambahan dan penghapusan elemen di awal atau akhir, serta pencarian dan pengambilan nilai pada simpul tertentu.

Double Linked List Non Circular:
Double linked list non-circular adalah jenis linked list di mana setiap simpul memiliki dua pointer: satu untuk menunjuk ke simpul berikutnya dan satu untuk menunjuk ke simpul sebelumnya dalam urutan. Ini memungkinkan operasi penambahan dan penghapusan pada simpul dilakukan secara efisien. Pointer pada elemen pertama menunjuk ke NULL, dan pointer pada elemen terakhir menunjuk ke NULL juga.

Single Circular Linked List:
Single circular linked list adalah jenis linked list di mana setiap simpul memiliki pointer yang menunjuk ke simpul berikutnya dalam urutan, dan elemen terakhir menunjuk kembali ke elemen pertama, membentuk lingkaran atau sirkuit. Operasi umum pada single circular linked list sama dengan single linked list non-circular, namun elemen terakhir tidak menunjuk ke NULL, melainkan kembali ke elemen pertama.

Double Circular Linked List:
Double circular linked list adalah jenis linked list di mana setiap simpul memiliki dua pointer: satu untuk menunjuk ke simpul berikutnya dan satu untuk menunjuk ke simpul sebelumnya dalam urutan. Selain itu, elemen terakhir menunjuk kembali ke elemen pertama, membentuk pola sirkular. Ini memungkinkan operasi penambahan dan penghapusan pada simpul dilakukan secara efisien, dan pola sirkular pada pointer memungkinkan untuk traversal yang lancar dalam kedua arah.

## Guided 

### 1. Linked List Non Circular

```C++
// Laprak 4 - Guided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
using namespace std;

// Deklarasi struct node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah kosong
bool isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}

// Tambah depan
void insertDepan(int nilai) {
    // Buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah belakang
void insertBelakang(int nilai) {
    // Buat node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
        tail->next = NULL;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung jumlah list
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;

        // Transversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus depan
void hapusDepan() {
    Node *hapus;
    if (!isEmpty()) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        } else {
            head = tail = NULL;
        }
    } else {
        cout << "List kosong" << endl;
    }
}

// Hapus tengah
void hapusTengah(int posisi) {
    Node *bantu, *hapus, *sebelum;
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                sebelum = bantu;
            }
            if (nomor == posisi) {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        sebelum->next = bantu;
        delete hapus;
    }
}

// Ubah depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah tengah
void ubahTengah(int data, int posisi) {
    Node *bantu;
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus semua list
void clearList() {
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan list
void tampil() {
    Node *bantu;
    bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusTengah(2);
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}

```

Deskripsi:

Program tersebut adalah implementasi dari struktur data linked list. Program ini memiliki sebuah struct `Node` yang berisi data bertipe integer dan pointer `next` yang menunjuk ke node selanjutnya. Program ini juga memiliki dua pointer global yaitu `head` dan `tail` yang menunjukkan ke node pertama dan terakhir dalam linked list.

Beberapa fungsi yang dimiliki oleh program ini antara lain:

1. `init()`: Menginisialisasi `head` dan `tail` menjadi `NULL`.
2. `isEmpty()`: Memeriksa apakah linked list kosong atau tidak.
3. `insertDepan(int nilai)`: Menambahkan node baru di bagian depan linked list.
4. `insertBelakang(int nilai)`: Menambahkan node baru di bagian belakang linked list.
5. `hitungList()`: Menghitung jumlah node dalam linked list.
6. `insertTengah(int data, int posisi)`: Menambahkan node baru di posisi tengah sesuai dengan posisi yang ditentukan.
7. `hapusDepan()`: Menghapus node pertama dalam linked list.
8. `hapusTengah(int posisi)`: Menghapus node pada posisi tertentu dalam linked list.
9. `ubahDepan(int data)`: Mengubah data pada node pertama dalam linked list.
10. `ubahTengah(int data, int posisi)`: Mengubah data pada node pada posisi tertentu dalam linked list.
11. `ubahBelakang(int data)`: Mengubah data pada node terakhir dalam linked list.
12. `clearList()`: Menghapus seluruh isi linked list.
13. `tampil()`: Menampilkan seluruh isi linked list.

Selain itu, program ini juga memiliki fungsi `main()` yang merupakan tempat eksekusi dari program. Pada fungsi `main()`, beberapa operasi seperti menambah, menghapus, dan mengubah data pada linked list telah diimplementasikan sebagai contoh penggunaan fungsi-fungsi yang telah didefinisikan sebelumnya.

### 2. Linked List Circular

```C++
// Laprak 4 - Guided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
using namespace std;

// Deklarasi Struct Node
struct Node
{
    string data;
    Node* next;
};

Node* head, * tail, * baru, * bantu, * hapus;

void init()
{
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty()
{
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList()
{
    bantu = head;
    int jumlah = 0;
    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }
    return jumlah;
}

// Tambah Depan
void insertDepan(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data)
{
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;
            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        // transversing
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList()
{
    if (head != NULL)
    {
        hapus = head->next;
        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}

```
Program diatas adalah implementasi dari struktur data circular linked list. Circular linked list adalah jenis linked list di mana setiap node memiliki pointer yang menunjuk kembali ke node pertama dalam linked list, sehingga membentuk sebuah lingkaran.

Program ini memiliki sebuah struct `Node` yang berisi data bertipe string dan pointer `next` yang menunjuk ke node selanjutnya. Selain itu, program juga memiliki beberapa pointer global seperti `head`, `tail`, `baru`, `bantu`, dan `hapus` yang digunakan dalam operasi-operasi pada circular linked list.

Beberapa fungsi yang dimiliki oleh program ini antara lain:

1. `init()`: Menginisialisasi `head` dan `tail` menjadi `NULL`.
2. `isEmpty()`: Memeriksa apakah circular linked list kosong atau tidak.
3. `buatNode(string data)`: Membuat node baru dengan data tertentu.
4. `hitungList()`: Menghitung jumlah node dalam circular linked list.
5. `insertDepan(string data)`: Menambahkan node baru di bagian depan circular linked list.
6. `insertBelakang(string data)`: Menambahkan node baru di bagian belakang circular linked list.
7. `insertTengah(string data, int posisi)`: Menambahkan node baru di posisi tertentu dalam circular linked list.
8. `hapusDepan()`: Menghapus node pertama dalam circular linked list.
9. `hapusBelakang()`: Menghapus node terakhir dalam circular linked list.
10. `hapusTengah(int posisi)`: Menghapus node pada posisi tertentu dalam circular linked list.
11. `clearList()`: Menghapus seluruh isi circular linked list.
12. `tampil()`: Menampilkan seluruh isi circular linked list.

Selain itu, program ini juga memiliki fungsi `main()` yang merupakan tempat eksekusi dari program. Pada fungsi `main()`, beberapa operasi seperti menambah, menghapus, dan menampilkan data pada circular linked list telah diimplementasikan sebagai contoh penggunaan fungsi-fungsi yang telah didefinisikan sebelumnya.

## Unguided 

### 1.  Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa, berikut contoh tampilan output dari nomor 1: ![Soal](<Naufal_Soal Unguided1_1.png>) ![Soal](<Naufal_Soal Unguided1_2.png>)

```C++
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

```
#### Output:
1. Output Tambah Depan![Output](<Naufal_Output Tambah Depan.png>)
2. Output Tambah Belakang![Output](<Naufal_Output Tambah Belakang.png>)
3. Output Tambah Tengah![Output](<Naufal_Output Tambah Tengah.png>)
4. Output Ubah Depan![Output](<Naufal_Output Ubah Depan.png>)
5. Output Ubah Belakang![Output](<Naufal_Output Ubah Belakang.png>)
6. Output Ubah Tengah![Output](<Naufal_Output Ubah Tengah.png>)
7. Output Hapus Depan![Output](<Naufal_Output Hapus Depan.png>)
8. Output Hapus Belakang![Output](<Naufal_Output Hapus Belakang.png>)
9. Output Hapus Tengah![Output](<Naufal_Output Hapus Tengah.png>)
10. Output Hapus List![Output](<Naufal_Output Hapus List.png>)
11. Output Tampilkan![Output](<Naufal_Output Tampilkan.png>)

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)![Soal](<Naufal_Soal Unguided2.png>)

#### Output:
1. Output Tambah Nama Jawad![Output](<Naufal_Output Nama Jawad.png>)
2. Output Tambah Nama Naufal![Output](<Naufal_Output Nama Naufal.png>)
3. Output Tambah Nama Farrel![Output](<Naufal_Output Nama Farrel.png>)
4. Output Tambah Nama Denis![Output](<Naufal_Output Nama Denis.png>)
5. Output Tambah Nama Anis![Output](<Naufal_Output Nama Anis.png>)
6. Output Tambah Nama Bowo![Output](<Naufal_Output Nama Bowo.png>)
7. Output Tambah Nama Gahar![Output](<Naufal_Output Nama Gahar.png>)
8. Output Tambah Nama Udin![Output](<Naufal_Output Nama Udin.png>)
9. Output Tambah Nama Ucok![Output](<Naufal_Output Nama Ucok.png>)
10. Output Tambah Nama Budi![Output](<Naufal_Output Nama Budi.png>)
11. Output Tampilan Seluruh Data![alt text](<Naufal_Output Tampilan Unguided2.png>)

### 3. Lakukan perintah berikut:![Soal](<Naufal_Soal Unguided3.png>)

#### Output:
1. Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004![Output](<Naufal_Output Tambah Data Wati.png>)
2. Hapus data Denis![Output](<Naufal_Output Hapus Data Denis.png>)
3. Tambahkan data berikut di awal: Owi 2330000![Output](<Naufal_Output Tambah Data Owi.png>)
4. Tambahkan data berikut di akhir: David 23300100![Output](<Naufal_Output Tambah Data David.png>)
5. Ubah data Udin menjadi data berikut: Idin 23300045![Output](<Naufal_Output Ubah Data Udin.png>)
6. Ubah data terkahir menjadi berikut: Lucy 23300101![Output](<Naufal_Output Ubah Data Lucy.png>)
7. Hapus data awal![Output](<Naufal_Output Hapus Data Awal.png>)
8. Ubah data awal menjadi berikut: Bagas 2330002![Output](<Naufal_Output Ubah Data Awal.png>)
9. Hapus data akhir![Output](<Naufal_Output Hapus Data Akhir.png>)
10. Tampilkan seluruh data![Output](<Naufal_Output Tampilkan Seluruh Data.png>)

Deskripsi :

Program diatas merupakan implementasi dari linked list non-circular yang digunakan untuk menyimpan data mahasiswa seperti Nama dan NIM. Program ini memiliki struktur utama berupa sebuah struct `node` yang memiliki dua atribut yaitu `Nama_125` dan `NIM_125`, serta pointer `next` yang menunjukkan ke node selanjutnya. Selain itu, program juga memiliki dua pointer global `head` dan `tail` yang menunjukkan ke node pertama dan terakhir dalam linked list.

Ada beberapa fungsi dan prosedur yang digunakan dalam program ini, antara lain:

1. `Inisialisasi_125()`: Digunakan untuk menginisialisasi `head` dan `tail` menjadi `NULL`.
2. `isEmpty_125()`: Digunakan untuk memeriksa apakah linked list kosong atau tidak.
3. `HitungNode_125()`: Menghitung jumlah node dalam linked list.
4. `TambahDepan_125(string Nama, string NIM)`: Menambahkan node baru di bagian depan linked list.
5. `TambahBelakang_125(string Nama, string NIM)`: Menambahkan node baru di bagian belakang linked list.
6. `TambahTengah_125(string Nama, string NIM, int Posisi)`: Menambahkan node baru di tengah-tengah linked list sesuai dengan posisi yang ditentukan.
7. `HapusDepan_125()`: Menghapus node pertama dalam linked list.
8. `TampilDepan_125()`: Menampilkan data dari node pertama dalam linked list.
9. `HapusBelakang_125()`: Menghapus node terakhir dalam linked list.
10. `TampilBelakang_125()`: Menampilkan data dari node terakhir dalam linked list.
11. `HapusTengah_125(int posisi_125)`: Menghapus node pada posisi tertentu dalam linked list.
12. `TampilTengah_125(int Posisi)`: Menampilkan data dari node pada posisi tertentu dalam linked list.
13. `UbahDepan_125(string NewName, string NewNIM)`: Mengubah data pada node pertama dalam linked list.
14. `UbahBelakang_125(string NewName, string NewNIM)`: Mengubah data pada node terakhir dalam linked list.
15. `UbahTengah_125(string NewName, string NewNIM, int Posisi)`: Mengubah data pada node pada posisi tertentu dalam linked list.
16. `HapusList_125()`: Menghapus seluruh isi linked list.
17. `TampilList_125()`: Menampilkan seluruh isi linked list.

Program tersebut juga memiliki loop utama `MenuUtama` yang memungkinkan pengguna untuk memilih operasi yang ingin dilakukan terhadap linked list, seperti menambah, menghapus, atau menampilkan isi linked list. Program akan terus berjalan hingga pengguna memilih untuk keluar (`Pilih = 0`).

## Kesimpulan
Linked List merupakan struktur data dinamis yang memungkinkan penyimpanan data secara efisien dengan menggunakan pointer untuk menghubungkan setiap simpul. Terdapat berbagai jenis Linked List, seperti Single Linked List Non Circular, Double Linked List Non Circular, Single Circular Linked List, dan Double Circular Linked List, masing-masing dengan karakteristik dan kegunaan yang berbeda. Kelebihan utama Linked List adalah kemampuannya dalam penambahan dan penghapusan elemen secara fleksibel. Setiap jenis Linked List memiliki cara tersendiri dalam mengatur penunjuk antar simpul, baik dalam arah satu maupun dua arah, yang memengaruhi kinerja operasional seperti penelusuran dan penghapusan elemen. Oleh karena itu, pemilihan jenis Linked List harus disesuaikan dengan kebutuhan aplikasi dan karakteristik data yang akan disimpan.

## Referensi
[1] Joseph Teguh Santoso, Struktur Data dan Algoritma (Bagian 1). Semarang: Yayasan Prima Agus Teknik, 2021.

[2] Triase. Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN, 2020.

[3] Shofyann Hanief,et al., Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Yogyakarta: Andi Publisher, 2020.

[4] Achmad Udin Zailani,Budi Apriyanto,Hadi Zakaria, STRUKTUR DATA, Banten:2 Universitas Pamulang Tangerang Selatan, 2020.