// Nama  : M. Arfa Raditya
// NIM   : 124140015
// Kelas : RD
// Soal nomor 1

#include <iostream>
using namespace std;

void hitungGanjil(int *x, int y){
    *x = 0;
    for(int i = 1; i <= y; i++){ // me-looping sebanyak n kali
        if(i % 2 == 1){ // mencari bilangan ganjil
            *x = *x + i; // bilangan akan diproses dan disimpan ke *x
        }
    }
}

int main()
{
    int bil1, bil2;
    
    cout << "Masukkan nilai batas atas : ";
    cin >> bil2;
    
    // memanggil sub program
    hitungGanjil(&bil1,bil2);
    cout << "Hasil hitung bilangan ganjil dari 1 - " << bil2 << " adalah : " << bil1;

    return 0;
}