// Laprak 8 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <algorithm>

using namespace std;

// Fungsi binarySearch untuk mencari target di dalam array yang telah diurutkan
int binarySearch(char arr[], int size125, char target) {
    int left125 = 0;  // Inisialisasi batas kiri
    int right125 = size125 - 1;  // Inisialisasi batas kanan

    // Selama batas kiri masih kurang atau sama dengan batas kanan
    while (left125 <= right125) {
        int mid = left125 + (right125 - left125) / 2;  // Hitung nilai tengah

        // Jika target ditemukan di posisi tengah, kembalikan indeksnya
        if (arr[mid] == target) {
            return mid;
        }

        // Jika nilai tengah lebih kecil dari target, geser batas kiri ke tengah + 1
        if (arr[mid] < target) {
            left125 = mid + 1;
        }
        // Jika nilai tengah lebih besar dari target, geser batas kanan ke tengah - 1
        else {
            right125 = mid - 1;
        }
    }

    // Jika target tidak ditemukan, kembalikan -1
    return -1;
}

// Fungsi untuk mengurutkan string
void sortString(string &str) {
    sort(str.begin(), str.end());  // Mengurutkan string menggunakan fungsi sort dari library algorithm
}

int main() {
    string kalimat125;  // Deklarasi variabel untuk menyimpan kalimat
    char target125;  // Deklarasi variabel untuk menyimpan huruf yang dicari

    cout << "---> Naufal'S Program Mencari Huruf di dalam Kalimat <---\n";
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat125);  // Membaca kalimat dari input pengguna

    // Menghapus semua spasi dari kalimat
    kalimat125.erase(remove(kalimat125.begin(), kalimat125.end(), ' '), kalimat125.end());

    // Mengurutkan kalimat menggunakan fungsi sortString
    sortString(kalimat125);

    // Menampilkan kalimat yang sudah diurutkan
    cout << "Kalimat setelah diurutkan: " << kalimat125 << endl;

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target125;  // Membaca huruf yang ingin dicari dari input pengguna

    // Mencari huruf yang diinginkan menggunakan binary search
    int result125 = binarySearch(&kalimat125[0], kalimat125.size(), target125);

    // Jika huruf ditemukan, cetak posisinya
    if (result125 != -1) {
        cout << "Huruf " << target125 << " ditemukan pada indeks ke-" << result125 << " setelah diurutkan." << endl;
    } 
    // Jika huruf tidak ditemukan, cetak pesan tidak ditemukan
    else {
        cout << "Huruf " << target125 << " tidak ditemukan." << endl;
    }

    return 0;  
}
