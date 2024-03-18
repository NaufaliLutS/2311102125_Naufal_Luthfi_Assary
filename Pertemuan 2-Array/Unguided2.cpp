// Laprak 2 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D
#include <iostream>

using namespace std;

int main() {
    int X_125, Y_125, Z_125; // Deklarasi Variabel Untuk Ukuran Array 3 Dimensi

    // Meminta Input Ukuran Array untuk Setiap Dimensi
    cout << "------------------------------------------\n";
    cout << "|---> Naufal-Program Array 3 Dimensi <---|\n";
    cout << "------------------------------------------\n";
    cout << "Masukkan Ukuran Array Dimensi X : "; cin >> X_125;
    cout << "Masukkan Ukuran Array Dimensi Y : "; cin >> Y_125;
    cout << "Masukkan Ukuran Array Dimensi Z : "; cin >> Z_125;

    // Deklarasi Array 3 Dimensi dengan Ukuran yang dimasukkan Oleh User
    int Arr_125[X_125][Y_125][Z_125];

    // Meminta User Untuk Memasukkan Elemen Array
    cout << "Masukkan Elemen Array:" << endl;
    for (int x = 0; x < X_125; x++) {
        for (int y = 0; y < Y_125; y++) {
            for (int z = 0; z < Z_125; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> Arr_125[x][y][z];
            }
        }
        cout << endl;
    }

    // Menampilkan Sebagian Data Array 3 Dimensi
    for (int x = 0; x < X_125; x++) {
        for (int y = 0; y < Y_125; y++) {
            for (int z = 0; z < Z_125; z++) {
                cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << Arr_125[x][y][z] << endl;
            }
        }
        cout << endl;
    }

    // Menampilkan Seluruh Data Array 3 Dimensi
    cout << "Hasil Array 3 Dimensi:" << endl;
    for (int x = 0; x < X_125; x++) {
        for (int y = 0; y < Y_125; y++) {
            for (int z = 0; z < Z_125; z++) {
                cout << Arr_125[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
