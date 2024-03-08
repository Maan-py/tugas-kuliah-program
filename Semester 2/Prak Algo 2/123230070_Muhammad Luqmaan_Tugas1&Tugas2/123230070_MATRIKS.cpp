#include <iostream>
using namespace std;

int main() {
  int barisA, kolomA, barisB, kolomB; // inisialisasi variabel baris dan kolom masing-masing matriks

  cout << "Masukkan jumlah baris matriks A : "; // input baris matriks A
  cin >> barisA;

  cout << "Masukkan jumlah kolom matriks A : "; // input kolom matriks A
  cin >> kolomA;

  int matriksA[barisA][kolomA];

  cout << endl;

  cout << "Masukkan jumlah baris matriks B : "; // input baris matriks B
  cin >> barisB;

  cout << "Masukkan jumlah kolom matriks B : "; // input kolom matriks B
  cin >> kolomB;

  int matriksB[barisB][kolomB];

  cout << endl;

  if(barisA == kolomB) { // error handling perkalian matriks hanya bisa dilakukan jika kolom matriks A sama dengan baris matriks B
    cout << "Masukkan angka untuk matriks A : " << endl; // input angka matriks A
    for(int i = 0; i < barisA; i++) { // perulangan untuk baris matriks A
      for(int j = 0; j < kolomA; j++) { // perulangan untuk kolom matriks A
        cout << "Angka " << "[" << i<< "]" << "[" << j<< "] : ";
        cin >> matriksA[i][j]; 
      }
    }

    cout << "\nMasukkan angka untuk matriks B : " << endl; // input angka matriks B
    for(int i = 0; i < barisB; i++) {
      for(int j = 0; j < kolomB; j++) {
        cout << "Angka " << "[" << i<< "]" << "[" << j<< "] : ";
        cin >> matriksB[i][j];
      }
    }

    cout << "\nAngka Matriks A : " << endl; 

    for(int i = 0; i < barisA; i++) {
      for(int j = 0; j < kolomA; j++) {
        cout << matriksA[i][j] << " "; // menampilkan kembali angka matriks A yang sudah diinputkan
      } 
      cout << endl;
    }

    cout << "\nAngka Matriks B : " << endl;

    for(int i = 0; i < barisB; i++) {
      for(int j = 0; j < kolomB; j++) {
        cout << matriksB[i][j] << " "; // menampilkan kembali angka matriks B yang sudah diinputkan
      }
      cout << endl;
    }

    cout << "\nHasil perkalian dari kedua matriks tersebut adalah : " << endl; 
    for(int i = 0; i < barisA; i++) {
      for(int j = 0; j < kolomB; j++) {
        int hasil = 0;
        for(int k = 0; k < barisB; k++) { 
          hasil += matriksA[i][k] * matriksB[k][j]; 
        }
        cout << hasil << " "; // menampilkan hasil perkalian matriks
      } 
      cout << endl;
    }
  } else {
    cout << "Perkalian matriks tidak mungkin dilakukan."; // error handling jika kolom matriks A tidak sama dengan baris matriks B
  }
}