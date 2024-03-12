#include <iostream>
#include <iomanip>

using namespace std;

int x_125, y_125;
char pil_125;

int perkalian_125(int x_125, int y_125)// Fungsi untuk perkalian
{
     return x_125*y_125;
}

float pembagian_125(float x_125, float y_125)// Fungsi untuk pembagian
{
    return x_125/y_125;
}

int main()
{
    MenuUtama_125 :
    cout << "----------------\n"; 
    cout << "|     Menu     |\n";
    cout << "----------------\n";
    cout << "1. Perkalian\n";
    cout << "2. Pembagian\n";
    cout << "3. Keluar\n";
    cout << "Masukkan Pilihan Anda : ";
    cin >> pil_125;

    switch (pil_125)
    {
    case '1':// Jika memilih 1, maka Anda akan menghitung perkalian
        cout << "Perkalian\n";
        cout << "Masukkan Bil Pertama : ";
        cin >> x_125;
        cout << "Masukkan Bil Kedua : ";
        cin >> y_125;
        cout << "Hasil Perkalian : " << perkalian_125(x_125,y_125) << endl; // Untuk memanggil fungsi perkalian
        goto MenuUtama_125;// Fungsi goto untuk kembali ke Menu Utama
        break;

    case '2':// Jika memilih 2, maka Anda akan menghitung pembagian
        cout << "Pembagian\n";
        cout << "Masukkan Pembilang : ";
        cin >> x_125;
        cout << "Masukkan Penyebut : ";
        cin >> y_125;
        if (y_125 == 0)
        {
            cout << "Penyebut tidak boleh = 0";
        } else {
            cout << "Hasil Pembagian : " << fixed << setprecision(2) << pembagian_125(x_125,y_125) << endl;// Untuk memanggil fungsi pembagian
        }
        goto MenuUtama_125;// Fungsi goto untuk kembali ke Menu Utama
        break;

    case '3':// Jika memilih 3, maka Anda akan keluar dari program
        cout << "Anda telah keluar dari menu";
        return false;
        break;

    default:
        cout << "Silahkan Masukkan Pilihan Yang Benar\n";
        goto MenuUtama_125;// Fungsi goto untuk kembali ke Menu Utama
        break;
    }

    return 0;
}