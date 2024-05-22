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
