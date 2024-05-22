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
