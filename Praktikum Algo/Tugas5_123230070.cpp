#include <iostream>
using namespace std;

char ulang;
int a, b, c, d;

void hitungPerkalianMatriks(int a, int b, int c, int d) {
    cout << "Perkalian 2 matriks (M * N)\n";
    cout << endl;

    cout << "Matriks M dengan ukuran a * b" << endl;
    cout << "Input nilai a: ";
    cin >> a;

    cout << "Input nilai b: ";
    cin >> b;

    int m[a][b];

    cout << endl;

    cout << "Matriks N dengan ukuran c * d" << endl;
    cout << "Input nilai c: ";
    cin >> c;


    cout << "Input nilai d: ";
    cin >> d;

    int n[c][d];

    cout << endl;

    if(b == c) {
        cout << "Input Matriks M" << endl;
        for (int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                cout << "Angka [" << i << "] [" << j << "] : ";
                cin >> m[i][j];
            }
        }

        cout << endl;

        cout << "Input Matriks N" << endl;
        for (int i = 0; i < c; i++) {
            for(int j = 0; j < d; j++) {
                cout << "Angka [" << i << "] [" << j << "] : ";
                cin >> n[i][j];
            }
        }

        cout << endl;

        cout << "Hasil Matriks M" << endl;
        for (int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Hasil Matriks N" << endl;
        for (int i = 0; i < c; i++) {
            for(int j = 0; j < d; j++) {
                cout << n[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;

        cout << "Hasil Perkalian Matriks M dan N" << endl;
        for (int i = 0; i < a; i++) {
            for(int j = 0; j < d; j++) {
                int hasil = 0;
                for(int k = 0; k < b; k++) {
                    hasil += m[i][k] * n[k][j];
                }
                cout << hasil << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Perkalian matriks tidak mungkin dilakukan!" << endl;
    }

}

int main() {
    do {
        system("cls");
        cout << "=========================" << endl;
        cout << "TUGAS ARRAY" << endl;
        cout << "=========================" << endl;

        cout << endl;

        cout << "Perkalian Matriks" << endl;
        cout << endl;

        hitungPerkalianMatriks(a, b, c, d);

        cout << endl;

        cout << "Apakah anda ingin mengulang? (y/n) : ";
        cin >> ulang;
    } while(ulang == 'y' || ulang == 'Y');
    
    return 0;
}