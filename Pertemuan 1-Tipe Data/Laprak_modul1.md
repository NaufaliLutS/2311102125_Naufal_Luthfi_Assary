# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Naufal Luthfi Assary</p>
<p align="center">2311102125</p>

## Dasar Teori

Tipe data merupakan klasifikasi data berdasarkan tipe datanya. Tipe data diperlukan agar kompiler mengetahui cara menggunakan data. Tipe data yang diperiksa adalah tipe data primitif, tipe data abstrak, dan tipe data koleksi. Map adalah wadah asosiatif yang menyimpan elemen terkait. Setiap elemen memiliki key dan value terkait.

## Guided 

### 1. Tipe data primitif

```C++
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    char op;
    float num1, num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch (op) {

        case '+':
            cout << "Result: " << num1 + num2;
            break;

        case '-':
            cout << "Result: " << num1 - num2;
            break;

        case '*':
            cout << "Result: " << num1 * num2;
            break;

        case '/':
            if (num2 != 0) {
            cout << "Result: " << fixed << setprecision(2) << num1 / num2;
            } else {
            cout << "Error! Division by zero is not allowed.";
            }
            break;

        default:
            cout << "Error! Operator is not correct";
    }

    return 0;
}

```
Program diatas merupakan program yang menggunakan tipe data primitive yang berisi 4 jenis aritmatika dasar yaitu penjumlahan, pengurangan, perkalian, pembagian.

### 2. Tipe data Abstrak

```C++
#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char name_125[50];
    char address_125[100];
    int age_125;
};
int main()
{
    struct Mahasiswa mhs1, mhs2;

    strcpy(mhs1.name_125, "Dian");
    strcpy(mhs1.address_125, "Mataram");
    mhs1.age_125 = 22;
    strcpy(mhs2.name_125, "Bambang");
    strcpy(mhs2.address_125, "Surabaya");
    mhs2.age_125 = 23;

    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name_125);
    printf("Alamat: %s\n", mhs1.address_125);
    printf("Umur: %d\n", mhs1.age_125);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name_125);
    printf("Alamat: %s\n", mhs2.address_125);
    printf("Umur: %d\n", mhs2.age_125);
    return 0;

}

```
Program diatas ialah program yang mengunakan struct untuk menyimpan data yang berlainan tipe data serta menampilkannya, yang dimana char name untuk nama, char addres untuk alamat, dan int age untuk usia.

### 3. Tipe data Koleksi

```C++
#include <iostream>
#include <array>
using namespace std;

int main(){
    int nilai_125[5];
    nilai_125[0] = 23;
    nilai_125[1] = 50;
    nilai_125[2] = 34;
    nilai_125[3] = 78;  
    nilai_125[4] = 90;

    cout << "Isi array pertama : " << nilai_125[0] << endl;
    cout << "Isi array kedua : " << nilai_125[1] << endl;
    cout << "Isi array ketiga : " << nilai_125[2] << endl;
    cout << "Isi array keempat : " << nilai_125[3] << endl;
    cout << "Isi array kelima : " << nilai_125[4] << endl;
    
    return 0;
}

```
Program diatas ialah program menyipam sebuah data di array nilai yang memiliki oanjang 5 dan nilai yang berbeda beda di setipa indeksnya. Indeks ke 0 ialah 23, indeks ke 1 ialah 50, indeks ke 2 ialah 34, indeks ke 3 ialah 78, indeks ke 4 ialah 90.

## Unguided 

### 1. [Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!]

```C++
#include <iostream>
#include <iomanip>

using namespace std;

int x_125, y_125;
char pil_125;

int perkalian_125(int x_125, int y_125)// Fungsi untuk perkalian
{
     return x_125*y_125;
}

float pembagian_125(float x_125, float y_125)// Fungsi untuk pembagian
{
    return x_125/y_125;
}

int main()
{
    MenuUtama_125 :
    cout << "----------------\n"; 
    cout << "|     Menu     |\n";
    cout << "----------------\n";
    cout << "1. Perkalian\n";
    cout << "2. Pembagian\n";
    cout << "3. Keluar\n";
    cout << "Masukkan Pilihan Anda : ";
    cin >> pil_125;

    switch (pil_125)
    {
    case '1':// Jika memilih 1, maka Anda akan menghitung perkalian
        cout << "Perkalian\n";
        cout << "Masukkan Bil Pertama : ";
        cin >> x_125;
        cout << "Masukkan Bil Kedua : ";
        cin >> y_125;
        cout << "Hasil Perkalian : " << perkalian_125(x_125,y_125) << endl; // Untuk memanggil fungsi perkalian
        goto MenuUtama_125;// Fungsi goto untuk kembali ke Menu Utama
        break;

    case '2':// Jika memilih 2, maka Anda akan menghitung pembagian
        cout << "Pembagian\n";
        cout << "Masukkan Pembilang : ";
        cin >> x_125;
        cout << "Masukkan Penyebut : ";
        cin >> y_125;
        if (y_125 == 0)
        {
            cout << "Penyebut tidak boleh = 0";
        } else {
            cout << "Hasil Pembagian : " << fixed << setprecision(2) << pembagian_125(x_125,y_125) << endl;// Untuk memanggil fungsi pembagian
        }
        goto MenuUtama_125;// Fungsi goto untuk kembali ke Menu Utama
        break;

    case '3':// Jika memilih 3, maka Anda akan keluar dari program
        cout << "Anda telah keluar dari menu";
        return false;
        break;

    default:
        cout << "Silahkan Masukkan Pilihan Yang Benar\n";
        goto MenuUtama_125;// Fungsi goto untuk kembali ke Menu Utama
        break;
    }

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/NaufaliLutS/2311102125_Naufal_Luthfi_Assary/blob/main/Pertemuan%201-Tipe%20Data/Screenshot%202024-03-12%20222515.png)

Deskripsi :
Program diatas ialah program yang menggunakan tipe data primitif yang digunakan oleh dua fungsi yaitu perkalian dan pembagian.
Kesimpulan yang dapat saya ambil ialah bahwa setiap tipe data memiliki fungsi kegunaan dan kebutuhannya masing masing dan tergantung orang yang memilih tipe datanya.

### 2. [Menjelaskan fungsi dari class dan struct secara detail dan memberikan contoh programnya]

Class lebih banyak digunakan untuk objek yang dimana setiap proses di dalamnya saling berhubungan. Sedangkan struct biasa digunakan untuk struktur data atau objek yang sebenarnya, menyimpan data menggunakan variabel dan membuat fungsi. (Aristo, 2021).

Adapun perbedaan yang cukup menarik bahwa class dapat melakukan inheritance dengan subclass dimana fungsi pada subclass dapat digunakan untuk class lainnya. Akan tetapi struct tidak bisa dilakukan inheritance.

Contoh Program menggunakan Class
```C++
#include <iostream>
#include <string.h>

using namespace std;

class Novel
{
    public:
    char Judul_125[50];// Deklarasi
    char Penerbit_125[100];
    int Tahun_125;
};

int main()
{
    Novel Novel1;
    strcpy(Novel1.Judul_125, "Cinta Pertama");// Untuk memasukkan Judul Novel
    strcpy(Novel1.Penerbit_125, "Naufal");// Untuk memasukkan Penerbit Novel
    Novel1.Tahun_125 = 2023;// Untuk memasukkan Tahun Novel

    cout << "--Novel 1--\n";
    cout << "Judul: " << Novel1.Judul_125 << endl;// Untuk memanggil Judul Novel
    cout << "Penerbit: " << Novel1.Penerbit_125 << endl;// Untuk memanggil Penerbit Novel
    cout << "Tahun: " << Novel1.Tahun_125 << endl;// Untuk memanggil Tahun Buku

    return 0;

}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/NaufaliLutS/2311102125_Naufal_Luthfi_Assary/blob/main/Pertemuan%201-Tipe%20Data/Screenshot%202024-03-12%20222555.png)

Deskripsi :
Program diatas ialah program untuk menyimpan data Novel menggunakan Class yang dimana menginputkannya menggunakan strcpy dan dipanggil menggunakan cout.

Contoh Program menggunakan Struct
```C++
#include <stdio.h>
#include <string.h>

struct Novel
{
    char Judul_125[50];// deklarasi
    char Penerbit_125[100];
    int Tahun_125;
};

int main()
{
    struct Novel Novel1, Novel2;
    strcpy(Novel1.Judul_125, "Cinta Pertama");// Untuk memasukkan Judul Novel
    strcpy(Novel1.Penerbit_125, "Naufal");// Untuk memasukkan Penerbit Novel
    Novel1.Tahun_125 = 2023;// Untuk memasukkan Tahun Novel
    strcpy(Novel2.Judul_125, "Dia Yang Engkau Pilih");
    strcpy(Novel2.Penerbit_125, "Naufal");
    Novel2.Tahun_125 = 2024;

    printf("Novel 1\n");
    printf("judul : %s \n", Novel1.Judul_125);// Untuk memanggil Judul Novel
    printf("Penerbit : %s \n", Novel1.Penerbit_125);// Untuk memanggil Penerbit Novel
    printf("Tahun : %d \n", Novel1.Tahun_125);// Untuk memanggil Tahun Novel
    printf("\n");
    printf("Novel 2\n");
    printf("Judul : %s \n", Novel2.Judul_125);
    printf("Penerbit : %s \n", Novel2.Penerbit_125);
    printf("Tahun : %d \n", Novel2.Tahun_125);

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/NaufaliLutS/2311102125_Naufal_Luthfi_Assary/blob/main/Pertemuan%201-Tipe%20Data/Screenshot%202024-03-12%20222839.png)

Deskripsi : 
Program diatas ialah program untuk menyimpan data Novel menggunakan fungsi struct yang dimana menginputkannya menggunakan strcpy dan dipanggil menggunakan printf.

### 3. [Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan array dengan map!]

```C++
#include <iostream>
#include <map>

using namespace std;

int main()
{   
    map <string, int> Merk_125;// membuat map dengan tipe data string dan int
    Merk_125["Asus"] = 25;
    Merk_125["Lenovo"] = 24;
    Merk_125["Acer"] = 23;
    Merk_125["HP"] = 22;
    Merk_125["MSI"] = 21;
    Merk_125["MacBook"] = 20;

    cout << "--Stok Laptop di Toko iLutS Store--\n";
   int i = 1;
    for (const auto & pair : Merk_125) { // Memanggil isi map menggunakan perulangan
        cout << i << ". " << pair.first << ": " << pair.second << endl;
        i++;
    }
    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/NaufaliLutS/2311102125_Naufal_Luthfi_Assary/blob/main/Pertemuan%201-Tipe%20Data/Screenshot%202024-03-12%20222922.png)

Deskripsi :
Program diatas merupakan program menggunakan map untuk menyimpan stok laptop di suatu toko yang dimana string digunakan sebagai key dan int merupakan value dari key tersebut. Dan di program diatas menggunakan perulangan for menampilkan isi map Merk_125. Setiap pasangan kunci-nilai dari map diakses menggunakan variabel pair, di mana pair.first adalah kunci (nama merek laptop) dan pair.second adalah nilai (jumlah stok laptop).

Jadi, perbedaan antara array dan map ialah, map merupakan struktur data yang memetakan key ke value sedangkan Array merupakan struktur data yang terdiri dari kumpulan elemen dengan tipe data yang sama yang di indekskan dari 0 hingga -1 panjang array.


## Kesimpulan
Kesimpulan yang saya dapat ialah terdapat tiga jenis tipe data dasar dalam pemrograman: tipe data primitif (seperti integer, float, char, dan boolean), tipe data koleksi (seperti array), dan map (atau dictionary). Tipe data primitif digunakan untuk menyimpan nilai tunggal, sementara tipe data koleksi digunakan untuk menyimpan kumpulan nilai dengan cara yang lebih terstruktur dan fleksibel. Map adalah struktur data yang memetakan key ke value, berguna untuk pencarian efisien dan menyimpan data terstruktur. Pemahaman tentang perbedaan dan karakteristik dari masing-masing tipe data ini memungkinkan untuk membuat pilihan yang tepat dalam pengembangan program kedepannya.


## Referensi
[1] Wika Purbasari, Taufiq Iqbal, dkk. Algoritma Pemrograman. Nagrak, Benteng, Warudoyong, Sukabumi. 2024.

[2] Muhammad Taufik Dwi Putra, Munawir, dkk. Belajar Pemrograman Lanjut Dengan C++. Bandung, Jawa Barat. 2023.