#include <iostream>
using namespace std;

int main() {
  int barisA, kolomA, barisB, kolomB;

  cout << "Masukkan jumlah baris matriks A : ";
  cin >> barisA;

  cout << "Masukkan jumlah kolom matriks A : ";
  cin >> kolomA;

  int matriksA[barisA][kolomA];

  cout << endl;

  cout << "Masukkan jumlah baris matriks B : ";
  cin >> barisB;

  cout << "Masukkan jumlah kolom matriks B : ";
  cin >> kolomB;

  int matriksB[barisB][kolomB];

  cout << endl;

  if(barisA == kolomB) {
    cout << "Masukkan angka untuk matriks A : " << endl;
    for(int i = 0; i < barisA; i++) {
      for(int j = 0; j < kolomA; j++) {
        cout << "Angka " << "[" << i<< "]" << "[" << j<< "] : ";
        cin >> matriksA[i][j];
      }
    }

    cout << "\nMasukkan angka untuk matriks B : " << endl;
    for(int i = 0; i < barisB; i++) {
      for(int j = 0; j < kolomB; j++) {
        cout << "Angka " << "[" << i<< "]" << "[" << j<< "] : ";
        cin >> matriksB[i][j];
      }
    }

    cout << "\nAngka Matriks A : " << endl;

    for(int i = 0; i < barisA; i++) {
      for(int j = 0; j < kolomA; j++) {
        cout << matriksA[i][j] << " ";
      } 
      cout << endl;
    }

    cout << "\nAngka Matriks B : " << endl;

    for(int i = 0; i < barisB; i++) {
      for(int j = 0; j < kolomB; j++) {
        cout << matriksB[i][j] << " ";
      } 
      cout << endl;
    }

    //[1 2 3] [6 5]
    //[4 5 6] [4 3]
    //        [2 1]

    cout << "\nHasil perkalian dari kedua matriks tersebut adalah : " << endl;
    for(int i = 0; i < barisA; i++) {
      for(int j = 0; j < kolomB; j++) {
        int hasil = 0;
        for(int k = 0; k < barisB; k++) { // 3
          hasil += matriksA[i][k] * matriksB[k][j]; // 1 * 6 2 * 4 3 * 2
        }
        cout << hasil << " ";
      } 
      cout << endl;
    }
  } else {
    cout << "Perkalian matriks tidak mungkin dilakukan.";
  }
}