// Nama : M. Arfa Raditya
// NIM   : 124140015
// Kelas : RD
// Soal nomor 3

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan ukuran array: ";
    cin >> n;

    int *arr = new int[n];  // alokasi dinamis untuk array

    // menginput elemen array menggunakan pointer
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen array ke-" << i + 1 << ": ";
        cin >> *(arr + i);
    }

    // menampilkan array sebelum dibalik
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // proses membalik elemen array
    for (int i = 0; i < n/2; i++) {
        int temp = *(arr + i);
        *(arr + i) = *(arr + (n - 1 - i));
        *(arr + (n - 1 - i)) = temp;
    }

    // menampilkan array sesudah dibalik
    cout << "Array sesudah dibalik: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    delete[] arr; // dealokasi memori
    return 0;
}