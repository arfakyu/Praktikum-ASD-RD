// Nama : M. Arfa Raditya
// NIM : 124140015
// Kelas : ASD RD
// Soal nomor 2

#include <iostream>
using namespace std;

typedef int infotype;

// struktur node
typedef struct TElmtList *address;
typedef struct TElmtList {
    infotype info;
    address next;
} ElmtList;

// struktur list
typedef struct TList {
    address first;
} List;

// mengecek apakah list kosong
bool IsEmpty(List L) {
    return (L.first == nullptr);
}

// alokasi memori untuk node baru
address Allocation(infotype x) {
    address P = new ElmtList;
    P->info = x;
    P->next = nullptr;
    return P;
}

// dealokasi node
void Deallocate(address P) {
    delete P;
}

// menyisipkan node di awal list
void InsertFirst(List *L, infotype x) {
    address P = Allocation(x);
    P->next = L->first;
    L->first = P;
}

// menyisipkan node setelah node tertentu
void InsertAfter(address Prec, infotype x) {
    if (Prec != nullptr) {
        address P = Allocation(x);
        P->next = Prec->next;
        Prec->next = P;
    }
}

// menyisipkan node secara terurut menaik
void InsertSorted(List *L, infotype x) {
    // jika list kosong atau x lebih kecil dari elemen pertama
    if (IsEmpty(*L) || L->first->info > x) {
        InsertFirst(L, x);
    } else {
        // cari posisi yang tepat untuk sisipkan x
        address temp = L->first;
        while (temp->next != nullptr && temp->next->info < x) {
            temp = temp->next;
        }
        InsertAfter(temp, x);
    }
}

// menampilkan seluruh elemen list
void ShowData(List L) {
    address temp = L.first;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

// menghapus seluruh elemen dalam list
void DeallocateAll(List *L) {
    address temp = L->first;
    while (temp != nullptr) {
        address nextNode = temp->next;
        Deallocate(temp);
        temp = nextNode;
    }
    L->first = nullptr;
}

int main() {
    List siswa;
    siswa.first = nullptr;

    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        infotype x;
        cout << "Data ke-" << i + 1 << ": ";
        cin >> x;
        InsertSorted(&siswa, x);  // menyisipkan secara terurut
        cout << "List sementara: ";
        ShowData(siswa);
    }

    cout << "List akhir (terurut ascending): ";
    ShowData(siswa);

    DeallocateAll(&siswa);  // menghapus semua elemen sebelum program selesai
    return 0;
}
