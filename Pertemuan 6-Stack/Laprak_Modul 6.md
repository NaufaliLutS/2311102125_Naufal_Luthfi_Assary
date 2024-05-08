# <h1 align="center">Laporan Praktikum Modul 6 - Stack</h1>
<p align="center">Naufal Luthfi Assary</p>
<p align="center">2311102125</p>

## Dasar Teori

Stack dalam pemrograman adalah struktur data yang mengikuti prinsip Last In, First Out (LIFO), mirip dengan tumpukan piring di kafetaria atau tumpukan buku di meja. Operasi utama dalam stack adalah push untuk menambahkan elemen baru ke atas tumpukan dan pop untuk menghapus elemen teratas dari tumpukan. Karakteristik ini membuat stack berguna dalam menyimpan data yang memerlukan urutan operasi tertentu, seperti dalam penyelesaian masalah matematika atau manajemen memori dalam sistem komputer.

Operasi dasar pada stack meliputi:

A. `Push` (Masukkan): Menambahkan elemen baru ke atas tumpukan. Ini seperti menambahkan buku baru ke tumpukan buku yang sudah ada.

B. `Pop` (Keluarkan): Menghapus elemen teratas dari tumpukan. Ketika Anda mengambil buku dari tumpukan, yang diambil adalah yang paling atas, yang paling terlihat.

C. `Top` (Atas): Melihat elemen teratas dari tumpukan tanpa menghapusnya. Ini memungkinkan Anda untuk melihat elemen teratas tanpa mengganggu susunan tumpukan.

D. `IsEmpty` (Kosong): Memeriksa apakah tumpukan kosong atau tidak. Ini berguna untuk memastikan tumpukan tidak kosong sebelum melakukan operasi pop atau peek.

E. `IsFull` (Penuh): Memeriksa apakah tumpukan penuh atau tidak. Ini berguna untuk memastikan tumpukan tidak meluap saat melakukan operasi push.

F. `Ukuran` (Ukuran): Mengembalikan jumlah elemen dalam tumpukan. Ini memberi Anda informasi tentang seberapa besar tumpukan saat ini.

G. `Peek` (Lihat): Melihat elemen tertentu dalam tumpukan tanpa menghapusnya. Ini berguna untuk memeriksa nilai tertentu dalam tumpukan tanpa memodifikasi tumpukan itu sendiri.

H. `Clear` (Hapus Semua): Mengosongkan tumpukan dengan menghapus semua elemennya. Ini berguna saat Anda ingin mengosongkan tumpukan untuk penggunaan berikutnya.

I. `Search` (Cari) : Mencari elemen tertentu dalam tumpukan.

Stack memiliki kelebihan, seperti pengelolaan data yang mudah dan efisien dengan metode LIFO, dan kelemahan, seperti keterbatasan dalam ukuran memori tumpukan dan risiko tumpukan meluap jika terlalu banyak elemen dimasukkan. Meskipun demikian, stack tetap menjadi struktur data yang sangat berguna dalam berbagai aplikasi pemrograman.

## Guided 

### 1. SourceCode

```C++
// Laprak 6 - Guided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

    return 0;
}

```

Deskripsi:

Program ini merupakan implementasi dari struktur data stack menggunakan array dalam bahasa C++. Program ini memiliki beberapa fungsi utama:

1. `isFull()`: Fungsi ini digunakan untuk memeriksa apakah stack telah penuh atau tidak. Jika `top` (indeks teratas) sama dengan `maksimal`, maka stack dianggap penuh.

2. `isEmpty()`: Fungsi ini digunakan untuk memeriksa apakah stack kosong atau tidak. Jika `top` sama dengan 0, maka stack dianggap kosong.

3. `pushArrayBuku(string data)`: Fungsi ini digunakan untuk menambahkan data ke dalam stack. Data ditambahkan pada posisi `top` dan nilai `top` dinaikkan satu.

4. `popArrayBuku()`: Fungsi ini digunakan untuk menghapus data dari stack. Data yang dihapus adalah data pada posisi `top - 1`, dan nilai `top` dikurangi satu.

5. `peekArrayBuku(int posisi)`: Fungsi ini digunakan untuk melihat data pada posisi tertentu dalam stack. Data pada posisi `posisi` dihitung dari atas stack.

6. `countStack()`: Fungsi ini digunakan untuk menghitung jumlah data dalam stack, yaitu dengan mengembalikan nilai dari `top`.

7. `changeArrayBuku(int posisi, string data)`: Fungsi ini digunakan untuk mengubah data pada posisi tertentu dalam stack dengan data baru.

8. `destroyArraybuku()`: Fungsi ini digunakan untuk menghapus semua data dalam stack dengan mengosongkan array dan mengatur `top` kembali ke 0.

9. `cetakArrayBuku()`: Fungsi ini digunakan untuk mencetak semua data dalam stack, dimulai dari data paling atas (top) hingga data paling bawah.

Program kemudian melakukan pengujian terhadap fungsi-fungsi di atas dengan menambahkan beberapa data ke dalam stack, mencetak data-stack, dan melakukan operasi-operasi lain seperti mengubah data, menghitung jumlah data, dan menghapus semua data dalam stack.


## Unguided 

### 1.  Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
// Laprak 6 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define MAX_SIZE 100 // Mendefinisikan ukuran maksimum stack

// Fungsi untuk memeriksa apakah sebuah string adalah palindrom atau bukan
bool CekPalindrom_125(string input_125) {
    char stack[MAX_SIZE]; // Array untuk menyimpan karakter dari string input sebagai stack
    int top = -1; // Indeks teratas (top) stack, awalnya diatur ke -1 karena stack kosong

    int n = input_125.length(); // Mendapatkan panjang string input

    // Mengisi stack dengan karakter dari string input
    for (int i = 0; i < n; i++) {
        if (top < MAX_SIZE - 1) { // Memeriksa apakah stack masih memiliki ruang kosong
            stack[++top] = input_125[i]; // Menambahkan karakter ke stack dan mengubah nilai top
        } else {
            cout << "Lebihan"; // Jika stack penuh, mencetak pesan dan mengembalikan false
            return false;
        }
    }

    // Memeriksa apakah string input adalah palindrom dengan membandingkan karakter input dengan karakter yang dikeluarkan dari stack
    for (int i = 0; i < n; i++) {
        if (input_125[i] != stack[top--]) { // Membandingkan karakter input dengan karakter stack
            return false; // Jika ada perbedaan, mengembalikan false karena string bukan palindrom
        }
    }

    return true; // Jika tidak ada perbedaan, mengembalikan true karena string adalah palindrom
}

int main()
{
    char LanjutkanInput_125; // Variabel untuk menyimpan opsi pengguna untuk melanjutkan atau tidak
    do {  
        string input_125; // Variabel untuk menyimpan input pengguna
        
        cout << "---> Naufal'S Cek Palindrom <---\n";
        cout << "Masukkan Kalimat: "; 
        getline(cin, input_125); // Mengambil input dari pengguna

        // Memeriksa apakah input adalah palindrom menggunakan fungsi CekPalindrom_125
        if (CekPalindrom_125(input_125)) {
            cout << "Kalimat " <<  input_125 << " adalah Palindrom" << endl; // Jika palindrom, mencetak pesan yang sesuai
        } else {
            cout << "Kalimat " << input_125 << " bukan Palindrom " << endl; // Jika bukan palindrom, mencetak pesan yang sesuai
        }

        cout << "Ingin mencoba kata/kalimat lain? (y/n): "; // Meminta opsi dari pengguna
        cin >> LanjutkanInput_125; 
        cin.ignore(); 
    } while (LanjutkanInput_125 == 'y' || LanjutkanInput_125 == 'Y'); // Melakukan loop jika pengguna ingin melanjutkan

    return 0; 
}


```
#### Output:
![Output](<Naufal_Output1 Unguided.png>)

Deskripsi :

Program ini merupakan implementasi dari struktur data stack menggunakan array dalam bahasa C++. Yang digunakan untuk memeriksa apakah sebuah kalimat yang dimasukkan oleh pengguna merupakan palindrom atau tidak. Berikut adalah deskripsi rinci dari program tersebut:

1. Program memulai dengan mendefinisikan fungsi `CekPalindrom_125(string input_125)` untuk memeriksa apakah sebuah string merupakan palindrom atau bukan.
2. Dalam fungsi `CekPalindrom_125`, program menggunakan array `stack` untuk menyimpan karakter-karakter dari string input.
3. Setiap karakter dari string input dimasukkan ke dalam stack.
4. Setelah semua karakter dimasukkan, program membandingkan karakter-karakter dari string input dengan karakter-karakter yang dikeluarkan dari stack.
5. Jika semua karakter cocok, maka string input dianggap palindrom. Jika ada perbedaan, string input dianggap bukan palindrom.
6. Program kemudian mengambil input kalimat dari pengguna menggunakan fungsi `getline(cin, input_125)` dalam loop `do-while`.
7. Setelah mendapatkan input, program memanggil fungsi `CekPalindrom_125` untuk memeriksa apakah kalimat tersebut merupakan palindrom atau tidak.
8. Hasilnya dicetak ke layar.
9. Pengguna diberi opsi untuk memasukkan kalimat lain atau tidak. Jika pengguna memilih untuk melanjutkan, program akan kembali ke langkah 6. Jika tidak, program akan berakhir.

Program ini memberikan pengalaman interaktif kepada pengguna untuk memeriksa palindrom dari berbagai kalimat yang dimasukkan.

### 2.  Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakanstack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat? 

```C++
// Laprak 6 - Unguided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define MAX_SIZE 100 // Mendefinisikan ukuran maksimum stack

// Fungsi untuk membuat kalimat terbalik dari string input
string BuatKalimat_125(string input_125) {
    char stack[MAX_SIZE]; // Array untuk menyimpan karakter dari string input sebagai stack
    int top = -1; // Indeks teratas (top) stack, awalnya diatur ke -1 karena stack kosong

    int n = input_125.length(); // Mendapatkan panjang string input

    // Mengisi stack dengan karakter dari string input
    for (int i = 0; i < n; i++) {
        if (top < MAX_SIZE - 1) { // Memeriksa apakah stack masih memiliki ruang kosong
            stack[++top] = input_125[i]; // Menambahkan karakter ke stack dan mengubah nilai top
        } else {
            cout << "Lebihan"; // Jika stack penuh, mencetak pesan dan mengembalikan string kosong
            return "";
        }
    }

    string Kalimat_125; // Variabel untuk menyimpan kalimat terbalik

    // Mengambil karakter dari stack dan membangun string kalimat terbalik
    while (top >= 0) {
        Kalimat_125 += stack[top--];
    }

    return Kalimat_125; // Mengembalikan kalimat terbalik
}

int main()
{
    char LanjutkanInput125; // Variabel untuk menyimpan input pengguna (y/n) untuk melanjutkan atau tidak
    string input_125, PembalikKalimat_125; // Variabel untuk menyimpan input string dan kalimat terbalik
    int count125 = 0; // Variabel untuk menghitung jumlah kata dalam input

    do {
        cout << "---> Naufal'S Pembalik Kalimat <---\n";

        // Meminta pengguna untuk memasukkan kalimat minimal 3 kata
        MasukkanKalimat:
        cout << "Masukkan Kalimat (Minimal 3 kata ya): "; 
        getline(cin, input_125);

        // Menghitung jumlah kata dalam input
        for (char ch:input_125)
        {
            if (ch == ' ')
            {
                count125++;
            }
        }

        // Memeriksa apakah jumlah kata dalam input cukup
        if (count125 < 2)
        {
            cout << "Kata yang Anda Masukkan kurang dari 3 kata, Minimal 3 Kata ya!\n";
            goto MasukkanKalimat; // Kembali ke langkah memasukkan kalimat jika jumlah kata kurang dari 3
        }

        // Membuat kalimat terbalik dari input menggunakan fungsi BuatKalimat_125
        PembalikKalimat_125 = BuatKalimat_125(input_125);

        // Menampilkan kalimat terbalik
        cout << "Kalimat terbalik dari " << input_125 << " adalah " << PembalikKalimat_125 << endl;

        // Meminta pengguna untuk melanjutkan atau tidak
        cout << "Ingin mencoba kalimat lain? (y/n): ";
        cin >> LanjutkanInput125;
        cin.ignore(); 

    } while (LanjutkanInput125 == 'y' || LanjutkanInput125 == 'Y'); // Melakukan loop jika pengguna ingin melanjutkan

    return 0;
}


```
#### Output:
![Output](<Naufal_Output2 Unguided.png>)

Deskripsi :

Program ini adalah sebuah program sederhana yang digunakan untuk membalikkan kalimat yang dimasukkan oleh pengguna. Berikut adalah deskripsi rinci dari program tersebut:

1. Program dimulai dengan mendefinisikan fungsi `BuatKalimat_125(string input_125)` yang bertujuan untuk membuat kalimat terbalik dari string input.

2. Dalam fungsi `BuatKalimat_125`, program menggunakan array `stack` untuk menyimpan karakter-karakter dari string input.

3. Setiap karakter dari string input dimasukkan ke dalam stack.

4. Setelah semua karakter dimasukkan, program mengambil karakter-karakter dari stack dan membangun string kalimat terbalik.

5. Program kemudian mengambil input kalimat dari pengguna menggunakan fungsi `getline(cin, input_125)` dalam loop `do-while`.

6. Setelah mendapatkan input, program memanggil fungsi `BuatKalimat_125` untuk membuat kalimat terbalik dari kalimat yang dimasukkan pengguna.

7. Hasil kalimat terbalik dicetak ke layar.

8. Pengguna diberi opsi untuk memasukkan kalimat lain atau tidak. Jika pengguna memilih untuk melanjutkan, program akan kembali ke langkah 5. Jika tidak, program akan berakhir.

Program ini memberikan pengalaman interaktif kepada pengguna untuk membalikkan kalimat-kalimat yang dimasukkan dengan mudah dan efisien.

## Kesimpulan
Dapat disimpulkan bahwa stack adalah struktur data yang berguna dalam menyimpan dan mengelola data dengan prinsip LIFO (Last In, First Out). Implementasi stack dalam pemrograman C++ dapat dilakukan menggunakan array atau linked list. Stack memiliki operasi dasar seperti push, pop, top, isEmpty, isFull, ukuran, peek, clear, dan search yang memungkinkan penggunaan yang fleksibel dan efisien.

Kelebihan penggunaan stack meliputi kemudahan dalam mengelola data dengan konsep LIFO, otomatisnya penghapusan objek yang tidak diperlukan, dan pengelolaan memori yang mandiri. Namun, ada juga beberapa kelemahan seperti keterbatasan memori tumpukan, risiko overflow jika terlalu banyak elemen dimasukkan, dan keterbatasan dalam mengakses data secara acak.

Dengan memahami konsep dan operasi dasar stack, pengguna dapat mengimplementasikan stack dalam berbagai aplikasi, mulai dari penyelesaian masalah matematika hingga manajemen memori dalam sistem komputer. Sehingga, pemahaman tentang stack merupakan hal yang penting dalam pengembangan program dan pemecahan masalah dalam dunia pemrograman.

## Referensi
[1] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform, Yogyakarta, 2021.

[2] Joseph Teguh Santoso, Struktur Data dan ALgoritma, Semarang: Yayasan Prima Agus Teknik, 2021.

[3] Wanra Tarigan, Algoritma Pemograman dan Struktur Data, Purbalingga: EUREKA MEDIA AKSARA, 2022.

[4] Asisten Praktikum. Modul 6 Stack. Purwokerto: Institut Teknologi Purwokerto. 2024.