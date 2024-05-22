# <h1 align="center">Laporan Praktikum Modul 8 - Algoritma Searching</h1>
<p align="center">Naufal Luthfi Assary</p>
<p align="center">2311102125</p>

## Dasar Teori

Algoritma pencarian (searching algorithm) adalah suatu algoritma yang digunakan untuk mencari sebuah rekaman atau elemen tertentu dalam sebuah kumpulan data. Pada dasarnya, algoritma pencarian menerima sebuah kunci atau target sebagai input, kemudian menggunakan langkah-langkah tertentu untuk mencari rekaman yang sesuai dengan kunci tersebut. Proses pencarian tersebut kemudian menghasilkan dua kemungkinan, yaitu berhasil menemukan rekaman yang dicari atau tidak menemukan rekaman tersebut.

Metode Pencarian:
A. `Sequential Search:`
`Deskripsi:` Sequential search adalah proses membandingkan setiap elemen array satu per satu secara berurutan, dimulai dari elemen pertama hingga elemen yang dicari ditemukan atau hingga akhir array.
`Keuntungan:` Sederhana dan dapat digunakan baik pada array yang terurut maupun yang tidak terurut.
`Proses Algoritma:`
1. Data dibandingkan satu per satu dalam kumpulan data dengan data yang dicari.
2. Pencarian dilakukan dari elemen pertama hingga elemen terakhir.
3. Jika data yang dicari ditemukan, proses pencarian berhenti; jika tidak, pencarian dilanjutkan hingga akhir array.

B. `Binary Search:`
`Deskripsi:` Binary search adalah metode pencarian data pada array yang telah terurut. Algoritma ini lebih efisien karena membagi data menjadi dua bagian dan membandingkan dengan elemen tengah.
`Keuntungan:` Efisien untuk data yang telah terurut dengan kompleksitas waktu O(log N).
`Proses Algoritma:`
1. Data diambil dari posisi pertama hingga posisi terakhir.
2. Mencari posisi data tengah dengan membagi posisi akhir dengan 2.
3. Data yang akan dicari dibandingkan dengan data yang berada di posisi tengah.
4. Jika data yang dicari lebih besar, pencarian dilanjutkan di bagian kanan; jika lebih kecil, di bagian kiri.
5. Proses ini terus berlanjut hingga data ditemukan atau tidak ada lagi yang bisa dibagi.

## Guided 

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
// Laprak 8 - Guided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data[n] = {9,4,1,7,5,12,4,13,4,10};
    int cari = 10;
    bool ketemu = false;
    int i;

    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout <<"Program Sequential Search" <<endl;
    cout <<"data : {9,4,1,7,5,12,4,13,4,10} " <<endl;

    if (ketemu) {
        cout <<"\nAngka " << cari <<" ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << "data tidak ditemukan"<< endl;
    }

    return 0;
}
```

#### Deskripsi:

Program ini merupakan implementasi dari pencarian linear atau sequential search. Tujuan dari program ini adalah untuk mencari keberadaan suatu angka dalam array `data`. Jika angka yang dicari ditemukan dalam array, program akan mencetak indeks pertama di mana angka tersebut ditemukan. Jika tidak ditemukan, program akan mencetak pesan bahwa data tidak ditemukan.

Deskripsi alur program:
1. Program menginisialisasi array `data` yang berisi 10 elemen bilangan bulat.
2. Program mendefinisikan variabel `cari` yang menyimpan nilai yang akan dicari dalam array.
3. Program menggunakan loop `for` untuk melakukan pencarian secara sequential dalam array `data`. Loop ini akan berjalan dari indeks 0 hingga `n-1`, di mana `n` adalah panjang array `data`.
4. Saat melakukan iterasi, program memeriksa setiap elemen array apakah sama dengan nilai yang dicari (`cari`). Jika ada yang sama, program menandai bahwa angka tersebut ditemukan dengan mengatur nilai variabel `ketemu` menjadi `true` dan menyimpan indeksnya dalam variabel `i`.
5. Setelah loop selesai, program mencetak hasil pencarian. Jika nilai `ketemu` adalah `true`, program mencetak indeks pertama di mana angka ditemukan. Jika tidak, program mencetak pesan bahwa data tidak ditemukan.

Program ini menggunakan metode pencarian linear yang sederhana, di mana setiap elemen dalam array diperiksa satu per satu. Metode ini efektif untuk array yang tidak terlalu besar, tetapi kurang efisien untuk array besar karena kompleksitas waktu pencarian adalah O(n), di mana n adalah jumlah elemen dalam array.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.

```C++
// Laprak 8 - Guided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int dataArray[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void Selection_Sort(){
    int temp, min, i, j;
    for(i = 0; i < 7; i++){
        min = i;
        for(j = i + 1; j < 7; j++){
            if(dataArray[j] < dataArray[min]){
                min = j;
            }
        }
        temp = dataArray[i];
        dataArray[i] = dataArray[min];
        dataArray[min] = temp;
    }
}

void BinarySearch(){
    int awal, akhir, tengah;
    bool b_flag = false;
    awal = 0;
    akhir = 6;
    while(!b_flag && awal <= akhir){
        tengah = (awal + akhir)/2;
        if(dataArray[tengah] == cari){
            b_flag = true;
        } else if(dataArray[tengah] < cari){
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag){
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan" << endl;
    }
}

int main(){
    cout << "BINARY SEARCH" << endl;
    cout << "\nData : ";
    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;

    cout << "Masukkan data yang ingin dicari : ";
    cin >> cari;
    
    cout << "\nData diurutkan : ";
    Selection_Sort();

    for(int x = 0; x < 7; x++){
        cout << setw(3) << dataArray[x];
    }
    cout << endl;
    BinarySearch();
    _getche();
    return 0;
}
```

#### Deskripsi:

Program ini adalah implementasi algoritma binary search untuk mencari suatu nilai dalam array yang sudah diurutkan secara menaik. Berikut adalah deskripsi singkat dari program:

1. **Inisialisasi Data**: Program menginisialisasi array `dataArray` yang berisi 7 elemen bilangan bulat secara statis.

2. **Selection Sort**: Program memiliki fungsi `Selection_Sort()` untuk mengurutkan array `dataArray` menggunakan algoritma selection sort. Algoritma ini bekerja dengan cara mencari elemen terkecil dari array dan menukar posisi dengan elemen di indeks awal. Proses ini diulang untuk setiap indeks hingga array terurut.

3. **Binary Search**: Program memiliki fungsi `BinarySearch()` untuk melakukan pencarian binary pada array yang sudah diurutkan. Algoritma binary search membagi array menjadi dua bagian dan memeriksa apakah nilai yang dicari berada di bagian kiri atau kanan array. Proses ini terus berlanjut hingga nilai yang dicari ditemukan atau tidak ada lagi bagian array yang perlu diperiksa.

4. **Main Function**: 
   - Program mencetak array awal sebelum diurutkan.
   - Kemudian, program meminta pengguna untuk memasukkan nilai yang ingin dicari.
   - Setelah itu, program mengurutkan array menggunakan selection sort dan mencetaknya.
   - Selanjutnya, program melakukan pencarian binary untuk nilai yang dimasukkan pengguna.
   - Hasil pencarian, yaitu apakah nilai ditemukan atau tidak, dicetak di layar.

Program ini menggabungkan algoritma selection sort untuk mengurutkan array dan algoritma binary search untuk mencari nilai. Algoritma binary search lebih efisien daripada pencarian linear, terutama untuk array yang sudah diurutkan, karena kompleksitas waktunya adalah O(log n), di mana n adalah jumlah elemen dalam array.


## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
// Laprak 8 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <algorithm>

using namespace std;

// Fungsi binarySearch untuk mencari target di dalam array yang telah diurutkan
int binarySearch(char arr[], int size125, char target) {
    int left125 = 0;  // Inisialisasi batas kiri
    int right125 = size125 - 1;  // Inisialisasi batas kanan

    // Selama batas kiri masih kurang atau sama dengan batas kanan
    while (left125 <= right125) {
        int mid = left125 + (right125 - left125) / 2;  // Hitung nilai tengah

        // Jika target ditemukan di posisi tengah, kembalikan indeksnya
        if (arr[mid] == target) {
            return mid;
        }

        // Jika nilai tengah lebih kecil dari target, geser batas kiri ke tengah + 1
        if (arr[mid] < target) {
            left125 = mid + 1;
        }
        // Jika nilai tengah lebih besar dari target, geser batas kanan ke tengah - 1
        else {
            right125 = mid - 1;
        }
    }

    // Jika target tidak ditemukan, kembalikan -1
    return -1;
}

// Fungsi untuk mengurutkan string
void sortString(string &str) {
    sort(str.begin(), str.end());  // Mengurutkan string menggunakan fungsi sort dari library algorithm
}

int main() {
    string kalimat125;  // Deklarasi variabel untuk menyimpan kalimat
    char target125;  // Deklarasi variabel untuk menyimpan huruf yang dicari

    cout << "---> Naufal'S Program Mencari Huruf di dalam Kalimat <---\n";
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat125);  // Membaca kalimat dari input pengguna

    // Menghapus semua spasi dari kalimat
    kalimat125.erase(remove(kalimat125.begin(), kalimat125.end(), ' '), kalimat125.end());

    // Mengurutkan kalimat menggunakan fungsi sortString
    sortString(kalimat125);

    // Menampilkan kalimat yang sudah diurutkan
    cout << "Kalimat setelah diurutkan: " << kalimat125 << endl;

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target125;  // Membaca huruf yang ingin dicari dari input pengguna

    // Mencari huruf yang diinginkan menggunakan binary search
    int result125 = binarySearch(&kalimat125[0], kalimat125.size(), target125);

    // Jika huruf ditemukan, cetak posisinya
    if (result125 != -1) {
        cout << "Huruf " << target125 << " ditemukan pada indeks ke-" << result125 << " setelah diurutkan." << endl;
    } 
    // Jika huruf tidak ditemukan, cetak pesan tidak ditemukan
    else {
        cout << "Huruf " << target125 << " tidak ditemukan." << endl;
    }

    return 0;  
}

```
#### Output:
![Output](<Naufal_Output1 Unguided.png>)

#### Deskripsi :

Program ini merupakan implementasi dari algoritma binary search untuk mencari keberadaan sebuah huruf dalam sebuah kalimat. Berikut adalah deskripsi singkat dari program:

Fungsi `binarySearch`:
- Fungsi ini digunakan untuk mencari target di dalam sebuah array yang telah diurutkan.
- Menerima tiga parameter: array yang akan dicari (`arr`), ukuran array (`size125`), dan target yang ingin dicari (`target`).
- Menggunakan pendekatan binary search untuk mencari target di dalam array yang diurutkan.
- Jika target ditemukan, fungsi mengembalikan indeksnya. Jika tidak ditemukan, fungsi mengembalikan -1.

Fungsi `sortString`:
- Fungsi ini digunakan untuk mengurutkan string.
- Menerima satu parameter, yaitu string yang akan diurutkan (`str`).
- Menggunakan fungsi `sort` dari library `<algorithm>` untuk mengurutkan string.

Fungsi `main`:
- Pada bagian ini, program meminta pengguna untuk memasukkan sebuah kalimat.
- Setelah kalimat dimasukkan, program menghapus semua spasi dari kalimat tersebut menggunakan `erase` dan `remove`.
- Kalimat yang sudah dihapus spasi kemudian diurutkan menggunakan fungsi `sortString`.
- Setelah itu, program meminta pengguna untuk memasukkan huruf yang ingin dicari.
- Program menggunakan fungsi `binarySearch` untuk mencari keberadaan huruf tersebut dalam kalimat yang sudah diurutkan.
- Hasil pencarian ditampilkan kepada pengguna.
  
Program ini memanfaatkan algoritma binary search untuk mencari huruf dalam kalimat yang sudah diurutkan. Algoritma ini efisien untuk pencarian dalam data yang sudah diurutkan.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
// Laprak 8 - Unguided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string kalimat125;  // Deklarasi variabel untuk menyimpan kalimat yang akan diinput
    int vokal125 = 0;  // Deklarasi variabel untuk menghitung jumlah huruf vokal

    cout << "---> Naufal'S Program Menghitung Jumlah Huruf Vokal <---\n";
    cout << "Input Kalimat: ";
    getline(cin, kalimat125);  // Membaca kalimat dari input pengguna
    
    // Loop untuk memeriksa setiap karakter dalam kalimat
    for (int i = 0; i < kalimat125.length(); i++)
    {
        char ch = kalimat125[i];  // Mendapatkan karakter pada posisi i
        // Memeriksa apakah karakter adalah huruf vokal
        if (ch == 'a' || ch == 'i' || ch == 'u' || ch == 'e' || ch == 'o' ||
            ch == 'A' || ch == 'I' || ch == 'U' || ch == 'E' || ch == 'O')
        {
            vokal125++;  // Menambah hitungan huruf vokal
        }
    }

    // Jika ada huruf vokal yang ditemukan
    if (vokal125 > 0)
    {
        cout << "Jumlah huruf vokal adalah " << vokal125 << endl;  // Menampilkan jumlah huruf vokal
    }
    // Jika tidak ada huruf vokal yang ditemukan
    else
    {
        cout << "Huruf vokal tidak ditemukan" << endl;  // Menampilkan pesan tidak ada huruf vokal
    }
    
    return 0;  
}

```
#### Output:
![Output](<Naufal_Output2 Unguided.png>)

#### Deskripsi:

Program ini merupakan program sederhana yang menghitung jumlah huruf vokal dalam sebuah kalimat yang dimasukkan oleh pengguna.

Fungsi `main`:
- Program meminta pengguna untuk memasukkan sebuah kalimat.
- Menggunakan `getline()` untuk membaca kalimat dari input pengguna dan menyimpannya dalam variabel `kalimat125`.
- Program melakukan iterasi melalui setiap karakter dalam kalimat menggunakan loop `for`.
- Di dalam loop, setiap karakter diperiksa untuk menentukan apakah itu huruf vokal. Jika ya, variabel `vokal125` ditambah satu.
- Setelah selesai melakukan iterasi, program menampilkan jumlah huruf vokal yang ditemukan. Jika tidak ada huruf vokal, program akan menampilkan pesan bahwa huruf vokal tidak ditemukan.

Variabel yang Digunakan:
- `kalimat125`: Variabel untuk menyimpan kalimat yang dimasukkan oleh pengguna.
- `vokal125`: Variabel untuk menghitung jumlah huruf vokal dalam kalimat.

Program ini hanya menghitung jumlah huruf vokal dalam sebuah kalimat. Ini adalah contoh sederhana dari bagaimana sebuah program dapat melakukan analisis sederhana pada input teks.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
// Laprak 8 - Unguided 3
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>

using namespace std;

int main()
{
    int n125 = 10;  // Deklarasi dan inisialisasi variabel untuk jumlah elemen dalam array
    int data[n125] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};  // Deklarasi dan inisialisasi array dengan 10 elemen
    int cari125;  // Variabel untuk menyimpan angka yang akan dicari
    int ketemu125 = 0;  // Variabel untuk menghitung jumlah kemunculan angka yang dicari

    cout << "---> Naufal'S Program Menghitung Jumlah Sebuah Angka di Sequential Search <---" << endl;
    cout << "Data : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;
    cout << "Masukkan Data: ";
    cin >> cari125;  // Membaca angka yang akan dicari dari input pengguna

    // Loop untuk melakukan pencarian angka dalam array
    for (int i = 0; i < n125; i++)
    {
        if (data[i] == cari125)  // Memeriksa apakah elemen array sama dengan angka yang dicari
        {
            ketemu125++;  // Menambah hitungan jika angka ditemukan
        }
    }

    // Jika angka ditemukan dalam array
    if (ketemu125 > 0)
    {
        cout << "Angka " << cari125 << " ditemukan " << ketemu125 << " kali" << endl;  // Menampilkan jumlah kemunculan angka
    }
    // Jika angka tidak ditemukan dalam array
    else
    {
        cout << cari125 << " tidak ditemukan" << endl;  // Menampilkan pesan bahwa angka tidak ditemukan
    }

    return 0;  
}

```
#### Output:
![Output](<Naufal_Output3 Unguided.png>)

#### Deskripsi:

Program ini adalah implementasi dari pencarian sekuensial (sequential search) untuk mencari jumlah kemunculan suatu angka dalam sebuah array.

### Fungsi `main`:
- Program ini dimulai dengan mendeklarasikan dan menginisialisasi variabel-variabel yang dibutuhkan, seperti `n125` untuk jumlah elemen dalam array, `data` untuk menyimpan data integer, `cari125` untuk menyimpan angka yang akan dicari, dan `ketemu125` untuk menghitung jumlah kemunculan angka yang dicari.
- Selanjutnya, program mencetak judul program dan array data yang akan dicari.
- Kemudian, program meminta pengguna untuk memasukkan angka yang akan dicari.
- Program melakukan iterasi melalui array data menggunakan loop `for`.
- Di dalam loop, setiap elemen array diperiksa untuk menentukan apakah sama dengan angka yang dicari. Jika ya, variabel `ketemu125` ditambah satu.
- Setelah selesai melakukan iterasi, program menampilkan jumlah kemunculan angka yang dicari. Jika angka tidak ditemukan, program akan menampilkan pesan bahwa angka tidak ditemukan.

Variabel yang Digunakan:
- `n125`: Variabel untuk menyimpan jumlah elemen dalam array.
- `data`: Array untuk menyimpan data integer.
- `cari125`: Variabel untuk menyimpan angka yang akan dicari.
- `ketemu125`: Variabel untuk menghitung jumlah kemunculan angka yang dicari.

Program ini adalah contoh sederhana dari pencarian sekuensial dalam array. Ini berguna untuk menemukan jumlah kemunculan suatu angka dalam dataset.

## Kesimpulan
Dapat disimpulkan bahwa, kedua metode pencarian tersebut memiliki peran penting tergantung pada sifat data yang akan dicari.

Sequential Search: Cocok untuk data yang tidak terurut. Pencarian dilakukan secara berurutan satu per satu. Meskipun sederhana, namun dapat menghabiskan waktu lebih lama untuk pencarian pada data yang besar.

Binary Search: Efisien untuk data yang telah terurut. Pencarian dilakukan dengan membagi data menjadi dua bagian dan membandingkan dengan elemen tengah. Meskipun membutuhkan data yang terurut, namun memiliki kompleksitas waktu yang lebih efisien untuk data yang besar.

## Referensi
[1] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform, Yogyakarta, 2021.

[2] Joseph Teguh Santoso, Struktur Data dan ALgoritma, Semarang: Yayasan Prima Agus Teknik, 2021.

[3] Budiman, A. & Rusdi, A. (2020). Penerapan Algoritma Pencarian Binary Search pada Sistem Basis Data untuk Meningkatkan Kecepatan Pencarian Data. Jurnal Sains dan Teknologi Komputer, 11(2), 123-130.

[4] Kartiko Ardi Widodo, Suryo Adi Wibowo, dan Nurlaily Vendyansyah. Penerapan Sequential Search Untuk Pengelolaan Data Barang, Vol. 15 No. 1 Mei 2021.

[5] Asisten Praktikum. Modul 8 Algoritma Searching. Purwokerto: Institut Teknologi Purwokerto. 2024.