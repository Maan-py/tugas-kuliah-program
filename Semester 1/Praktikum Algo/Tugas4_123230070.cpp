#include <iostream>
using namespace std;

int pilih, angka1, angka2, jumlah;
char ulang;
int reverse(int angka);
void faktorBilangan(int angka);

int main() {
    do {
        system("cls");
        puts("--------------------------------------------------------------------------------");
        puts("              MENU UTAMA TUGAS PERULANGAN & FUNCTION                            ");
        puts("--------------------------------------------------------------------------------");
        cout << endl;

        cout << "1. Kasus Penjumlahan angka terbalik yang dibalik" << endl;
        cout << "2. Kasus Faktor Bilangan" << endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "Masukkan angka pertama : ";
            cin >> angka1;

            cout << "Masukkan angka kedua : ";
            cin >> angka2;

            cout << endl;

            cout << "Hasil reverse angka pertama : " << reverse(angka1) << endl;
            cout << "Hasil reverse angka kedua : " << reverse(angka2) << endl;

            cout << "Hasil penjumlahan reverse angka pertama dijumlah reverse angka kedua: " << reverse(angka1) + reverse(angka2) << endl;
            cout << "\nHasil akhir dari operasi ini adalah " << reverse(reverse(angka1) + reverse(angka2)) << endl;
            break;

        case 2:
            cout << "Masukkan angka : ";
            cin >> angka1;

            cout << endl;

            cout << "Faktor dari " << angka1 << " adalah : " << endl;
            faktorBilangan(angka1);
            break;

        default:
            cout << "Inputan Salah, Silakan Coba Lagi!" << endl;
            goto cobaLagi;
            break;
        }

    cobaLagi:
        cout << "\nUlangi program? (y/n) : ";
        cin >> ulang;
    } while (ulang == 'y' or ulang == 'Y');
}

int reverse(int angka) {
    int reverse = 0;
    while (angka != 0) {
        int digit = angka % 10;
        reverse = reverse * 10 + digit;
        angka /= 10;
    }
    return reverse;
}

void faktorBilangan(int angka) {
    for (int i = angka; i >= 1; i--) {
        if (angka % i == 0) {
            cout << i << " ";
        }
    }
}
