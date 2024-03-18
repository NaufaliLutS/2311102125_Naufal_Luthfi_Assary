// Laprak 2 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D
#include <iostream>

using namespace std;

int main() {
    int SizeArray_125; // Ukuran Array yang dimasukkan oleh User
    cout << "-----------------------------------------------------\n";
    cout << "|--------> Naufal-Program Ganjil dan Genap <--------|\n";
    cout << "-----------------------------------------------------\n";
    cout << "Masukkan Ukuran Array : "; 
    cin >> SizeArray_125;

    int Angka_125[SizeArray_125]; // Deklarasi Array untuk Menyimpan Angka-Angka
    int Genap_125[SizeArray_125]; // Deklarasi Array untuk Menyimpan Angka Genap
    int Ganjil_125[SizeArray_125]; // Deklarasi Array untuk Menyimpan Angka Ganjil
    int Genap = 0; // Jumlah Angka untuk Angka Genap
    int Ganjil = 0; // Jumlah Angka untuk Angka Ganjil

    cout << "|---------------------------------------------------|\n";

    // Meminta Pengguna untuk Memasukkan Angka-Angka
    cout << "Masukkan Angka dengan Limit yang Sudah Anda Tentukan\n";
    cout << "Pisahkan Angka dengan Koma dan Akhiri dengan Titik\n";
    cout << "Masukkan Angka : ";
    for (int i = 0; i < SizeArray_125; ++i) {
        cin >> Angka_125[i];
        char comma;
        cin >> comma;
        if (comma == '\n') // Memeriksa Input yang dipisahkan oleh Koma dan Mengakhiri dengan Titik
            break;
    }

    // Memisahkan angka genap dan ganjil
    for (int i = 0; i < SizeArray_125; ++i) {
        if (Angka_125[i] % 2 == 0)
            Genap_125[Genap++] = Angka_125[i]; // Menyimpan Angka Genap
        else
            Ganjil_125[Ganjil++] = Angka_125[i]; // Menyimpan Angka Ganjil
    }

    cout << "-----------------------------------------------------\n";
    cout << "|-----------------> Hasil Program <-----------------|\n";
    cout << "-----------------------------------------------------\n";

    // Menampilkan data array yang dimasukkan oleh pengguna
    cout << "Data Array   : ";
    for (int i = 0; i < SizeArray_125; ++i) {
        cout << Angka_125[i];
        if (i != SizeArray_125 - 1)
            cout << " ";
    }
    cout << endl;

    // Menampilkan angka genap
    cout << "Nomor Genap  : ";
    for (int i = 0; i < Genap; ++i) {
        cout << Genap_125[i];
        cout << ", ";
    }
    cout << endl;

    // Menampilkan angka ganjil
    cout << "Nomor Ganjil : ";
    for (int i = 0; i < Ganjil; ++i) {
        cout << Ganjil_125[i];
        cout << ", ";
    }
    cout << endl;

    return 0;
}
