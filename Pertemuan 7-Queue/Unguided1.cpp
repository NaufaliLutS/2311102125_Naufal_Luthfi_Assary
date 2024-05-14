// Laprak 7 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include <iostream>

using namespace std;

// Struktur untuk node dalam antrian
struct Node {
    string data_125;  // Data yang disimpan dalam node
    Node* next;       // Untuk ke node berikutnya

    // Konstruktor untuk inisialisasi node dengan data dan next sebagai nullptr
    Node(string val) : data_125(val), next(nullptr) {}
};

// Struktur untuk antrian
struct Queue {
    Node* front;  // Untuk ke depan antrian
    Node* back;   // Untuk ke belakang antrian
    int size;     // Ukuran antrian

    // Konstruktor untuk inisialisasi antrian kosong
    Queue() : front(nullptr), back(nullptr), size(0) {}
};

// Fungsi untuk memeriksa apakah antrian kosong
bool isEmpty(Queue* queue) {
    return queue->size == 0;  // Antrian kosong jika ukuran antrian adalah 0
}

// Fungsi untuk menambahkan elemen ke antrian
void enqueueAntrian(Queue* queue, string data) {
    Node* newNode = new Node(data);  // Buat node baru dengan data

    // Jika antrian kosong, depan dan belakang menunjuk ke node baru
    if (isEmpty(queue)) {
        queue->front = queue->back = newNode;
    } else {
        // Jika tidak kosong, tambahkan node baru di belakang antrian
        queue->back->next = newNode;
        queue->back = newNode;
    }

    queue->size++;  // Tingkatkan ukuran antrian
}

// Fungsi untuk menghapus elemen dari antrian
void dequeueAntrian(Queue* queue) {
    // Jika antrian kosong, cetak pesan dan keluar dari fungsi
    if (isEmpty(queue)) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    // Hapus node dari depan antrian
    Node* temp = queue->front;  // Simpan node depan ke variabel sementara
    queue->front = queue->front->next;  // Pindahkan depan ke node berikutnya
    delete temp;  // Hapus node depan yang lama

    queue->size--;  // Kurangi ukuran antrian
}

// Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue(Queue* queue) {
    return queue->size;  // Kembalikan ukuran antrian
}

// Fungsi untuk menghapus semua elemen dalam antrian
void clearQueue(Queue* queue) {
    // Hapus elemen satu per satu hingga antrian kosong
    while (!isEmpty(queue)) {
        dequeueAntrian(queue);
    }
}

// Fungsi untuk menampilkan semua elemen dalam antrian
void viewQueue(Queue* queue) {
    // Jika antrian kosong, cetak pesan dan keluar dari fungsi
    if (isEmpty(queue)) {
        cout << "Antrian Kosong" << endl;
        return;
    }

    // Cetak data semua elemen dalam antrian
    cout << "Data antrian Teller : " << endl;
    Node* current = queue->front;  // Mulai dari depan antrian
    int index = 1;  // Indeks untuk penomoran elemen

    // Iterasi melalui semua node dalam antrian
    while (current != nullptr) {
        cout << index << ". " << current->data_125 << endl;  // Cetak data dan indeks
        current = current->next;  // Pindah ke node berikutnya
        index++;  // Tambah indeks
    }
}

int main() {
    Queue* antrian_125 = new Queue();  // Buat antrian baru

    cout << "---> Naufal'S Teller Queue <---\n";  // Cetak judul antrian
    enqueueAntrian(antrian_125, "Alya");  // Tambahkan 'Alya' ke antrian
    enqueueAntrian(antrian_125, "Kiki");  // Tambahkan 'Kiki' ke antrian
    enqueueAntrian(antrian_125, "Artika");  // Tambahkan 'Artika' ke antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian
    cout << endl;

    dequeueAntrian(antrian_125);  // Hapus elemen depan antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << endl;

    enqueueAntrian(antrian_125, "Naufal");  // Tambahkan 'Naufal' ke antrian
    enqueueAntrian(antrian_125, "Luthfi");  // Tambahkan 'Luthfi' ke antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian
    cout << endl;

    clearQueue(antrian_125);  // Hapus semua elemen dalam antrian
    viewQueue(antrian_125);  // Tampilkan antrian
    cout << "Jumlah Antrian = " << countQueue(antrian_125) << endl;  // Cetak jumlah antrian

    return 0;  
}
