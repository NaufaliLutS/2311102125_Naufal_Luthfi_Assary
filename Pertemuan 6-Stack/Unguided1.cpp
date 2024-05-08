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
