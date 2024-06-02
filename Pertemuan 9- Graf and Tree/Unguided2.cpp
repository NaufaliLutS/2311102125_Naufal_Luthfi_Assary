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
        cout << "-----------------------------------\n";
        cout << "|---> Naufal'S Graph And Tree <---|\n";
        cout << "-----------------------------------\n";
        cout << "Menu:\n";
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
