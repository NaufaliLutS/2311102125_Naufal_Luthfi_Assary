//Naufal Luthfi Assary - 2311102125 - If-11-D

#include <iostream>

using namespace std;

int main() {
    const int SizeArray_125 = 10; // Mendefinisikan konstanta ukuran array
    int numbers[SizeArray_125]; // Deklarasi array untuk menyimpan angka-angka
    int evenNumbers[SizeArray_125]; // Deklarasi array untuk menyimpan angka genap
    int oddNumbers[SizeArray_125]; // Deklarasi array untuk menyimpan angka ganjil
    int evenCount = 0; // Inisialisasi hitungan untuk angka genap
    int oddCount = 0; // Inisialisasi hitungan untuk angka ganjil

    // Meminta pengguna untuk memasukkan angka-angka
    cout << "Naufal- Program Ganjil dan Genap\n";
    cout << "Masukkan Angkat dengan limit 10 Angka\n";
    cout << "Pisahkan Angka dengan koma dan akhiri dengan titik\n";
    cout << "Masukkan Angka: ";
    for (int i = 0; i < SizeArray_125; ++i) {
        cin >> numbers[i];
        char comma;
        cin >> comma;
        if (comma == '\n') // Memeriksa jika input berakhir
            break;
    }

    // Memisahkan angka genap dan ganjil
    for (int i = 0; i < SizeArray_125; ++i) {
        if (numbers[i] % 2 == 0)
            evenNumbers[evenCount++] = numbers[i]; // Menyimpan angka genap dan menginkremen hitungan
        else
            oddNumbers[oddCount++] = numbers[i]; // Menyimpan angka ganjil dan menginkremen hitungan
    }

    // Menampilkan data array yang dimasukkan oleh pengguna
    cout << "Data Array: ";
    for (int i = 0; i < SizeArray_125; ++i) {
        cout << numbers[i];
        if (i != SizeArray_125 - 1)
            cout << ",";
    }
    cout << endl;

    // Menampilkan angka genap
    cout << "Nomor Genap: ";
    for (int i = 0; i < evenCount; ++i) {
        cout << evenNumbers[i];
        if (i != evenCount - 1)
            cout << ",";
    }
    cout << endl;

    // Menampilkan angka ganjil
    cout << "Nomor Ganjil: ";
    for (int i = 0; i < oddCount; ++i) {
        cout << oddNumbers[i];
        if (i != oddCount - 1)
            cout << ",";
    }
    cout << endl;

    return 0;
}
