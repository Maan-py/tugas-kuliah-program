#include <iostream>
using namespace std;

int main() {
  int matriks1[2][2]; // {{2, 3},
                      //   {}}
  int matriks2[2][2];

  // cout << "Masukkan nilai untuk matriks 1 : " << endl;

  // for(int i = 0; i < 2; i++) {
  //   for(int j = 0; j < 2; j++) {
  //     cout << "Nilai untuk "
  //          << "[" << i << "]"
  //          << "[" << j << "] : ";
  //     cin >> matriks1[i][j];
  //   }
  //   cout << endl;
  // }

  // for(int i = 0; i < 2; i++) {
  //   for(int j = 0; j < 2; j++) {
  //     cout << "Nilai untuk "
  //          << "[" << i << "]"
  //          << "[" << j << "] : ";
  //     cin >> matriks2[i][j];
  //   }
  //   cout << endl;
  // }

  // for(int i = 0; i < 2; i++) {
  //   for(int j = 0; j <  2; j++) {
  //     cout << matriks1[i][j] + matriks2[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << "Masukkan nilai untuk matriks 1 : " << endl;

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      cout << "Nilai untuk "
           << "[" << i << "]"
           << "[" << j << "] : ";
      cin >> matriks1[i][j];
    }
    cout << endl;
  }

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      cout << "Nilai untuk "
           << "[" << i << "]"
           << "[" << j << "] : ";
      cin >> matriks2[i][j];
    }
    cout << endl;
  }

  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
      int hasil = 0;
        for (int k = 0; k < j; k++) {
          hasil += matriks1[i][k] * matriks2[k][j];
        }
        cout << hasil << " ";
    }
  }
}