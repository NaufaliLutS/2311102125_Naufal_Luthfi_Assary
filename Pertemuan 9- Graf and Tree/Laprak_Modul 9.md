# <h1 align="center">Laporan Praktikum Modul 9 - Graph Dan Tree</h1>
<p align="center">Naufal Luthfi Assary</p>
<p align="center">2311102125</p>

## Dasar Teori

Dalam teori graf, graf dan pohon adalah dua konsep dasar yang digunakan untuk merepresentasikan hubungan antara entitas. `Graf` adalah struktur data non-linear yang terdiri dari node atau vertex yang terhubung oleh sisi atau edge. Graf dapat memiliki arah atau tidak, tergantung pada apakah sisi memiliki arah atau tidak. Di sisi lain, pohon adalah jenis graf yang terhubung, tidak berarah, dan tidak memiliki sirkuit. Setiap node dalam pohon terhubung ke setiap node lainnya dengan jalan yang unik, dan tidak ada lebih dari satu jalan antara dua node. Graf pohon digunakan dalam berbagai aplikasi, seperti file system, dokumen XML, dan sebagainya, sedangkan hutan adalah kumpulan pohon yang tidak saling terhubung dalam sebuah graf asiklik tak berarah.

Graf, secara matematis, dapat dinyatakan sebagai G = (V, E), di mana G adalah graf, V adalah himpunan simpul atau vertex, dan E adalah himpunan sisi atau edge yang menghubungkan simpul-simpul tersebut.

`Beberapa jenis graf` yang umum dikenal termasuk graf sederhana (tidak memiliki sisi ganda atau gelang), graf tak-sederhana (bisa memiliki sisi ganda atau gelang), graf teratur (setiap simpul memiliki jumlah sisi yang sama), dan graf bipartisi (dapat dibagi menjadi dua kelompok simpul di mana tidak ada sisi yang menghubungkan simpul-simpul dalam kelompok yang sama). Graf juga dapat dibedakan berdasarkan arah tepinya, menjadi graf tak berarah (tidak memiliki arah pada sisinya) dan graf berarah (memiliki arah pada sisinya).

Selain itu, graf juga dapat dikategorikan berdasarkan adanya bobot pada sisinya. Graf berbobot memiliki nilai atau bobot pada setiap sisi yang menghubungkan simpul, sedangkan graf tidak berbobot tidak memiliki bobot pada sisinya.

`Pohon(tree)`, di sisi lain, adalah struktur data yang terdiri dari satu set node yang terhubung dan tertaut dalam grafik terurut. Setiap node dalam pohon memiliki paling banyak satu simpul induk dan dapat memiliki nol atau lebih simpul anak dengan urutan tertentu. Struktur data pohon digunakan untuk menyimpan data hirarkis, seperti struktur keluarga, skema pertandingan, dan struktur organisasi.

**Operasi pada Pohon**

`Create`: Membuat ruang kosong untuk menaruh elemen-elemen baru, seperti membuka pintu ke rumah kosong yang siap diisi.

`Clear`: Membersihkan seluruh isi pohon, mengembalikan ke kondisi kosong, seperti membereskan seluruh isi rumah.

`isEmpty`: Mengecek apakah pohon kosong, seperti mengecek apakah rumah tidak berisi perabotan.

`Insert`: Menambahkan node baru ke dalam pohon, memastikan ditempatkan sesuai aturan, seperti menambahkan perabot ke ruangan yang tepat.

`Find`: Mencari informasi tentang suatu node, seperti mencari barang atau ruangan dalam rumah.

`Update`: Mengubah nilai atau isi node yang ada dengan nilai baru, seperti mengganti sofa lama dengan yang baru.

`Retrieve`: Mengetahui detail informasi tentang node tertentu.

`Delete Sub`: Menghapus seluruh isi subtree yang ditunjuk, seperti membersihkan seluruh isi sebuah kamar.

`Characteristic`: Mengetahui ukuran, tinggi, atau panjang rata-rata pohon, seperti mengukur karakteristik rumah.

`Traverse`: Mengunjungi seluruh node dalam pohon dengan metode traversal tertentu, seperti menjelajahi seluruh ruang dalam rumah.

**Metode Traversal**:
- `Pre-Order`: Cetak root, lalu subpohon kiri, kemudian subpohon kanan.
- `In-Order`: Cetak subpohon kiri, lalu root, kemudian subpohon kanan.
- `Post-Order`: Cetak subpohon kiri, subpohon kanan, lalu root.

## Guided 

### 1. Program Graph.

```C++
// Laprak 9 - Guided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <iomanip>

using namespace std;

// Array simpul menyimpan nama-nama kota
string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

// Array busur menyimpan jarak antar kota
int busur[7][7] = {
    // Matriks busur yang merepresentasikan jarak antar kota,
    // nilai 0 menandakan tidak ada jalur langsung antara dua kota
    // nilai selain 0 menandakan jarak antara dua kota tersebut
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

// Fungsi untuk menampilkan graf, dengan mencetak nama kota dan jarak ke kota lainnya
void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        // Mencetak nama kota di setiap baris
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        // Memeriksa kolom dalam matriks busur untuk menemukan jarak antar kota
        for (int kolom = 0; kolom < 7; kolom++) {
            // Jika terdapat jalur antar kota (nilai bukan 0)
            if (busur[baris][kolom] != 0) {
                // Mencetak nama kota tujuan beserta jaraknya
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    // Memanggil fungsi tampilGraph untuk menampilkan graf
    tampilGraph();
    return 0;
} 

```

#### Deskripsi:

Kode di atas adalah implementasi sederhana dari struktur data graf menggunakan representasi matriks. Deskripsi codingan tersebut dapat dijabarkan sebagai berikut:

**Deklarasi Variabel**: 
   - `simpul[7]`: Array yang menyimpan nama-nama kota atau simpul dalam graf. Terdapat 7 elemen dalam array ini.
   - `busur[7][7]`: Array dua dimensi yang menyimpan jarak antara kota-kota dalam graf. Setiap elemen `[i][j]` dalam array ini menunjukkan jarak dari kota `i` ke kota `j`. Nilai 0 menandakan bahwa tidak ada jalur langsung antara dua kota tersebut.

**Fungsi `tampilGraph()`**: Fungsi ini digunakan untuk menampilkan graf. Dalam fungsi ini dilakukan perulangan untuk setiap baris matriks `busur`. Pada setiap baris, dilakukan perulangan lagi untuk setiap kolom matriks `busur`. Jika nilai dalam matriks `busur` tidak sama dengan 0, maka akan dicetak nama kota tujuan beserta jaraknya. Setiap nama kota dan jarak ditampilkan dengan format tertentu untuk memperbaiki tampilan.


### 2. Program Tree.

```C++
// Laprak 9 - Guided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>

using namespace std;

//Program Binary Tree

//Deklarasi Pohon
struct Pohon{
 char data;
 Pohon *left, *right, *parent;
};
Pohon *root, *baru;

//Inisialisasi
void init()
{
    root = NULL;
}

//Cek Node
int isEmpty()
{
    if (root == NULL)
        return 1; //true
    else
        return 0; //false
}

void buatNode(char data )
{
    if(isEmpty() == 1){
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
    }else{
        cout << "\n Pohon sudah dibuat" << endl;
    }
}

//Tambah Kiri
Pohon *insertLeft(char data, Pohon *node )
{
    if(isEmpty() == 1){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }else{
        // cek apakah child kiri ada atau tidak
        if( node->left != NULL ){
            // kalau ada
            cout << "\n Node "<< node->data << " sudah ada child kiri!" << endl;
            return NULL;
        }else{
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}
//Tambah Kanan
Pohon *insertRight(char data, Pohon *node )
{
    if( root == NULL ){
        cout <<  "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    }else{
        // cek apakah child kanan ada atau tidak
        if( node->right != NULL ){
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        }else{
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
    }
    }
}
// Ubah Data Tree
void update(char data, Pohon *node)
{
    if(isEmpty() == 1){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if( !node )
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        else{
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
// Lihat Isi Data Tree
void retrieve( Pohon *node )
{
    if( !root ){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if( !node )
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else{
            cout << "\n Data node : " << node->data << endl;
        }
    }
}
// Cari Data Tree
void find(Pohon *node)
{
    if( !root ){
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }else{
        if( !node )
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else{
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
        if( !node->parent )
            cout << " Parent : (tidak punya parent)" << endl;
        else
            cout << " Parent : " << node->parent->data << endl;
        if( node->parent != NULL && node->parent->left != node && node->parent->right == node )
            cout << " Sibling : " << node->parent->left->data << endl;
        else if( node->parent != NULL && node->parent->right != node&&node->parent->left == node )
            cout << " Sibling : " << node->parent->right->data << endl;
        else
            cout << " Sibling : (tidak punya sibling)" << endl;
        if( !node->left )
            cout << " Child Kiri : (tidak punya Child kiri)" << endl;
        else
            cout << " Child Kiri : " << node->left->data << endl;
        if( !node->right )
            cout << " Child Kanan : (tidak punya Child kanan)" << endl;
        else
            cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node = root)
{
    if(!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else{
        if( node != NULL ){
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node = root)
{
    if(!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else{
        if(node != NULL){
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node = root)
{
    if(!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else{
        if( node != NULL ){
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if(!root)
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else{
        if( node != NULL ){
            if( node != root ){
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if( node == root ){
                delete root;
                root = NULL;
            }else{
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node){
    if( !root )
        cout << "\n Buat tree terlebih dahulu!" << endl;
    else{
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}
// Hapus Tree
void clear(){
    if( !root )
        cout << "\n Buat tree terlebih dahulu!!" << endl;
    else{
        deleteTree(root);
        cout << "\n Pohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node = root){
    if( !root ){
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }else{
        if( !node ){
            return 0;
        }else{
            return 1 + size( node->left ) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height( Pohon *node = root )
{
    if( !root ){
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }else{
        if( !node ){
            return 0;
        }else{
            int heightKiri = height( node->left );
            int heightKanan = height( node->right );
            if( heightKiri >= heightKanan ){
                return heightKiri + 1;
            }else{
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void charateristic()
{
    cout << "\n Size Tree : " << size() << endl;
    cout << " Height Tree : " << height() << endl;
    cout << " Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    buatNode('A');

    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);

    update('Z', nodeC);
    update('C', nodeC);
    
    retrieve(nodeC);
    
    find(nodeC);
    
    cout << "\n PreOrder :" << endl;
    preOrder(root);
    
    cout << "\n" << endl;
    cout << " InOrder :" << endl;
    inOrder(root);
    
    cout << "\n" << endl;
    cout << " PostOrder :" << endl;
    postOrder(root);
    
    cout << "\n" << endl;
    charateristic();
    deleteSub(nodeE);
    
    cout << "\n PreOrder :" << endl;
    preOrder();
    
    cout << "\n" << endl;
    charateristic();
}

```

#### Deskripsi:

Kode tersebut adalah implementasi dari struktur data pohon biner menggunakan bahasa pemrograman C++. Dalam struktur data pohon biner, setiap simpul memiliki paling banyak dua anak, yaitu anak kiri dan anak kanan. Setiap simpul juga dapat memiliki sebuah simpul induk, kecuali simpul root yang tidak memiliki induk.
   
1. **Deklarasi Struktur Data:**
   - Struktur data `Pohon` dideklarasikan untuk merepresentasikan simpul-simpul dalam pohon biner.
   - Setiap simpul (`node`) memiliki data bertipe `char`, pointer ke simpul anak kiri (`left`) dan kanan (`right`), serta pointer ke simpul induk (`parent`).
   - `root` dan `baru` dideklarasikan sebagai pointer ke simpul untuk menunjukkan akar dan simpul yang baru dibuat.

2. **Fungsi-fungsi Utama:**
   - `init()`: Inisialisasi `root` menjadi `NULL`.
   - `isEmpty()`: Mengecek apakah pohon kosong atau tidak.
   - `buatNode()`: Membuat simpul baru sebagai root jika pohon masih kosong, jika tidak, mencetak pesan bahwa pohon sudah dibuat.
   - `insertLeft()`: Menambahkan simpul anak kiri dari simpul yang ditunjuk.
   - `insertRight()`: Menambahkan simpul anak kanan dari simpul yang ditunjuk.
   - `update()`: Mengubah data dari simpul yang ditunjuk.
   - `retrieve()`: Menampilkan data dari simpul yang ditunjuk.
   - `find()`: Menampilkan informasi tentang simpul yang ditunjuk, termasuk data, parent, sibling, serta anak kiri dan kanan.
   - `preOrder()`, `inOrder()`, `postOrder()`: Menjalankan pre-order, in-order, dan post-order traversal pada pohon, defaultnya dimulai dari `root`.
   - `deleteTree()`: Menghapus seluruh pohon.
   - `deleteSub()`: Menghapus subtree yang diawali dari simpul yang ditunjuk.
   - `clear()`: Menghapus seluruh pohon.
   - `size()`: Menghitung jumlah simpul dalam pohon.
   - `height()`: Menghitung tinggi atau level pohon.
   - `charateristic()`: Menampilkan karakteristik pohon, termasuk ukuran, tinggi, dan rata-rata node per level.

3. **Fungsi `main()`:**
   - Di dalam `main()`, pertama-tama sebuah simpul root 'A' dibuat.
   - Kemudian, simpul-simpul lain ditambahkan sebagai anak kiri atau kanan dari simpul-simpul yang sudah ada.
   - Beberapa operasi dilakukan, seperti update data simpul, menampilkan informasi simpul, dan melakukan traversal pada pohon.
   - Setelah itu, dilakukan penghapusan subtree dan menampilkan karakteristik pohon lagi.



## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
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

```
#### Output:
![Output](<Naufal_Output1 Unguided1.png>)

#### Deskripsi :
Kode tersebut merupakan implementasi dari struktur data graf menggunakan vektor dan matriks 2D untuk menyimpan informasi mengenai kota dan jarak antar kota. Berikut adalah deskripsi singkat dari setiap bagian kode:

1. **Deklarasi Variabel**:
   - `simpul`: Vektor yang menyimpan nama-nama kota (simpul).
   - `busur`: Matriks 2D yang menyimpan jarak antar kota (busur).

2. **Fungsi `tampilGraph()`**:
   - Fungsi ini digunakan untuk menampilkan graf, yaitu nama-nama kota dan jarak antar kota.
   - Pertama, mencetak bagian atas graf dengan menyertakan nama-nama kota.
   - Kemudian, mencetak baris-baris yang berisi nama kota di awal baris dan jarak antar kota.
   
3. **Fungsi `main()`**:
   - Variabel `sim_2311102125` dan `bus125` digunakan untuk menyimpan jumlah simpul (kota) dan jumlah jalan antar kota yang dimasukkan oleh pengguna.
   - Meminta pengguna untuk memasukkan jumlah simpul.
   - Mengubah ukuran vektor `simpul` dan matriks `busur` sesuai dengan jumlah kota.
   - Meminta pengguna untuk memasukkan nama-nama kota dan menyimpannya dalam vektor `simpul`.
   - Meminta pengguna untuk memasukkan jumlah jalan antar kota.
   - Meminta pengguna untuk memasukkan jalan antar kota beserta jaraknya, kemudian memasukkan informasi jarak ke dalam matriks `busur`.
   - Memanggil fungsi `tampilGraph()` untuk menampilkan graf yang sudah dibuat.

Dengan menggunakan kode ini, pengguna dapat memasukkan informasi mengenai kota dan jarak antar kota, dan kemudian melihat graf yang sudah dibuat berdasarkan informasi yang dimasukkan.


### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
// Laprak 9 - Unguided 2
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>
#include <queue>

using namespace std;

// Program Binary Tree

// Deklarasi Pohon
struct Pohon {
    char data125;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
int isEmpty() {
    return root == NULL ? 1 : 0; // 1 untuk true, 0 untuk false
}

void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data125 = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

// Tambah Kiri
Pohon* insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data125 << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data125 = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data125 << endl;
            return baru;
        }
    }
}

// Tambah Kanan
Pohon* insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data125 << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            baru = new Pohon();
            baru->data125 = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data125 << endl;
            return baru;
        }
    }
}

// Ubah Data Tree
void update(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!" << endl;
        } else {
            char temp = node->data125;
            node->data125 = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
// lihat isi child
void retrieveWithChildren(Pohon *node) {
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data125 << endl;
    if (node->left) {
        cout << "Child Kiri: " << node->left->data125 << endl;
    } else {
        cout << "Child Kiri: (tidak punya Child kiri)" << endl;
    }
    if (node->right) {
        cout << "Child Kanan: " << node->right->data125 << endl;
    } else {
        cout << "Child Kanan: (tidak punya Child kanan)" << endl;
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        retrieveWithChildren(node);
    }
}

// Cari Data Tree
void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node: " << node->data125 << endl;
            cout << "Root: " << root->data125 << endl;
            if (!node->parent) {
                cout << "Parent: (tidak punya parent)" << endl;
            } else {
                cout << "Parent: " << node->parent->data125 << endl;
            }
            if (node->parent && node->parent->left != node && node->parent->right == node) {
                cout << "Sibling: " << node->parent->left->data125 << endl;
            } else if (node->parent && node->parent->right != node && node->parent->left == node) {
                cout << "Sibling: " << node->parent->right->data125 << endl;
            } else {
                cout << "Sibling: (tidak punya sibling)" << endl;
            }
            if (!node->left) {
                cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            } else {
                cout << "Child Kiri: " << node->left->data125 << endl;
            }
            if (!node->right) {
                cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            } else {
                cout << "Child Kanan: " << node->right->data125 << endl;
            }
        }
    }
}

// Menampilkan Descendant dari Node
void printDescendants(Pohon *node) {
    if (!node) {
        cout << "(tidak ada descendant)" << endl;
        return;
    }
    queue<Pohon*> q;
    q.push(node);
    while (!q.empty()) {
        Pohon *current = q.front();
        q.pop();
        if (current->left) {
            cout << " " << current->left->data125;
            q.push(current->left);
        }
        if (current->right) {
            cout << " " << current->right->data125;
            q.push(current->right);
        }
    }
}

// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data125 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// inOrder
void inOrder(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data125 << ", ";
            inOrder(node->right);
        }
    }
}

// postOrder
void postOrder(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data125 << ", ";
        }
    }
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Hapus Tree
void clear() {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Hapus Node Tree (SubTree)
void deleteSTree(Pohon *node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

// Hapus SubTree
void deleteSub(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node == root) {
            clear();
            return;
        }
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = NULL;
            } else if (node->parent->right == node) {
                node->parent->right = NULL;
            }
        }
        deleteSTree(node);
        cout << "\nNode subtree berhasil dihapus." << endl;
    }
}

// Cek Size Tree
int size(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Cek Height Level Tree
int height(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int left_height = height(node->left);
            int right_height = height(node->right);
            return max(left_height, right_height) + 1;
        }
    }
}

// Karakteristik Tree
void charateristic() {
    cout << "\nSize Tree: " << size(root) << endl;
    cout << "Height Tree: " << height(root) << endl;
    cout << "Average Node of Tree: " << size(root) / height(root) << endl;
}

int main() {
    int pil_2311102125;
    char data125, parentData;
    Pohon *parentNode = NULL;
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Buat Node\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Lihat Data Node\n";
        cout << "6. Cari Node\n";
        cout << "7. PreOrder Traversal\n";
        cout << "8. InOrder Traversal\n";
        cout << "9. PostOrder Traversal\n";
        cout << "10. Hapus SubTree\n";
        cout << "11. Hapus Tree\n";
        cout << "12. Tampilkan Karakteristik Tree\n";
        cout << "13. Tampilkan Descendant dari Node\n";
        cout << "14. Keluar\n";
        cout << "Pilihan: ";
        cin >> pil_2311102125;
        switch (pil_2311102125) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data125;
                buatNode(data125);
                break;
            case 2:
                cout << "Masukkan data node kiri: ";
                cin >> data125;
                cout << "Masukkan data parent: ";
                cin >> parentData;
                parentNode = root;
                while (parentNode && parentNode->data125 != parentData) {
                    if (parentNode->left && parentNode->left->data125 == parentData) {
                        parentNode = parentNode->left;
                    } else if (parentNode->right && parentNode->right->data125 == parentData) {
                        parentNode = parentNode->right;
                    } else {
                        parentNode = (parentNode->left) ? parentNode->left : parentNode->right;
                    }
                }
                insertLeft(data125, parentNode);
                break;
            case 3:
                cout << "Masukkan data node kanan: ";
                cin >> data125;
                cout << "Masukkan data parent: ";
                cin >> parentData;
                parentNode = root;
                while (parentNode && parentNode->data125 != parentData) {
                    if (parentNode->left && parentNode->left->data125 == parentData) {
                        parentNode = parentNode->left;
                    } else if (parentNode->right && parentNode->right->data125 == parentData) {
                        parentNode = parentNode->right;
                    } else {
                        parentNode = (parentNode->left) ? parentNode->left : parentNode->right;
                    }
                }
                insertRight(data125, parentNode);
                break;
            case 4:
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> data125;
                cout << "Masukkan data baru: ";
                char newData;
                cin >> newData;
                parentNode = root;
                while (parentNode && parentNode->data125 != data125) {
                    if (parentNode->left && parentNode->left->data125 == data125) {
                        parentNode = parentNode->left;
                    } else if (parentNode->right && parentNode->right->data125 == data125) {
                        parentNode = parentNode->right;
                    } else {
                        parentNode = (parentNode->left) ? parentNode->left : parentNode->right;
                    }
                }
                update(newData, parentNode);
                break;
            case 5:
                cout << "Masukkan data node yang ingin dilihat: ";
                cin >> data125;
                parentNode = root;
                while (parentNode && parentNode->data125 != data125) {
                    if (parentNode->left && parentNode->left->data125 == data125) {
                        parentNode = parentNode->left;
                    } else if (parentNode->right && parentNode->right->data125 == data125) {
                        parentNode = parentNode->right;
                    } else {
                        parentNode = (parentNode->left) ? parentNode->left : parentNode->right;
                    }
                }
                retrieve(parentNode);
                break;
            case 6:
                cout << "Masukkan data node yang ingin dicari: ";
                cin >> data125;
                parentNode = root;
                while (parentNode && parentNode->data125 != data125) {
                    if (parentNode->left && parentNode->left->data125 == data125) {
                        parentNode = parentNode->left;
                    } else if (parentNode->right && parentNode->right->data125 == data125) {
                        parentNode = parentNode->right;
                    } else {
                        parentNode = (parentNode->left) ? parentNode->left : parentNode->right;
                    }
                }
                find(parentNode);
                break;
            case 7:
                cout << "PreOrder Traversal:\n";
                preOrder(root);
                cout << endl;
                break;
            case 8:
                cout << "InOrder Traversal:\n";
                inOrder(root);
                cout << endl;
                break;
            case 9:
                cout << "PostOrder Traversal:\n";
                postOrder(root);
                cout << endl;
                break;
            case 10:
                cout << "Masukkan data node subtree yang ingin dihapus: ";
                cin >> data125;
                parentNode = root;
                while (parentNode && parentNode->data125 != data125) {
                    if (parentNode->left && parentNode->left->data125 == data125) {
                        parentNode = parentNode->left;
                    } else if (parentNode->right && parentNode->right->data125 == data125) {
                        parentNode = parentNode->right;
                    } else {
                        parentNode = (parentNode->left) ? parentNode->left : parentNode->right;
                    }
                }
                deleteSub(parentNode);
                break;
            case 11:
                clear();
                break;
            case 12:
                charateristic();
                break;
            case 13:
                cout << "Masukkan data node yang ingin ditampilkan descendant-nya: ";
                cin >> data125;
                parentNode = root;
                while (parentNode && parentNode->data125 != data125) {
                    if (parentNode->left && parentNode->left->data125 == data125) {
                        parentNode = parentNode->left;
                    } else if (parentNode->right && parentNode->right->data125 == data125) {
                        parentNode = parentNode->right;
                    } else {
                        parentNode = (parentNode->left) ? parentNode->left : parentNode->right;
                    }
                }
                cout << "Descendant dari node " << data125 << ":";
                printDescendants(parentNode);
                cout << endl;
                break;
            case 14:
                cout << "Keluar dari program..." << endl;
                return false;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }
    return 0;
}

```
#### Output:
![Output](<Naufal_Output1 Unguided2.png>) ![Output](<Naufal_Output2 Unguided2.png>) ![Output](<Naufal_Output3 Unguided2.png>) ![Output](<Naufal_Output4 Unguided2.png>) ![Output](<Naufal_Output5 Unguided2.png>) ![Output](<Naufal_Output6 Unguided2.png>) ![Output](<Naufal_Output7 Unguided2.png>) ![Output](<Naufal_Output8 Unguided2.png>)

#### Deskripsi:

Kode tersebut adalah implementasi dari struktur data Binary Tree menggunakan bahasa C++. Binary Tree adalah struktur data hierarkis di mana setiap node memiliki dua anak, yang disebut anak kiri dan anak kanan.

Berikut adalah deskripsi singkat dari setiap bagian kode:

1. **Deklarasi Struktur dan Variabel**: 
   - `Pohon`: Struktur yang merepresentasikan node dalam pohon. Setiap node memiliki data (bertipe char), pointer ke node anak kiri (`left`) dan anak kanan (`right`), serta pointer ke node induk (`parent`). 
   - `root`: Pointer ke node root dari pohon.
   - `baru`: Pointer yang digunakan untuk menunjuk node baru yang akan ditambahkan.

2. **Inisialisasi Tree**:
   - Fungsi `init()` digunakan untuk menginisialisasi `root` menjadi NULL.

3. **Penambahan Node**:
   - Fungsi `buatNode()` digunakan untuk membuat node baru dan menetapkannya sebagai root jika pohon masih kosong.
   - Fungsi `insertLeft()` dan `insertRight()` digunakan untuk menambahkan node sebagai anak kiri atau anak kanan dari suatu node tertentu.

4. **Pembaruan Node**:
   - Fungsi `update()` digunakan untuk mengubah data pada suatu node yang sudah ada.

5. **Pengambilan Informasi Node**:
   - Fungsi `retrieve()` digunakan untuk menampilkan informasi tentang suatu node, termasuk data node itu sendiri, parent, sibling, serta anak kiri dan kanan.
   - Fungsi `find()` digunakan untuk mencari suatu node berdasarkan datanya.

6. **Traversal**:
   - Traversal dilakukan menggunakan tiga metode: preOrder, inOrder, dan postOrder. Setiap metode mengunjungi node dalam urutan tertentu (secara preOrder, inOrder, atau postOrder) dan mencetak nilai data dari setiap node.

7. **Hapus Node atau SubTree**:
   - Fungsi `deleteSTree()` dan `deleteSub()` digunakan untuk menghapus node atau subtree.

8. **Cek Karakteristik Pohon**:
   - Fungsi `size()` digunakan untuk menghitung jumlah node dalam pohon.
   - Fungsi `height()` digunakan untuk menghitung tinggi pohon.
   - Fungsi `charateristic()` digunakan untuk menampilkan ukuran, tinggi, dan rata-rata node dalam pohon.

9. **Main Function**:
   - Dalam loop utama, pengguna diberikan berbagai opsi menu untuk berinteraksi dengan pohon, seperti menambah node, menghapus node, traversal, dan lainnya.

Kode ini memungkinkan pengguna untuk membuat, mengelola, dan menganalisis pohon biner melalui berbagai operasi yang didefinisikan.


## Kesimpulan

Graf dan pohon adalah konsep fundamental dalam teori graf yang digunakan untuk merepresentasikan hubungan antara entitas. 

- `Graf` adalah struktur non-linear yang terdiri dari node (vertex) yang terhubung oleh sisi (edge), yang bisa memiliki arah (graf berarah) atau tidak (graf tak berarah). Graf dapat dibedakan berdasarkan strukturnya (sederhana, tak-sederhana, teratur, bipartisi) dan adanya bobot pada sisinya (graf berbobot dan tidak berbobot). Secara matematis, graf dinyatakan sebagai G = (V, E), di mana V adalah himpunan simpul dan E adalah himpunan sisi.

- `Pohon` adalah jenis graf yang terhubung, tidak berarah, dan tidak memiliki sirkuit. Setiap node dalam pohon terhubung ke setiap node lainnya dengan jalan yang unik, tanpa adanya lebih dari satu jalan antara dua node. Pohon digunakan untuk menyimpan data hierarkis seperti struktur keluarga, file system, dan struktur organisasi. Pohon adalah graf terhubung yang tidak memiliki sirkuit, sementara hutan adalah kumpulan pohon yang tidak saling terhubung dalam sebuah graf asiklik tak berarah.

Operasi-operasi pada pohon mencakup pembuatan (create), pembersihan (clear), pengecekan kekosongan (isEmpty), penambahan node (insert), pencarian informasi (find), pembaruan nilai node (update), pengambilan detail node (retrieve), penghapusan subtree (delete sub), penentuan karakteristik pohon (characteristic), dan traversal untuk mengunjungi seluruh node (traverse).

`Metode traversal` pada pohon termasuk pre-order (root, subpohon kiri, subpohon kanan), in-order (subpohon kiri, root, subpohon kanan), dan post-order (subpohon kiri, subpohon kanan, root). Traversal ini memungkinkan eksplorasi dan manipulasi data dalam struktur pohon secara efektif.

Secara keseluruhan, memahami graf dan pohon serta operasinya sangat penting dalam banyak aplikasi, mulai dari pengelolaan file sistem hingga pemodelan struktur organisasi dan analisis hubungan data.

## Referensi
[1] Muhammad Nugraha, Dasar Pemrograman Dengan C++, Materi Paling Dasar untuk Menjadi Programmer Berbagai Platform, Yogyakarta, 2021.

[2] Joseph Teguh Santoso, Struktur Data dan ALgoritma, Semarang: Yayasan Prima Agus Teknik, 2021.

[3] Laisouw, R., & Burhanudin, H. Analisis Representasi Graf Berarah dalam Matriks. JURNAL BIOSAINSTEK, 2(01), 70-74, 2020.

[4] Sedgewick, R., Algorithms in C++ Part 5: Graph Algorithms 3rd Edition. Boston: Addison-Wesley Professional, 2020.

[5] Asisten Praktikum. Modul 9 Graph Dan Tree. Purwokerto: Institut Teknologi Purwokerto. 2024.