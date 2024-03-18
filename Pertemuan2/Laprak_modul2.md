# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Naufal Luthfi Assary</p>
<p align="center">2311102125</p>

## Dasar Teori

Tipe data merupakan klasifikasi data berdasarkan tipe datanya. Tipe data diperlukan agar kompiler mengetahui cara menggunakan data. Tipe data yang diperiksa adalah tipe data primitif, tipe data abstrak, dan tipe data koleksi. Map adalah wadah asosiatif yang menyimpan elemen terkait. Setiap elemen memiliki key dan value terkait.

## Guided 

### 1. Input Program Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
    // Deklarasi array
    int arr[2][3][3];
    // Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }
    // Output Array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    // Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}

```
Program diatas merupakan program yang menggunakan tipe data primitive yang berisi 4 jenis aritmatika dasar yaitu penjumlahan, pengurangan, perkalian, pembagian.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;
int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}

```
Program diatas ialah program yang mengunakan struct untuk menyimpan data yang berlainan tipe data serta menampilkannya, yang dimana char name untuk nama, char addres untuk alamat, dan int age untuk usia.

## Unguided 

### 1. [Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user![Soal](<../Soal Unguided1.png>)]

```C++

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/NaufaliLutS/2311102125_Naufal_Luthfi_Assary/blob/main/Pertemuan1/Screenshot%202024-03-12%20222515.png)

Deskripsi :
Program diatas ialah program yang menggunakan tipe data primitif yang digunakan oleh dua fungsi yaitu perkalian dan pembagian.
Kesimpulan yang dapat saya ambil ialah bahwa setiap tipe data memiliki fungsi kegunaan dan kebutuhannya masing masing dan tergantung orang yang memilih tipe datanya.

### 2. [Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!]

Class lebih banyak digunakan untuk objek yang dimana setiap proses di dalamnya saling berhubungan. Sedangkan struct biasa digunakan untuk struktur data atau objek yang sebenarnya, menyimpan data menggunakan variabel dan membuat fungsi. (Aristo, 2021).

Adapun perbedaan yang cukup menarik bahwa class dapat melakukan inheritance dengan subclass dimana fungsi pada subclass dapat digunakan untuk class lainnya. Akan tetapi struct tidak bisa dilakukan inheritance.

Contoh Program menggunakan Class
```C++

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/NaufaliLutS/2311102125_Naufal_Luthfi_Assary/blob/main/Pertemuan1/Screenshot%202024-03-12%20222555.png)

Deskripsi :
Program diatas ialah program untuk menyimpan data Novel menggunakan Class yang dimana menginputkannya menggunakan strcpy dan dipanggil menggunakan cout.

Contoh Program menggunakan Struct
```C++

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/NaufaliLutS/2311102125_Naufal_Luthfi_Assary/blob/main/Pertemuan1/Screenshot%202024-03-12%20222839.png)

Deskripsi : 
Program diatas ialah program untuk menyimpan data Novel menggunakan fungsi struct yang dimana menginputkannya menggunakan strcpy dan dipanggil menggunakan printf.

### 3. [Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!]

```C++

```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/NaufaliLutS/2311102125_Naufal_Luthfi_Assary/blob/main/Pertemuan1/Screenshot%202024-03-12%20222922.png)

Deskripsi :
Program diatas merupakan program menggunakan map untuk menyimpan stok laptop di suatu toko yang dimana string digunakan sebagai key dan int merupakan value dari key tersebut. Dan di program diatas menggunakan perulangan for menampilkan isi map Merk_125. Setiap pasangan kunci-nilai dari map diakses menggunakan variabel pair, di mana pair.first adalah kunci (nama merek laptop) dan pair.second adalah nilai (jumlah stok laptop).

Jadi, perbedaan antara array dan map ialah, map merupakan struktur data yang memetakan key ke value sedangkan Array merupakan struktur data yang terdiri dari kumpulan elemen dengan tipe data yang sama yang di indekskan dari 0 hingga -1 panjang array.


## Kesimpulan
Kesimpulan yang saya dapat ialah terdapat tiga jenis tipe data dasar dalam pemrograman: tipe data primitif (seperti integer, float, char, dan boolean), tipe data koleksi (seperti array), dan map (atau dictionary). Tipe data primitif digunakan untuk menyimpan nilai tunggal, sementara tipe data koleksi digunakan untuk menyimpan kumpulan nilai dengan cara yang lebih terstruktur dan fleksibel. Map adalah struktur data yang memetakan key ke value, berguna untuk pencarian efisien dan menyimpan data terstruktur. Pemahaman tentang perbedaan dan karakteristik dari masing-masing tipe data ini memungkinkan untuk membuat pilihan yang tepat dalam pengembangan program kedepannya.


## Referensi
[1] Wika Purbasari, Taufiq Iqbal, dkk. Algoritma Pemrograman. Nagrak, Benteng, Warudoyong, Sukabumi. 2024.

[2] Muhammad Taufik Dwi Putra, Munawir, dkk. Belajar Pemrograman Lanjut Dengan C++. Bandung, Jawa Barat. 2023.