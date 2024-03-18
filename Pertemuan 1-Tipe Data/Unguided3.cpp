#include <iostream>
#include <map>

using namespace std;

int main()
{   
    map <string, int> Merk_125;// membuat map dengan tipe data string dan int
    Merk_125["Asus"] = 25;
    Merk_125["Lenovo"] = 24;
    Merk_125["Acer"] = 23;
    Merk_125["HP"] = 22;
    Merk_125["MSI"] = 21;
    Merk_125["MacBook"] = 20;

    cout << "--Stok Laptop di Toko iLutS Store--\n";
   int i = 1;
    for (const auto & pair : Merk_125) { // Memanggil isi map menggunakan perulangan
        cout << i << ". " << pair.first << ": " << pair.second << endl;
        i++;
    }
    return 0;
}