// Nama : M. Arfa Raditya
// NIM : 124140015
// Kelas : ASD RD
// Soal nomor 1

#include <iostream>
using namespace std;

typedef int infotype;

typedef struct TElmtList *address;

typedef struct TElmtList {
    string nama;       // nama siswa
    infotype info;     // nilai siswa
    address next;      // pointer ke node berikutnya
} ElmtList;

typedef struct TList {
    address first;
} List;

// Fungsi Dasar Linked List

// inisialisasi list kosong
void CreateEmpty(List* L) {
    (*L).first = NULL;
}

// mengecek apakah list kosong
bool IsEmpty(List L) {
    return (L.first == NULL);
}

// alokasi node baru
address Allocation(string nama, infotype nilai) {
    address newNode = new TElmtList;
    newNode->nama = nama;
    newNode->info = nilai;
    newNode->next = NULL;
    return newNode;
}

// insert di awal list
void InsertFirst(List* L, string nama, infotype nilai) {
    address newNode = Allocation(nama, nilai);
    newNode->next = (*L).first;
    (*L).first = newNode;
}

// insert di akhir list
void InsertLast(List* L, string nama, infotype nilai) {
    if (IsEmpty(*L)) {
        InsertFirst(L, nama, nilai);
    } else {
        address temp = (*L).first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = Allocation(nama, nilai);
    }
}

// menampilkan semua data siswa
void ShowData(List L) {
    if (IsEmpty(L)) {
        cout << "List kosong." << endl;
    } else {
        address temp = L.first;
        cout << "Data Siswa:\n";
        while (temp != NULL) {
            cout << "- Nama : " << temp->nama << ", Nilai : " << temp->info << endl;
            temp = temp->next;
        }
    }
}

// dealokasi semua node

void DeallocateAll(List* L) {
    address temp;
    while ((*L).first != NULL) {
        temp = (*L).first;
        (*L).first = (*L).first->next;
        delete temp;
    }
}

// Program Utama

int main() {
    List siswa;
    CreateEmpty(&siswa);

    int pilihan;
    string nama;
    infotype nilai;

    do {
        cout << "\n=== Menu Sistem Nilai Siswa ===\n";
        cout << "1. Tambah Data Siswa\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama siswa: ";
                cin.ignore(); // membersihkan newline
                getline(cin, nama); // agar input nama bisa ada spasi nya
                cout << "Masukkan nilai siswa: ";
                cin >> nilai;
                InsertLast(&siswa, nama, nilai);
                break;

            case 2:
                ShowData(siswa);
                break;

            case 0:
                cout << "Terima kasih!\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);

    // dealokasi semua node sebelum keluar
    DeallocateAll(&siswa);

    return 0;
}
