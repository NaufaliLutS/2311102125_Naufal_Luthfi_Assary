// Laprak 2 - Unguided 3
// Naufal Luthfi Assary - 2311102125
// IF-11-D
#include <iostream> 

using namespace std; 

int main() {
    int Jml_Arr_125; // Deklarasi variabel untuk menyimpan jumlah elemen dalam array.
    cout << "------------------------------------\n";
    cout << "|-----> Naufal-Program Array <-----|\n"; 
    cout << "------------------------------------\n";
    cout << "Masukkan jumlah elemen dalam array: ";
    cin >> Jml_Arr_125; // Meminta pengguna untuk memasukkan jumlah elemen dalam array.

    int *Daftar_Arr_125 = new int[Jml_Arr_125]; // Mengalokasikan memori dinamis untuk array dengan ukuran yang dimasukkan oleh pengguna.
    int i, NilaiMin_125, NilaiMax_125; // Deklarasi variabel untuk perulangan dan menyimpan nilai minimum dan maksimum.
    float Rata_125; // Deklarasi variabel untuk menyimpan nilai rata-rata.

    // Meminta pengguna untuk memasukkan elemen-elemen array.
    cout << "|----------> Input Array <---------|" << endl;
    cout << "Masukkan " << Jml_Arr_125 << " Elemen Array " << endl;
    for (int i = 0; i < Jml_Arr_125; i++) {
        cout << "Masukkan indeks ke - " << i + 1 << ": ";
        cin >> Daftar_Arr_125[i];
    }

    while (true) { // Looping menu utama program.
        cout << "------------------------------" << endl;
        cout << "|            Menu            |" << endl; // Menampilkan menu pilihan.
        cout << "------------------------------" << endl;
        cout << "1. Tampil Array" << endl;
        cout << "2. Cari Nilai Maksimum" << endl;
        cout << "3. Cari Nilai Minimum" << endl;
        cout << "4. Hitung Rata-rata" << endl;
        cout << "5. Keluar" << endl;
        int pil_125;
        cout << "Masukkan Pilihan : ";
        cin >> pil_125; // Meminta pengguna memilih opsi.

        switch (pil_125) { // Memilih opsi berdasarkan pilihan pengguna.
            case 1:
                cout << "Tampil Array" << endl;
                cout << "Array yang Sudah Anda Simpan adalah : " << endl;
                for (i = 0; i < Jml_Arr_125; i++) {
                    cout << Daftar_Arr_125[i] << endl; // Menampilkan elemen-elemen array.
                }
                break;
            case 2:
                cout << "Nilai Maksimum" << endl;
                NilaiMax_125 = 0;
                for (i = 0; i < Jml_Arr_125; i++) {
                    if (Daftar_Arr_125[i] > NilaiMax_125) {
                        NilaiMax_125 = Daftar_Arr_125[i]; // Mencari nilai maksimum dalam array.
                    }
                }
                cout << "Nilai Maksimumnya adalah " << NilaiMax_125 << endl; // Menampilkan nilai maksimum.
                break;
            case 3:
                cout << "Nilai Minimum" << endl;
                NilaiMin_125 = Daftar_Arr_125[0];
                for (i = 0; i < Jml_Arr_125; i++) {
                    if (Daftar_Arr_125[i] < NilaiMin_125) {
                        NilaiMin_125 = Daftar_Arr_125[i]; // Mencari nilai minimum dalam array.
                    }
                }
                cout << "Nilai Minimumnya adalah = " << NilaiMin_125 << endl; // Menampilkan nilai minimum.
                break;
            case 4:
                cout << "Nilai Rata-Rata" << endl;
                Rata_125 = 0;
                for (i = 0; i < Jml_Arr_125; i++) {
                    Rata_125 += Daftar_Arr_125[i]; // Menghitung total nilai dalam array.
                }
                cout << "Nilai Rata-Ratanya adalah = " << Rata_125 / Jml_Arr_125 << endl; // Menampilkan nilai rata-rata.
                break;
            case 5:
                cout << "Anda telah Keluar dari Program, Terimakasih:3" << endl;
                return false; // Mengakhiri program.
            default:
                cout << "Pilihan tidak valid" << endl; // Menampilkan pesan jika pilihan tidak valid.
                break;
        }
    }

    return 0;
}
