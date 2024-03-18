#include <stdio.h>
#include <string.h>

struct Mahasiswa
{
    char name_125[50];
    char address_125[100];
    int age_125;
};
int main()
{
    struct Mahasiswa mhs1, mhs2;

    strcpy(mhs1.name_125, "Dian");
    strcpy(mhs1.address_125, "Mataram");
    mhs1.age_125 = 22;
    strcpy(mhs2.name_125, "Bambang");
    strcpy(mhs2.address_125, "Surabaya");
    mhs2.age_125 = 23;

    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name_125);
    printf("Alamat: %s\n", mhs1.address_125);
    printf("Umur: %d\n", mhs1.age_125);
    printf ("\n");
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name_125);
    printf("Alamat: %s\n", mhs2.address_125);
    printf("Umur: %d\n", mhs2.age_125);
    return 0;

}