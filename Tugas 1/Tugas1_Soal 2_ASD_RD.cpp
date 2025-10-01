// Nama : M. Arfa Raditya
// NIM   : 124140015
// Kelas : RD
// Soal nomor 2

#include <iostream>
using namespace std;

// mendeklarasikan subprogram
void opMat(int *x, int y, float *z){
    *x = 0;
    *z = 1;
    for(int i = 1; i <= y; i++){
        *x += i * i; // penjumlahan bilangan kuadrat sampai ke-n
        *z *= (2*i - 1); // perkalian bilangan ganjil
    }
}

int main()
{
    int bil1, bil2;
    float bil3;
    
    cout << "Masukkan batas atas : ";
    cin >> bil2;
    
    opMat(&bil1, bil2, &bil3);
    cout << "Hasil penjumlahan bilangan kuadrat dari 1 sampai "<< bil2 << " adalah : " << bil1 << endl;
    cout << "Hasil perkalian bilangan ganjil sebanyak "<< bil2 << " bilangan (mulai dari 1) adalah : " << bil3;

    return 0;
}