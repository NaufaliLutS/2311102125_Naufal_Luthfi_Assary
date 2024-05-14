# <h1 align="center">Laporan Praktikum Modul 7 - Queue</h1>
<p align="center">Naufal Luthfi Assary</p>
<p align="center">2311102125</p>

## Dasar Teori

Queue adalah struktur data yang menggunakan metode First-In First-Out (FIFO), yang berarti data yang pertama dimasukkan ke dalam queue akan menjadi data yang pertama pula untuk dikeluarkan. Konsep ini mirip dengan antrian dalam kehidupan sehari-hari, di mana konsumen yang datang lebih dulu akan dilayani terlebih dahulu sebelum konsumen yang datang kemudian.

Implementasi queue dapat dilakukan menggunakan array atau linked list. Struktur data queue terdiri dari dua pointer, yaitu front (atau head) dan rear (atau tail). Front merupakan pointer yang menunjukkan ke elemen pertama dalam queue, sedangkan rear menunjukkan ke elemen terakhir dalam queue.

Perbedaan mendasar antara stack dan queue terletak pada aturan penambahan dan penghapusan elemen. Pada stack, operasi penambahan (push) dan penghapusan (pop) elemen dilakukan di satu ujung tumpukan. Elemen yang terakhir ditambahkan akan berada paling atas dan akan dihapus paling awal (Last-In First-Out atau LIFO). Sementara pada queue, operasi penambahan dan penghapusan dilakukan di dua ujung yang berbeda. Penambahan (enqueue) dilakukan di ujung belakang (rear), sementara penghapusan (dequeue) dilakukan di ujung depan (front). Oleh karena itu, hanya ada satu jenis operasi untuk menambah (enqueue) dan menghapus (dequeue) elemen pada queue.

Operasi dasar pada queue meliputi:

1. `enqueue()`: Menambahkan data ke dalam queue. Elemen baru ditambahkan setelah elemen terakhir dalam queue.
2. `dequeue()`: Mengeluarkan data dari queue. Elemen pertama dalam queue dihapus dan pointer front diubah ke elemen selanjutnya.
3. `peek()`: Mengambil data dari queue tanpa menghapusnya. Melihat elemen pertama dalam queue.
4. `isEmpty()`: Mengecek apakah queue kosong atau tidak.
5. `isFull()`: Mengecek apakah queue penuh atau tidak (terutama pada implementasi dengan array).
6. `size()`: Menghitung jumlah elemen dalam queue.

Dengan menggunakan operasi-operasi ini, kita dapat memanipulasi data dalam queue sesuai dengan kebutuhan aplikasi atau algoritma yang digunakan.

## Guided 

### 1. SourceCode

```C++
// Laprak 7 - Guided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>

using namespace std;

const int maksimalAntrian = 5;
int front = 0;
int back = 0;
string queueTeller[5];

bool isFull(){
    if (back == maksimalAntrian){
        return true;
    } else {
        return false;
    }
    
}
 //mengecek antrian apakah masih kosong
 bool isEmpty(){
    if(back == 0){
        return true;
    } else {
        return false;
    }
}

//menambah antrian 
void tambahData(string nama){
    if (isFull()){
        cout << "Antrian sudah penuh." << endl;
    } else {
        if (isEmpty()){
            queueTeller[0] = nama;
            front++;
            back++;
        } else {
            queueTeller[back] = nama;
            back++;
        }
    }
}

//mengurangi antrian
void kurangAntrian(){
    if(isEmpty()){
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++){
            queueTeller[i] = queueTeller[i+1];
        }
        back --;
    }
}

//menghitung banyak antrian
int count(){
    return back;
} 

//menghapus seluruh antrian
void clearQueue(){
    if(isEmpty()){
        cout << "Antrian kosong"<< endl;
    } else {
        for (int i = 0; i < back; i++){
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

//melihat antrian
void viewQueue(){
    cout << "Data antrian: "<< endl;
    for (int i = 0; i < maksimalAntrian; i++)
    {
        if (queueTeller[i] != ""){
            cout << i+1 <<". "<< queueTeller[i]<<endl;
        } else {
            cout << i+1 <<". "<<"(kosong)"<<endl; 
        }
    }   
}

//main fungsi
int main(){
    tambahData("Alya");
    tambahData("Kiki");
    tambahData("Artika");
    viewQueue();

    //mengurangi antrian 
    kurangAntrian();
    viewQueue();

    //menghapus seluruh antrian
    clearQueue();
    viewQueue();
}

```

#### Deskripsi:

Program tersebut merupakan implementasi sederhana dari sebuah antrian (queue) menggunakan array dalam bahasa C++. Program ini memiliki fungsi-fungsi dasar untuk mengelola antrian, seperti menambahkan data ke antrian, menghapus data dari antrian, menampilkan data antrian, menghitung jumlah data dalam antrian, dan menghapus semua data dalam antrian.

#### Deskripsi Fungsi-fungsi Utama:

1. **`isFull()`**: Fungsi ini memeriksa apakah antrian sudah penuh. Antrian dikatakan penuh jika indeks belakang (`back`) sudah mencapai maksimalAntrian.

2. **`isEmpty()`**: Fungsi ini memeriksa apakah antrian kosong. Antrian dikatakan kosong jika tidak ada data yang ada dalam antrian.

3. **`tambahData(string nama)`**: Fungsi ini menambahkan data baru ke dalam antrian. Data ditambahkan di posisi belakang antrian (`back`). Jika antrian penuh, akan mencetak pesan bahwa antrian sudah penuh.

4. **`kurangAntrian()`**: Fungsi ini mengurangi jumlah data dalam antrian dengan menggeser data ke depan setelah menghapus data pertama (data di posisi depan antrian).

5. **`count()`**: Fungsi ini mengembalikan jumlah data yang ada dalam antrian.

6. **`clearQueue()`**: Fungsi ini menghapus semua data dalam antrian dengan mengosongkan semua elemen dalam array dan mengatur ulang indeks depan dan belakang.

7. **`viewQueue()`**: Fungsi ini menampilkan semua data yang ada dalam antrian. Jika suatu posisi dalam array kosong, maka akan ditampilkan "(kosong)".

#### Logika Program Utama:

1. Memanggil fungsi `tambahData()` untuk menambahkan beberapa data ke antrian.
2. Menampilkan data antrian dengan memanggil fungsi `viewQueue()`.
3. Memanggil fungsi `kurangAntrian()` untuk mengurangi satu data dari antrian.
4. Menampilkan data antrian setelah pengurangan.
5. Memanggil fungsi `clearQueue()` untuk menghapus semua data dalam antrian.
6. Menampilkan data antrian setelah dihapus.


## Unguided 

### 1.  Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
// Laprak 7 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>

using namespace std;

// Struktur untuk node dalam antrian
struct Node {
    string data_125;  // Data yang disimpan dalam node
    Node* next;       // Untuk ke node berikutnya

    // Konstruktor untuk inisialisasi node dengan data dan next sebagai nullptr
    Node(string val) : data_125(val), next(nullptr) {}
};

// Struktur untuk antrian
struct Queue {
    Node* front;  // Untuk ke depan antrian
    Node* back;   // Untuk ke belakang antrian
    int size;     // Ukuran antrian

    // Konstruktor untuk inisialisasi antrian kosong
    Queue() : front(nullptr), back(nullptr), size(0) {}
};

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty(Queue* queue) {
    return queue->size == 0;  // Antrian kosong jika ukuran antrian adalah 0
}

// Fungsi untuk menambahkan elemen ke antrian
void enqueueAntrian(Queue* queue, string data) {
    Node* newNode = new Node(data);  // Buat node baru dengan data

    // Jika antrian kosong, depan dan belakang menunjuk ke node baru
    if (isEmpty(queue)) {
        queue->front = queue->back = newNode;
    } else {
        // Jika tidak kosong, tambahkan node baru di belakang antrian
        queue->back->next = newNode;
        queue->back = newNode;
    }

    queue->size++;  // Tingkatkan ukuran antrian
}

// Fungsi untuk menghapus elemen dari antrian
void dequeueAntrian(Queue* queue) {
    // Jika antrian kosong, cetak pesan dan keluar dari fungsi
    if (isEmpty(queue)) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    // Hapus node dari depan antrian
    Node* temp = queue->front;  // Simpan node depan ke variabel sementara
    queue->front = queue->front->next;  // Pindahkan depan ke node berikutnya
    delete temp;  // Hapus node depan yang lama

    queue->size--;  // Kurangi ukuran antrian
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue(Queue* queue) {
    return queue->size;  // Kembalikan ukuran antrian
}

// Fungsi untuk menghapus semua elemen dalam antrian
void clearQueue(Queue* queue) {
    // Hapus elemen satu per satu hingga antrian kosong
    while (!isEmpty(queue)) {
        dequeueAntrian(queue);
    }
}

// Fungsi untuk menampilkan semua elemen dalam antrian
void viewQueue(Queue* queue) {
    // Jika antrian kosong, cetak pesan dan keluar dari fungsi
    if (isEmpty(queue)) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    // Cetak data semua elemen dalam antrian
    cout << "Data antrian Teller : " << endl;
    Node* current = queue->front;  // Mulai dari depan antrian
    int index = 1;  // Indeks untuk penomoran elemen

    // Iterasi melalui semua node dalam antrian
    while (current != nullptr) {
        cout << index << ". " << current->data_125 << endl;  // Cetak data dan indeks
        current = current->next;  // Pindah ke node berikutnya
        index++;  // Tambah indeks
    }
}

int main() {
    Queue* antrian_125 = new Queue();  // Buat antrian baru

    cout << "---> Naufal'S Teller Queue <---\n";  // Cetak judul antrian
    enqueueAntrian(antrian_125, "Alya");  // Tambahkan 'Alya' ke antrian
    enqueueAntrian(antrian_125, "Kiki");  // Tambahkan 'Kiki' ke antrian
    enqueueAntrian(antrian_125, "Artika");  // Tambahkan 'Artika' ke antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian
    cout << endl;

    dequeueAntrian(antrian_125);  // Hapus elemen depan antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << endl;

    enqueueAntrian(antrian_125, "Naufal");  // Tambahkan 'Naufal' ke antrian
    enqueueAntrian(antrian_125, "Luthfi");  // Tambahkan 'Luthfi' ke antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian
    cout << endl;

    clearQueue(antrian_125);  // Hapus semua elemen dalam antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian

    return 0;  
}

```
#### Output:
![Output](<Naufal_Output1 Unguided.png>)

#### Deskripsi :

Program tersebut merupakan implementasi sederhana dari sebuah antrian (queue) menggunakan linked list dalam bahasa C++. Program ini menggunakan struktur data linked list untuk menyimpan dan mengelola data dalam antrian. Berikut adalah deskripsi singkat dari program:

#### Struktur Data:

1. **Node**: Struktur ini digunakan untuk merepresentasikan elemen tunggal dalam linked list. Setiap node memiliki dua bagian utama: data yang disimpan (dalam kasus ini `data_125` bertipe string) dan pointer ke node berikutnya (`next`).

2. **Queue**: Struktur ini merepresentasikan antrian secara keseluruhan. Ini memiliki dua pointer, yaitu `front` untuk menunjukkan elemen pertama dalam antrian dan `back` untuk menunjukkan elemen terakhir. Ukuran antrian juga disimpan dalam variabel `size`.

#### Fungsi-fungsi Utama:

1. **`isEmpty(Queue* queue)`**: Fungsi ini memeriksa apakah antrian kosong dengan memeriksa apakah ukuran antrian adalah 0.

2. **`enqueueAntrian(Queue* queue, string data)`**: Fungsi ini menambahkan elemen baru ke dalam antrian. Jika antrian kosong, elemen baru menjadi depan dan belakang antrian. Jika tidak, elemen baru ditambahkan di belakang antrian.

3. **`dequeueAntrian(Queue* queue)`**: Fungsi ini menghapus elemen pertama dari antrian. Jika antrian kosong, akan dicetak pesan bahwa antrian kosong. Jika tidak, elemen pertama dihapus dari antrian.

4. **`countQueue(Queue* queue)`**: Fungsi ini mengembalikan jumlah elemen dalam antrian.

5. **`clearQueue(Queue* queue)`**: Fungsi ini menghapus semua elemen dalam antrian dengan menghapus satu per satu sampai antrian kosong.

6. **`viewQueue(Queue* queue)`**: Fungsi ini menampilkan semua elemen dalam antrian.

#### Logika Program Utama:

1. Membuat objek antrian baru dengan menggunakan struktur `Queue`.
2. Menambahkan beberapa elemen ke dalam antrian dengan menggunakan `enqueueAntrian()`.
3. Menghapus elemen pertama dari antrian dengan menggunakan `dequeueAntrian()`.
4. Menampilkan elemen yang ada dalam antrian dengan menggunakan `viewQueue()`.
5. Menghapus semua elemen dari antrian dengan menggunakan `clearQueue()`.
6. Menampilkan elemen yang ada dalam antrian setelah dihapus dengan menggunakan `viewQueue()`.

Program ini memiliki fitur sederhana untuk mengelola antrian, seperti menambahkan, menghapus, dan menampilkan data dalam antrian.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
// Laprak 7 - Unguided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>

using namespace std;

// Struktur untuk node dalam antrian
struct Node {
    string nama_125;    // Nama mahasiswa
    long long nim_125;  // NIM mahasiswa
    Node* next;         // Untuk ke node berikutnya

    // Konstruktor untuk inisialisasi node dengan nama dan NIM
    Node(string n, long long a) : nama_125(n), nim_125(a), next(nullptr) {}
};

// Struktur untuk antrian
struct Queue {
    Node* front;  // Untuk ke depan antrian
    Node* back;   // Untuk ke belakang antrian
    int size;     // Ukuran antrian

    // Konstruktor untuk inisialisasi antrian kosong
    Queue() : front(nullptr), back(nullptr), size(0) {}
};

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty(Queue* queue) {
    return queue->size == 0;  // Antrian kosong jika ukuran antrian adalah 0
}

// Fungsi untuk menambahkan elemen ke antrian
void enqueueAntrian(Queue* queue, string nama, long long nim) {
    Node* newNode = new Node(nama, nim);  // Buat node baru dengan nama dan NIM

    // Jika antrian kosong, depan dan belakang menunjuk ke node baru
    if (isEmpty(queue)) {
        queue->front = queue->back = newNode;
    } else {
        // Jika tidak kosong, tambahkan node baru di belakang antrian
        queue->back->next = newNode;
        queue->back = newNode;
    }

    queue->size++;  // Tingkatkan ukuran antrian
}

// Fungsi untuk menghapus elemen dari antrian
void dequeueAntrian(Queue* queue) {
    // Jika antrian kosong, cetak pesan dan keluar dari fungsi
    if (isEmpty(queue)) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    // Hapus node dari depan antrian
    Node* temp = queue->front;  // Simpan node depan ke variabel sementara
    queue->front = queue->front->next;  // Pindahkan depan ke node berikutnya
    delete temp;  // Hapus node depan yang lama

    queue->size--;  // Kurangi ukuran antrian
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue(Queue* queue) {
    return queue->size;  // Kembalikan ukuran antrian
}

// Fungsi untuk menghapus semua elemen dalam antrian
void clearQueue(Queue* queue) {
    // Hapus elemen satu per satu hingga antrian kosong
    while (!isEmpty(queue)) {
        dequeueAntrian(queue);
    }
}

// Fungsi untuk menampilkan semua elemen dalam antrian
void viewQueue(Queue* queue) {
    // Jika antrian kosong, cetak pesan dan keluar dari fungsi
    if (isEmpty(queue)) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    // Cetak data semua elemen dalam antrian
    cout << "Data antrian : " << endl;
    Node* current = queue->front;  // Mulai dari depan antrian
    int index = 1;  // Indeks untuk penomoran elemen

    // Iterasi melalui semua node dalam antrian
    while (current != nullptr) {
        cout << index << ". " << current->nama_125 << ", NIM (" << current->nim_125 << ")" << endl;  // Cetak data dan indeks
        current = current->next;  // Pindah ke node berikutnya
        index++;  // Tambah indeks
    }
}

int main() {
    Queue* antrian_125 = new Queue();  // Buat antrian baru

    cout << "---> Naufal'S Mahasiswa Queue <---\n";  // Cetak judul antrian
    enqueueAntrian(antrian_125, "Naufal", 2311102125);  // Tambahkan 'Naufal' ke antrian
    enqueueAntrian(antrian_125, "Luthfi", 2311102125);  // Tambahkan 'Luthfi' ke antrian
    enqueueAntrian(antrian_125, "Assary", 2311102125);  // Tambahkan 'Assary' ke antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian
    cout << endl;

    dequeueAntrian(antrian_125);  // Hapus elemen depan antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << endl;

    enqueueAntrian(antrian_125, "Udin", 2311102125);  // Tambahkan 'Udin' ke antrian
    enqueueAntrian(antrian_125, "Nganga", 2311102125);  // Tambahkan 'Nganga' ke antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian
    cout << endl;

    clearQueue(antrian_125);  // Hapus semua elemen dalam antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian

    return 0;  
}

```
#### Output:
![Output](<Naufal_Output2 Unguided.png>)

#### Deskripsi:

Program tersebut merupakan implementasi sederhana dari sebuah antrian (queue) menggunakan linked list dalam bahasa C++. Program ini digunakan untuk mengelola antrian mahasiswa dengan menyimpan data nama dan NIM mahasiswa dalam setiap elemen antrian. Berikut adalah deskripsi singkat dari program:

#### Struktur Data:

1. **Node**: Struktur ini digunakan untuk merepresentasikan elemen tunggal dalam linked list. Setiap node memiliki dua bagian utama: nama mahasiswa (`nama_125` bertipe string) dan NIM mahasiswa (`nim_125` bertipe long long), serta pointer ke node berikutnya (`next`).

2. **Queue**: Struktur ini merepresentasikan antrian mahasiswa secara keseluruhan. Ini memiliki dua pointer, yaitu `front` untuk menunjukkan elemen pertama dalam antrian dan `back` untuk menunjukkan elemen terakhir. Ukuran antrian juga disimpan dalam variabel `size`.

#### Fungsi-fungsi Utama:

1. **`isEmpty(Queue* queue)`**: Fungsi ini memeriksa apakah antrian kosong dengan memeriksa apakah ukuran antrian adalah 0.

2. **`enqueueAntrian(Queue* queue, string nama, long long nim)`**: Fungsi ini menambahkan elemen baru ke dalam antrian dengan menyimpan nama dan NIM mahasiswa. Jika antrian kosong, elemen baru menjadi depan dan belakang antrian. Jika tidak, elemen baru ditambahkan di belakang antrian.

3. **`dequeueAntrian(Queue* queue)`**: Fungsi ini menghapus elemen pertama dari antrian. Jika antrian kosong, akan dicetak pesan bahwa antrian kosong. Jika tidak, elemen pertama dihapus dari antrian.

4. **`countQueue(Queue* queue)`**: Fungsi ini mengembalikan jumlah elemen dalam antrian.

5. **`clearQueue(Queue* queue)`**: Fungsi ini menghapus semua elemen dalam antrian dengan menghapus satu per satu sampai antrian kosong.

6. **`viewQueue(Queue* queue)`**: Fungsi ini menampilkan semua elemen dalam antrian beserta nama dan NIM mahasiswa.

#### Logika Program Utama:

1. Membuat objek antrian baru dengan menggunakan struktur `Queue`.
2. Menambahkan beberapa elemen ke dalam antrian dengan menggunakan `enqueueAntrian()`.
3. Menghapus elemen pertama dari antrian dengan menggunakan `dequeueAntrian()`.
4. Menampilkan elemen yang ada dalam antrian beserta nama dan NIM mahasiswa dengan menggunakan `viewQueue()`.
5. Menghapus semua elemen dari antrian dengan menggunakan `clearQueue()`.
6. Menampilkan elemen yang ada dalam antrian setelah dihapus dengan menggunakan `viewQueue()`.

Program ini memiliki fitur sederhana untuk mengelola antrian mahasiswa, seperti menambahkan, menghapus, dan menampilkan data dalam antrian.

## Kesimpulan
Dapat disimpulkan beberapa hal tentang struktur data queue:

1. **Konsep FIFO**: Queue mengikuti konsep First-In First-Out, di mana elemen pertama yang dimasukkan akan menjadi elemen pertama yang dikeluarkan. Ini mirip dengan antrian dalam kehidupan sehari-hari di mana orang atau objek yang datang lebih dulu akan dilayani terlebih dahulu.

2. **Implementasi**: Queue dapat diimplementasikan menggunakan array atau linked list. Dalam implementasi ini, terdapat dua pointer utama yaitu front dan rear, yang menunjukkan ke elemen pertama dan terakhir dalam queue.

3. **Operasi Dasar**: Operasi dasar pada queue meliputi enqueue untuk menambahkan elemen, dequeue untuk mengeluarkan elemen, peek untuk melihat elemen tanpa menghapusnya, isEmpty untuk memeriksa apakah queue kosong, isFull untuk memeriksa apakah queue penuh (terutama pada implementasi array), dan size untuk menghitung jumlah elemen dalam queue.

4. **Perbedaan dengan Stack**: Perbedaan utama antara stack dan queue terletak pada aturan penambahan dan penghapusan elemen. Queue mengikuti aturan FIFO, sementara stack mengikuti aturan LIFO (Last-In First-Out).

Kesimpulannya, queue adalah struktur data yang berguna dalam mengatur urutan data dengan cara yang sesuai dengan konsep antrian. Penggunaan queue umumnya ditemukan dalam berbagai aplikasi seperti sistem antrian, algoritma pemrosesan data, dan pemrograman paralel. Pemahaman konsep dan operasi dasar queue sangat penting dalam pengembangan perangkat lunak yang efisien dan andal.

## Referensi
[1] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform, Yogyakarta, 2021.

[2] Joseph Teguh Santoso, Struktur Data dan ALgoritma, Semarang: Yayasan Prima Agus Teknik, 2021.

[3] Wanra Tarigan, Algoritma Pemograman dan Struktur Data, Purbalingga: EUREKA MEDIA AKSARA, 2022.

[4] Rafsanjani, Malik Akbar Hashemi. Implementasi Algoritma Pengurutan General Purpose dan Berbasis Komparasi untuk Data Berkategori dalam Waktu Linier Tanpa Paralelisasi,2021.

[4] Asisten Praktikum. Modul 7 Queue. Purwokerto: Institut Teknologi Purwokerto. 2024.