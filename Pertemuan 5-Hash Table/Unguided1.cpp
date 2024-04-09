// Laprak 5 - Unguided 1
// Naufal Luthfi Assary - 2311102125
// IF-11-D

#include<iostream>
#include<vector> 
#include<iomanip>

using namespace std;

// Deklarasi untuk ukuran tabel hash
const int TableSize_125 = 100;

// Deklarasi Kelas untuk node dalam tabel hash
class HashNode_125{
    public:
    string nama_125; // Nama mahasiswa
    string NIM_125; // NIM mahasiswa
    int nilai_125; // Nilai mahasiswa

    // Konstruktor untuk inisialisasi node
    HashNode_125(string name_125, string NIM_125, int grade_125){
        this->nama_125 = name_125;
        this->NIM_125 = NIM_125;
        this->nilai_125 = grade_125;
    }
};

// Kelas untuk tabel hash
class HashMap_125{
    private: 
    vector<HashNode_125*> table[TableSize_125]; // Array dari vektor node untuk tabel hash

    public:
    // Fungsi hash sederhana
    int hashFunc_125(string key_125){
        int hashValue_125 = 0;
        for(char c : key_125){
            hashValue_125 += c;
        }
        return hashValue_125 % TableSize_125;
    }

    // Fungsi untuk menambahkan data ke dalam tabel hash
    void Tambah_125(string name_125, string NIM_125, int grade_125){
        int hashValue_125 = hashFunc_125(name_125); 

        // Memeriksa apakah data dengan nama yang sama sudah ada dalam tabel hash
        for(auto node : table[hashValue_125]){
            if(node->nama_125 == name_125){ 
                // Jika sudah ada, update NIM dan nilai
                node->NIM_125 = NIM_125; 
                node->nilai_125 = grade_125; 
                return;
            }
        }
        // Jika tidak ada, tambahkan data baru ke dalam vektor di indeks hash yang sesuai
        table[hashValue_125].push_back(new HashNode_125(name_125, NIM_125, grade_125));
    }

    // Fungsi untuk memeriksa keberadaan data dalam tabel hash berdasarkan nama
    bool CekData_125(string name_125){
        int hashValue_125 = hashFunc_125(name_125);

        // Iterasi melalui vektor pada indeks hash yang sesuai
        for(auto node = table[hashValue_125].begin(); node != table[hashValue_125].end(); node++){
            if((*node)->nama_125 == name_125){
                return true; 
            } 
        }
        return false;
    }
 
    // Fungsi untuk memeriksa apakah tabel hash kosong
    bool IsEmpty_125() {
        for (int i = 0; i < TableSize_125; i++) {
            if (!table[i].empty()) {
                return false;
            }
        }
        return true;
    }

    // Fungsi untuk menghapus data dari tabel hash berdasarkan nama
    void Hapus_125(string name_125){
        int hashValue_125 = hashFunc_125(name_125); 

        // Iterasi melalui vektor pada indeks hash yang sesuai
        for(auto node = table[hashValue_125].begin(); node != table[hashValue_125].end(); node++){
            if((*node)->nama_125 == name_125){ 
                table[hashValue_125].erase(node); 
                return;
            } else { 
                cout << "Data mahasiswa " << name_125 << " Tidak Ada" << endl;
            }
        }
    }

    // Fungsi untuk mencari data dalam tabel hash berdasarkan NIM
    void SearchByNIM_125(string NIM_125){
        bool ketemu = false; 
        cout << "Data Mahasiswa --->" << endl;
        cout << "=============================================\n";
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "=============================================\n";
        for(int i=0; i < TableSize_125; i++){
            // Iterasi melalui vektor pada indeks hash yang sesuai
            for(auto node : table[i]){
                if(node->NIM_125 == NIM_125){ 
                    cout << "|" << left << setw(14) << node->nama_125 << "|" << left << setw(14) << node->NIM_125 << "|" << left << setw(13) << node->nilai_125 << "|" << endl;
                    ketemu = true; 
                }
            }
        }
        if(!ketemu){ 
            cout << "Data Mahasiswa dengan NIM " << NIM_125 << " Tidak Ada" << endl;
        }
        cout << "=============================================\n";
    }

    // Fungsi untuk mencari data dalam tabel hash berdasarkan rentang nilai
    void SearchByGrade_125(int min_125, int max_125){
        bool ketemu = false; 
        cout << "Data Mahasiswa --->" << endl;
        cout << "=============================================\n";
        cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
        cout << "=============================================\n";
        for (int i=0; i < TableSize_125; i++){
            // Iterasi melalui vektor pada indeks hash yang sesuai
            for(auto node : table[i]){
                if(node->nilai_125 >= min_125 && node->nilai_125 <= max_125){ 
                    cout << "|" << left << setw(14) << node->nama_125 << "|" << left << setw(14) << node->NIM_125 << "|" << left << setw(13) << node->nilai_125 << "|" << endl;
                    ketemu = true;
                }
            }
        }
        if(!ketemu){ 
            cout << "Data Mahasiswa dengan Nilai " << min_125 << " - " << max_125 << " Tidak Ada" << endl;
        }
        cout << "=============================================\n";
    }

    // Fungsi untuk menampilkan semua data dalam tabel hash
    void TampilData_125(){
        for(int i=0; i < TableSize_125; i++){
            // Iterasi melalui vektor pada indeks hash yang sesuai
            for(auto node : table[i]){ 
            cout << "|" << left << setw(14) << node->nama_125 << "|" << left << setw(14) << node->NIM_125 << "|" << left << setw(13) << node->nilai_125 << "|" << endl;
            }
        }
        cout << "=============================================\n";
    }
};

// Fungsi utama
int main(){
    HashMap_125 StudentMap; // Membuat objek dari kelas HashMap_125 untuk menyimpan data mahasiswa
    int choose_125, grade_125, GradeMin_125, GradeMax_125; // Variabel untuk pilihan, nilai, dan rentang nilai
    string name_125, NIM_125; // Variabel untuk nama dan NIM mahasiswa
    MenuUtama:
    // Menampilkan menu utama
    cout << "=============================================\n";
    cout << "|--------> Naufal'S Data Mahasiswa <--------|\n";
    cout << "=============================================\n";
    cout << "| 1. Tambah Data                            |\n";
    cout << "| 2. Hapus Data                             |\n";
    cout << "| 3. Cari Data Mahasiswa Berdasarkan NIM    |\n";
    cout << "| 4. Cari Data Mahasiswa Berdasarkan Nilai  |\n";
    cout << "| 5. Tampilkan Data                         |\n";
    cout << "| 6. Keluar                                 |\n";
    cout << "=============================================\n";
    cout << "Masukkan Pilihan Anda = ";
    cin >> choose_125; // Meminta input pilihan
    cout << endl;

    switch(choose_125){ 
        case 1: 
            // Pilihan untuk menambah data
            cout << "Tambah Data --->\n";
            cout << "Masukkan Nama Mahasiswa : "; cin >> name_125;
            cout << "Masukkan NIM Mahasiswa : "; cin >> NIM_125;
            cout << "Masukkan Nilai Mahasiswa : "; cin >> grade_125;
            StudentMap.Tambah_125(name_125, NIM_125, grade_125); 
            cout << "Data Mahasiswa " << name_125 << " Berhasil ditambahkan" << endl;
            cout << endl;
            goto MenuUtama;
            break;
        case 2:
            // Pilihan untuk menghapus data
            cout << "Hapus Data --->\n";
            if(StudentMap.IsEmpty_125() == false){ 
                cout << "Masukkan Nama Mahasiswa yang Ingin dihapus : "; cin >> name_125;
                StudentMap.CekData_125(name_125);
                if(StudentMap.CekData_125(name_125) == true){ 
                        StudentMap.Hapus_125(name_125); 
                        cout << "Data Mahasiswa " << name_125 << " Berhasil dihapus" << endl;
                } else { 
                    cout << "Data mahasiswa " << name_125 << " Tidak Dapat ditemukan" << endl;
                }
            } else { 
                cout << "Tabel ini masih kosong!\n";
            }
            cout << endl;
            goto MenuUtama;
            break;
        case 3:
            // Pilihan untuk mencari data berdasarkan NIM
            cout << "Cari Data Mahasiswa Berdasarkan NIM --->\n";
            if(StudentMap.IsEmpty_125() == false){
                cout << "Masukkan NIM = "; cin >> NIM_125;
                cout << endl;
                StudentMap.SearchByNIM_125(NIM_125); 
            } else { 
                cout << "Tabel ini masih kosong!\n";
            }
            cout << endl;
            goto MenuUtama; 
            break;
        case 4: 
            // Pilihan untuk mencari data berdasarkan rentang nilai
            cout << "Cari Data Mahasiswa Berdasarkan Nilai --->\n";
            if(StudentMap.IsEmpty_125() == false){ 
                cout << "Masukkan Nilai Minimal : "; cin >> GradeMin_125;
                cout << "Masukkan Nilai Maksimal : "; cin >> GradeMax_125;
                cout << endl;
                StudentMap.SearchByGrade_125(GradeMin_125,GradeMax_125); 
            } else { 
                cout << "Tabel ini masih kosong!\n";
            }
            cout << endl;
            goto MenuUtama; 
            break;
        case 5: 
            // Pilihan untuk menampilkan semua data
            cout << "Tampil Data --->\n";
            if(StudentMap.IsEmpty_125() == false){
                cout << "=============================================\n";
                cout << "|" << left << setw(14) << "Nama" << "|" << left << setw(14) << "NIM" << "|" << left << setw(13) << "Nilai" << "|" << endl;
                cout << "=============================================\n";
                StudentMap.TampilData_125(); 
            } else { 
                cout << "Tabel Ini masih kosong!\n";
            }
            cout << endl;
            goto MenuUtama; 
            break;
        case 6: 
            // Pilihan untuk keluar dari program
            cout << "Terimakasih, Anda Telah Keluar dari Program Ini\n";
            return 0;
        default:
            // Pilihan yang tidak valid
            cout << "Pilihan Anda Tidak Sesuai\n";
            cout << endl;
            goto MenuUtama; 
            break;
    }
}
