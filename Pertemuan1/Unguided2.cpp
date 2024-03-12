#include <stdio.h>
#include <string.h>

struct Novel
{
    char Judul_125[50];// deklarasi
    char Penerbit_125[100];
    int Tahun_125;
};

int main()
{
    struct Novel Novel1, Novel2;
    strcpy(Novel1.Judul_125, "Cinta Pertama");// Untuk memasukkan Judul Novel
    strcpy(Novel1.Penerbit_125, "Naufal");// Untuk memasukkan Penerbit Novel
    Novel1.Tahun_125 = 2023;// Untuk memasukkan Tahun Novel
    strcpy(Novel1.Judul_125, "Dia Yang Engkau Pilih");
    strcpy(Novel2.Penerbit_125, "Naufal");
    Novel2.Tahun_125 = 2024;

    printf("Novel 1\n");
    printf("judul : %s \n", Novel1.Judul_125);// Untuk memanggil Judul Novel
    printf("Penerbit : %s \n", Novel1.Penerbit_125);// Untuk memanggil Penerbit Novel
    printf("Tahun : %d \n", Novel1.Tahun_125);// Untuk memanggil Tahun Novel
    printf("\n");
    printf("Novel 2\n");
    printf("Judul : %s \n", Novel2.Judul_125);
    printf("Penerbit : %s \n", Novel2.Penerbit_125);
    printf("Tahun : %d \n", Novel2.Tahun_125);

    return 0;
}