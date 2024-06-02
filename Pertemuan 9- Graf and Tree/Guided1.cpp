// Laprak 9 - Guided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <iomanip>

using namespace std;

// Array simpul menyimpan nama-nama kota
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

// Array busur menyimpan jarak antar kota
int busur[7][7] = {
    // Matriks busur yang merepresentasikan jarak antar kota,
    // nilai 0 menandakan tidak ada jalur langsung antara dua kota
    // nilai selain 0 menandakan jarak antara dua kota tersebut
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

// Fungsi untuk menampilkan graf, dengan mencetak nama kota dan jarak ke kota lainnya
void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        // Mencetak nama kota di setiap baris
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // Memeriksa kolom dalam matriks busur untuk menemukan jarak antar kota
        for (int kolom = 0; kolom < 7; kolom++) {
            // Jika terdapat jalur antar kota (nilai bukan 0)
            if (busur[baris][kolom] != 0) {
                // Mencetak nama kota tujuan beserta jaraknya
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    // Memanggil fungsi tampilGraph untuk menampilkan graf
    tampilGraph();
    return 0;
} 
