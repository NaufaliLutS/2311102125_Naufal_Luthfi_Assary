// Laprak 9 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Vektor untuk menyimpan nama-nama kota (simpul)
vector<string> simpul;
// Matriks 2D untuk menyimpan jarak antar kota (busur)
vector<vector<int>> busur;

// Fungsi untuk menampilkan graf (kota dan jarak antar kota)
void tampilGraph() {
    // Mencetak bagian atas (nama-nama kota)
    cout << setw(10) << " ";  // Menyisipkan spasi awal untuk penyelarasan
    for (const auto& kota : simpul) {
        cout << setw(10) << kota;  // Mencetak setiap nama kota dengan lebar 10
    }
    cout << endl;
    
    // Mencetak baris-baris (nama kota dan jarak antar kota)
    for (size_t i = 0; i < simpul.size(); i++) {
        cout << setw(10) << simpul[i];  // Mencetak nama kota di awal baris
        for (size_t j = 0; j < simpul.size(); j++) {
            cout << setw(10) << busur[i][j];  // Mencetak jarak antar kota
        }
        cout << endl;
    }
}

int main() {
    int sim_2311102125, bus125;
    
    cout << "---> Naufal'S Program menghitung jarak dari sebuah kota ke kota lainnya <---\n";
    // Meminta pengguna untuk memasukkan jumlah simpul (kota)
    cout << "Masukkan jumlah simpul: ";
    cin >> sim_2311102125;

    // Mengubah ukuran vektor simpul dan busur sesuai dengan jumlah kota
    simpul.resize(sim_2311102125);
    busur.resize(sim_2311102125, vector<int>(sim_2311102125, 0));

    // Meminta pengguna untuk memasukkan nama-nama kota
    cout << "Masukkan nama-nama kota:" << endl;
    for (int i = 0; i < sim_2311102125; i++) {
        cout << "Kota " << i + 1 << ": ";
        cin >> simpul[i];
    }

    // Meminta pengguna untuk memasukkan jumlah jalan antar kota
    cout << "Masukkan jumlah jalan antar kota: ";
    cin >> bus125;

    // Meminta pengguna untuk memasukkan jalan antar kota dan jaraknya
    cout << "Masukkan jalan antar kota dalam format (kota1 kota2 jarak):" << endl;
    for (int i = 0; i < bus125; i++) {
        string kota1, kota2;
        int jarak;
        cin >> kota1 >> kota2 >> jarak;

        // Mencari indeks kota1 dan kota2 dalam vektor simpul
        int index1 = -1, index2 = -1;
        for (int j = 0; j < sim_2311102125; j++) {  // Harusnya iterasi hingga sim_2311102125, bukan bus125
            if (simpul[j] == kota1) {
                index1 = j;
            }
            if (simpul[j] == kota2) {
                index2 = j;
            }
        }

        // Memasukkan jarak ke matriks busur jika kedua kota ditemukan
        if (index1 != -1 && index2 != -1) {
            busur[index1][index2] = jarak;
        } else {
            cout << "Kota tidak ditemukan. Pastikan nama kota sesuai." << endl;
        }
    }

    // Menampilkan graf
    tampilGraph();

    return 0;
}
