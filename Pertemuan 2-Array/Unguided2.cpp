#include <iostream>

using namespace std;

int main() {
    int xSize, ySize, zSize;

    cout << "Masukkan ukuran array tiga dimensi (x y z): ";
    cin >> xSize >> ySize >> zSize;

    int array3D[xSize][ySize][zSize];

    cout << "Masukkan elemen-elemen array:" << endl;
    for (int x = 0; x < xSize; ++x) {
        for (int y = 0; y < ySize; ++y) {
            for (int z = 0; z < zSize; ++z) {
                cout << "array[" << x << "][" << y << "][" << z << "]: ";
                cin >> array3D[x][y][z];
            }
        }
    }

    cout << "Array yang dimasukkan:" << endl;
    for (int x = 0; x < xSize; ++x) {
        for (int y = 0; y < ySize; ++y) {
            for (int z = 0; z < zSize; ++z) {
                cout << array3D[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
