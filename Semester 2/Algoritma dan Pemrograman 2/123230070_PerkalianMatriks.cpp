#include <iostream>
using namespace std;

int a, b, c, d;
void perkalianMatriks();

int main() { 
  perkalianMatriks(); 
}

void perkalianMatriks() {

  cout << "Perkalian 2 matriks\n";
  cout << endl;

  cout << "Matriks M dengan ordo a * b" << endl;
  cout << "Input nilai a (baris) matriks pertama : ";
  cin >> a;

  cout << "Input nilai b (kolom) matriks pertama : ";
  cin >> b;

  int m[a][b];

  cout << endl;

  cout << "Matriks N dengan ordo c * d" << endl;
  cout << "Input nilai c (baris) matriks kedua : ";
  cin >> c;

  cout << "Input nilai d (kolom) matriks kedua : ";
  cin >> d;

  int n[a][b];

  cout << endl;
  if (b == c) {
    cout << "Input nilai Matriks pertama" << endl;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        cout << "Angka "
             << "[" << i << "] "
             << "[" << j << "] : ";
        cin >> m[i][j];
      }
    }

    cout << endl;

    cout << "Input nilai Matriks kedua" << endl;
    for (int i = 0; i < c; i++) {
      for (int j = 0; j < d; j++) {
        cout << "Angka "
             << "[" << i << "] "
             << "[" << j << "] : ";
        cin >> n[i][j];
      }
    }

    //[1 2]  [4 3]
    //[3 4]  [2 1]

    cout << endl;

    cout << "Hasil Perkalian Matriks M dan N" << endl;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < d; j++) {
        int hasil = 0;
        for (int k = 0; k < b; k++) {
          hasil += m[i][k] * n[k][j];
        }
        cout << hasil << " ";
      }
      cout << endl;
    }
  } else {
    cout << "Perkalian matriks tidak mungkin dilakukan";
  }
}
