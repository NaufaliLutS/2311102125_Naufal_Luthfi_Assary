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
