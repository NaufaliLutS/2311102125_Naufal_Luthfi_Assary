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